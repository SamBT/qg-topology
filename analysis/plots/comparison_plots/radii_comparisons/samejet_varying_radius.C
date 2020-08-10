void samejet_varying_radius(TString type, TString var, TString sample, TString xlabel, int rebin) {
  TFile *f1 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_rewt.root");
  TFile *f2 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_05/output_dijets_rewt.root");
  TFile *f3 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_06/output_dijets_rewt.root");
  TFile *f4 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_07/output_dijets_rewt.root");
  TFile *f5 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_08/output_dijets_rewt.root");
  TFile *f6 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_09/output_dijets_rewt.root");
  TFile *f7 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_1/output_dijets_rewt.root");

  if (sample == "zplusjets") {
    f1 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets.root");
    f2 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_05/output_zplusjets.root");
    f3 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_06/output_zplusjets.root");
    f4 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_07/output_zplusjets.root");
    f5 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_08/output_zplusjets.root");
    f6 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_09/output_zplusjets.root");
    f7 = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_1/output_zplusjets.root");
  }

  TH1F *h1 = (TH1F*)f1->Get("h_"+type+"_"+var);
  TH1F *h2 = (TH1F*)f2->Get("h_"+type+"_"+var);
  TH1F *h3 = (TH1F*)f3->Get("h_"+type+"_"+var);
  TH1F *h4 = (TH1F*)f4->Get("h_"+type+"_"+var);
  TH1F *h5 = (TH1F*)f5->Get("h_"+type+"_"+var);
  TH1F *h6 = (TH1F*)f6->Get("h_"+type+"_"+var);
  TH1F *h7 = (TH1F*)f7->Get("h_"+type+"_"+var);
  
  h1->Rebin(rebin);
  h2->Rebin(rebin);
  h3->Rebin(rebin);
  h4->Rebin(rebin);
  h5->Rebin(rebin);
  h6->Rebin(rebin);
  h7->Rebin(rebin);

  h1->SetLineColor(1);
  h2->SetLineColor(2);
  h3->SetLineColor(3);
  h4->SetLineColor(4);
  h5->SetLineColor(6);
  h6->SetLineColor(7);
  h7->SetLineColor(8);
  
  //Normalizing to unity
  h1->Scale(1/h1->Integral());
  h2->Scale(1/h2->Integral());
  h3->Scale(1/h3->Integral());
  h4->Scale(1/h4->Integral());
  h5->Scale(1/h5->Integral());
  h6->Scale(1/h6->Integral());
  h7->Scale(1/h7->Integral());

  double max = h1->GetMaximum();

  TCanvas *c = new TCanvas();
  h1->GetYaxis()->SetRangeUser(0,1.5*max);
  h1->GetXaxis()->SetTitle(xlabel);
  h1->GetYaxis()->SetTitle("a.u.");
  h1->Draw("hist");
  h2->Draw("histsame");
  h3->Draw("histsame");
  h4->Draw("histsame");
  h5->Draw("histsame");
  h6->Draw("histsame");
  h7->Draw("histsame");
  TLegend leg(0.2,0.6,0.3,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.03);
  leg.SetShadowColor(0);
  leg.AddEntry(h1,"R = 0.4","l");
  leg.AddEntry(h2,"R = 0.5","l");
  leg.AddEntry(h3,"R = 0.6","l");
  leg.AddEntry(h4,"R = 0.7","l");
  leg.AddEntry(h5,"R = 0.8","l");
  leg.AddEntry(h6,"R = 0.9","l");
  leg.AddEntry(h7,"R = 1.0","l");
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  if (type == "qjet") l.DrawLatex(0.45,0.85,"Quark Jets, p_{T}^{jet} > 20 GeV, |#eta| < 2.5");
  if (type == "gjet") l.DrawLatex(0.45,0.85,"Gluon Jets, p_{T}^{jet} > 20 GeV, |#eta| < 2.5");
  if (sample == "dijets") l.DrawLatex(0.45,0.8,"Dijets (Reweighted)");
  if (sample == "zplusjets") l.DrawLatex(0.45,0.8,"Z+jets");
  TString outname = "compare_"+type+"_"+var+"_"+sample+"_varied_radius";
  c->SaveAs(outname+".png");
  c->SaveAs(outname+".pdf");
  c->SaveAs(outname+".C");

}
