void samejet_two_samples(TString type, TString var, TString xlabel, TString sample1, TString sample2, int njets1, int njets2, int rebin, int logscale) {
  TString fname1, fname2;
  if (sample1 == "dijets") fname1.Form("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_rewt_%ijets.root",njets1);
  if (sample1 == "zplusjets") fname1.Form("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets_%ijets.root",njets1);
  if (sample2 == "dijets") fname2.Form("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_rewt_%ijets.root",njets2);
  if (sample2 == "zplusjets") fname2.Form("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets_%ijets.root",njets2);

  TString message1, message2;
  if (sample1 == "dijets") message1.Form("Dijets, %i jets", njets1);
  if (sample1 == "zplusjets") message1.Form("Z+%i jets",njets1);
  if (sample2 == "dijets") message2.Form("Dijets, %i jets",njets2);
  if (sample2 == "zplusjets") message2.Form("Z+%i jets",njets2);

  TFile *f1 = TFile::Open(fname1);
  TFile *f2 = TFile::Open(fname2);

  TH1F *h1 = (TH1F*)f1->Get("h_"+type+"_"+var);
  TH1F *h2 = (TH1F*)f2->Get("h_"+type+"_"+var);
  
  h1->Rebin(rebin);
  h2->Rebin(rebin);
  h2->SetLineColor(2);
  
  //Normalizing to unity
  h1->Scale(1/h1->Integral());
  h2->Scale(1/h2->Integral());

  TH1F *sum = (TH1F*)h1->Clone();
  sum->Add(h2);
  
  TH1F *diff = (TH1F*)h1->Clone();
  diff->Add(h2,-1);

  //Squaring the difference of the two hists
  for (int i = 1; i <= diff->GetNbinsX(); i++) {
    diff->SetBinContent(i,diff->GetBinContent(i)*diff->GetBinContent(i));
  }

  diff->Divide(sum);
  double separation_power = 0.5*diff->Integral();

  TString sep; sep.Form("Separation Power = %.3f",separation_power);

  double max = h1->GetMaximum();
  if (h2->GetMaximum() > max) max = h2->GetMaximum();

  TCanvas *c = new TCanvas();
  if (logscale) {
    c->SetLogy();
    h2->GetXaxis()->SetRangeUser(h2->GetXaxis()->GetBinLowEdge(h2->FindFirstBinAbove(0)),h2->GetXaxis()->GetBinLowEdge(h2->FindLastBinAbove(0)+1)*1.5);
    h2->GetYaxis()->SetRangeUser(h2->GetBinContent(h2->FindLastBinAbove(0)),10*h2->GetMaximum());
  }
  else {
    h2->GetYaxis()->SetRangeUser(0,1.5*max);
  }
  h2->GetXaxis()->SetTitle(xlabel);
  h2->GetYaxis()->SetTitle("a.u.");
  h2->Draw("hist");
  h1->Draw("histsame");
  TLegend leg(0.2,0.8,0.4,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.04);
  leg.SetShadowColor(0);
  leg.AddEntry(h1,message1,"l");
  leg.AddEntry(h2,message2,"l");
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  if (type == "qjet") l.DrawLatex(0.45,0.85,"Quark Jets, p_{T}^{jet} > 20 GeV");
  if (type == "gjet") l.DrawLatex(0.45,0.85,"Gluon Jets, p_{T}^{jet} > 20 GeV");
  l.DrawLatex(0.45,0.8,sep);
  TString s1, s2, s; s1.Form("_%ijets_",njets1); s2.Form("_%ijets",njets2);
  s = sample1+s1+sample2+s2;
  TString outname = "compare_"+type+"_"+var+"_"+s;
  c->SaveAs(outname+".png");
  c->SaveAs(outname+".pdf");
}
