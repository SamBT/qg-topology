void quark_vs_gluon_samesample(TString type, TString var, TString xlabel, int rebin, int logscale, int njets) {
  TString filename;
  if (type == "dijets") filename.Form("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_rewt_%ijets.root",njets);
  if (type == "zplusjets") filename.Form("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets_%ijets.root",njets-1);
  
  TFile *f1 = TFile::Open(filename);

  TH1F *hq = (TH1F*)f1->Get("h_qjet_"+var);
  TH1F *hg = (TH1F*)f1->Get("h_gjet_"+var);
  
  hq->Rebin(rebin);
  hg->Rebin(rebin);
  hg->SetLineColor(2);
  
  //Normalizing to unity
  hq->Scale(1/hq->Integral());
  hg->Scale(1/hg->Integral());

  TH1F *sum = (TH1F*)hq->Clone();
  sum->Add(hg);
  
  TH1F *diff = (TH1F*)hq->Clone();
  diff->Add(hg,-1);

  //Squaring the difference of the two hists
  for (int i = 1; i <= diff->GetNbinsX(); i++) {
    diff->SetBinContent(i,diff->GetBinContent(i)*diff->GetBinContent(i));
  }

  diff->Divide(sum);
  double separation_power = 0.5*diff->Integral();

  TString sep; sep.Form("Separation Power = %.3f",separation_power);

  double max = hq->GetMaximum();
  if (hg->GetMaximum() > max) max = hg->GetMaximum();

  TCanvas *c = new TCanvas();
  if (logscale) {
    c->SetLogy();
    hg->GetXaxis()->SetRangeUser(hg->GetXaxis()->GetBinLowEdge(hg->FindFirstBinAbove(0)),hg->GetXaxis()->GetBinLowEdge(hg->FindLastBinAbove(0)+1)*1.5);
    hg->GetYaxis()->SetRangeUser(hg->GetBinContent(hg->FindLastBinAbove(0)),10*hg->GetMaximum());
  }
  else {
    hg->GetYaxis()->SetRangeUser(0,1.5*max);
  }
  hg->GetXaxis()->SetTitle(xlabel);
  hg->GetYaxis()->SetTitle("a.u.");
  hg->Draw("hist");
  hq->Draw("histsame");
  TLegend leg(0.2,0.8,0.4,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.04);
  leg.SetShadowColor(0);
  leg.AddEntry(hq,"Quark Jets","l");
  leg.AddEntry(hg,"Gluon Jets","l");
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  TString jets; jets.Form("N_{jets} = %i",njets);
  TString dijets_label; dijets_label.Form("Dijets, N_{jets} = %i, p_{T}^{jet} > 20 GeV",njets);
  TString zplusjets_label; zplusjets_label.Form("Z+%i jets, p_{T}^{jet} > 20 GeV",njets-1);
  if (type == "dijets") l.DrawLatex(0.45,0.85,dijets_label);
  if (type == "zplusjets") l.DrawLatex(0.45,0.85,zplusjets_label);
  l.DrawLatex(0.45,0.8,sep);
  l.DrawLatex(0.45,0.9,jets);
  TString s; s.Form("%ijets",njets);
  TString outname = "qjet_vs_gjet_"+var+"_"+type+"_"+s;
  c->SaveAs(outname+".png");
  c->SaveAs(outname+".pdf");
  c->SaveAs(outname+".C");

}
