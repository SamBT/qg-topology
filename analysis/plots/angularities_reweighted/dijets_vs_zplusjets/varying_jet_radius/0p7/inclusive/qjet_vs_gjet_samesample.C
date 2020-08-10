void qjet_vs_gjet_samesample(TString type, TString var, TString xlabel, int rebin, int logscale) {
  TString filename;
  if (type == "dijets") filename = "/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_07/output_dijets_rewt.root";
  if (type == "zplusjets") filename = "/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_07/output_zplusjets.root";
  
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
  if (type == "dijets") l.DrawLatex(0.45,0.85,"Dijets, p_{T}^{jet} > 20 GeV");
  if (type == "zplusjets") l.DrawLatex(0.45,0.85,"Z+jets, p_{T}^{jet} > 20 GeV");
  l.DrawLatex(0.45,0.8,sep);
  l.DrawLatex(0.45,0.75,"R = 0.7");
  TString outname = "qjet_gjet_"+var+"_"+type;
  c->SaveAs(outname+".png");
  c->SaveAs(outname+".pdf");
  c->SaveAs(outname+".C");

}
