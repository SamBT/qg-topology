void samejet_diffsample(TString type, TString var, TString xlabel, int rebin, int logscale) {
  TFile *f1 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_07/output_dijets_rewt.root");
  TFile *f2 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_07/output_zplusjets.root");

  TH1F *hd = (TH1F*)f1->Get("h_"+type+"_"+var);
  TH1F *hz = (TH1F*)f2->Get("h_"+type+"_"+var);
  
  hd->Rebin(rebin);
  hz->Rebin(rebin);
  hz->SetLineColor(2);
  
  //Normalizing to unity
  hd->Scale(1/hd->Integral());
  hz->Scale(1/hz->Integral());

  TH1F *sum = (TH1F*)hd->Clone();
  sum->Add(hz);
  
  TH1F *diff = (TH1F*)hd->Clone();
  diff->Add(hz,-1);

  //Squaring the difference of the two hists
  for (int i = 1; i <= diff->GetNbinsX(); i++) {
    diff->SetBinContent(i,diff->GetBinContent(i)*diff->GetBinContent(i));
  }

  diff->Divide(sum);
  double separation_power = 0.5*diff->Integral();

  TString sep; sep.Form("Separation Power = %.3f",separation_power);

  double max = hd->GetMaximum();
  if (hz->GetMaximum() > max) max = hz->GetMaximum();

  TCanvas *c = new TCanvas();
  if (logscale) {
    c->SetLogy();
    hz->GetXaxis()->SetRangeUser(hz->GetXaxis()->GetBinLowEdge(hz->FindFirstBinAbove(0)),hz->GetXaxis()->GetBinLowEdge(hz->FindLastBinAbove(0)+1)*1.5);
    hz->GetYaxis()->SetRangeUser(hz->GetBinContent(hz->FindLastBinAbove(0)),10*hz->GetMaximum());
  }
  else {
    hz->GetYaxis()->SetRangeUser(0,1.5*max);
  }
  hz->GetXaxis()->SetTitle(xlabel);
  hz->GetYaxis()->SetTitle("a.u.");
  hz->Draw("hist");
  hd->Draw("histsame");
  TLegend leg(0.2,0.8,0.4,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.04);
  leg.SetShadowColor(0);
  leg.AddEntry(hd,"Dijets","l");
  leg.AddEntry(hz,"Z + jets","l");
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  if (type == "qjet") l.DrawLatex(0.45,0.85,"Quark Jets, p_{T}^{jet} > 20 GeV");
  if (type == "gjet") l.DrawLatex(0.45,0.85,"Gluon Jets, p_{T}^{jet} > 20 GeV");
  l.DrawLatex(0.45,0.8,"Dijets Re-Weighted to Z+jets in p_{T} and #eta");
  l.DrawLatex(0.45,0.75,sep);
  l.DrawLatex(0.45,0.7,"R = 0.7");
  TString outname = "compare_"+type+"_"+var;
  c->SaveAs(outname+".png");
  c->SaveAs(outname+".pdf");
  c->SaveAs(outname+".C");

}
