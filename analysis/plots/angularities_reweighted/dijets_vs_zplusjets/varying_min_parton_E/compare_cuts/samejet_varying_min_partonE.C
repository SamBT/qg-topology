void samejet_varying_min_partonE(TString type, TString var, TString sample, TString xlabel, int rebin) {
  TFile *f1 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_rewt.root");
  TFile *f2 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_min_partonE_5_rewt.root");
  TFile *f3 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_min_partonE_10_rewt.root");
  TFile *f4 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_min_partonE_15_rewt.root");
  TFile *f5 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_min_partonE_20_rewt.root");
  if (sample == "zplusjets") {
    f1 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets.root");
    f2 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets_min_partonE_5.root");
    f3 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets_min_partonE_10.root");
    f4 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets_min_partonE_15.root");
    f5 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets_min_partonE_20.root");
  }

  TH1F *h1 = (TH1F*)f1->Get("h_"+type+"_"+var);
  TH1F *h2 = (TH1F*)f2->Get("h_"+type+"_"+var);
  TH1F *h3 = (TH1F*)f3->Get("h_"+type+"_"+var);
  TH1F *h4 = (TH1F*)f4->Get("h_"+type+"_"+var);
  TH1F *h5 = (TH1F*)f5->Get("h_"+type+"_"+var);
  
  h1->Rebin(rebin);
  h2->Rebin(rebin);
  h3->Rebin(rebin);
  h4->Rebin(rebin);
  h5->Rebin(rebin);

  h1->SetLineColor(1);
  h2->SetLineColor(2);
  h3->SetLineColor(3);
  h4->SetLineColor(4);
  h5->SetLineColor(6);
  
  //Normalizing to unity
  h1->Scale(1/h1->Integral());
  h2->Scale(1/h2->Integral());
  h3->Scale(1/h3->Integral());
  h4->Scale(1/h4->Integral());
  h5->Scale(1/h5->Integral());

  double max = h1->GetMaximum();

  TCanvas *c = new TCanvas();
  h1->GetYaxis()->SetRangeUser(0,1.5*max);
  h1->GetXaxis()->SetTitle(xlabel);
  h1->GetYaxis()->SetTitle("a.u.");
  h1->GetYaxis()->SetRangeUser(0,1.5*h1->GetMaximum());
  h1->Draw("hist");
  h2->Draw("histsame");
  h3->Draw("histsame");
  h4->Draw("histsame");
  h5->Draw("histsame");
  TLegend leg(0.2,0.6,0.3,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.03);
  leg.SetShadowColor(0);
  leg.AddEntry(h1,"E_{parton} > 0 GeV","l");
  leg.AddEntry(h2,"E_{parton} > 5 GeV","l");
  leg.AddEntry(h3,"E_{parton} > 10 GeV","l");
  leg.AddEntry(h4,"E_{parton} > 15 GeV","l");
  leg.AddEntry(h5,"E_{parton} > 20 GeV","l");
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  if (type == "qjet") l.DrawLatex(0.45,0.85,"Quark Jets, p_{T}^{jet} > 20 GeV, |#eta| < 2.5");
  if (type == "gjet") l.DrawLatex(0.45,0.85,"Gluon Jets, p_{T}^{jet} > 20 GeV, |#eta| < 2.5");
  if (sample == "dijets") l.DrawLatex(0.45,0.8,"Dijets (Reweighted)");
  if (sample == "zplusjets") l.DrawLatex(0.45,0.8,"Z+jets");
  TString outname = "compare_"+type+"_"+var+"_"+sample+"_varied_parton_Ecut";
  c->SaveAs(outname+".png");
  c->SaveAs(outname+".pdf");
  c->SaveAs(outname+".C");

}
