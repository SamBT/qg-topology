#include "info.hh"
void general_comparison(TString sample1, TString sample2, TString type1, TString type2, TString var, int isleading, TString radius, int rebin) {
  TString xlabel = ang_labels[var];
  TString file1 = "/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output_highpt/Radius_"+radius+"/output_"+sample1+".root";
  TString file2 = "/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output_highpt/Radius_"+radius+"/output_"+sample2+".root";

  TFile *f1 = TFile::Open(file1);
  TFile *f2 = TFile::Open(file2);
  if (isleading) var = "leading_"+var;

  TH1F *h1 = (TH1F*)f1->Get("h_"+type1+"_"+var);
  TH1F *h2 = (TH1F*)f2->Get("h_"+type2+"_"+var);

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

  TString rad_str;
  if ((int)atof(radius) > 1) {
    rad_str.Form("R = 0.%i",(int)atof(radius));
  }
  else {
    rad_str.Form("R = %i.0",(int)atof(radius));
  }

  TString entry1, entry2;
  entry1 = file_legend_info[sample1]; entry2 = file_legend_info[sample2];
  if (type1 == type2) {
    xlabel = type_label[type1]+" "+xlabel;
    if (isleading) {
      xlabel = "Leading "+xlabel;
    }
  }
  else {
    if (isleading) xlabel = "Leading Jet "+xlabel;
  }
  if (type1 != type2) {
    entry1 = entry1+", "+type_labels[type1];
    entry2 = entry2+", "+type_labels[type2];
  }
  if (sample1.Contains("groomed")) entry1 += ", Groomed";
  if (sample2.Contains("groomed")) entry2 += ", Groomed";

  TCanvas *c = new TCanvas();
  h2->GetYaxis()->SetRangeUser(0,1.5*max);
  h2->GetXaxis()->SetTitle(xlabel);
  h2->GetYaxis()->SetTitle("a.u.");
  h2->Draw("hist");
  h1->Draw("histsame");
  TLegend leg(0.2,0.8,0.4,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.04);
  leg.SetShadowColor(0);
  leg.AddEntry(h1,entry1,"l");
  leg.AddEntry(h2,entry2,"l");
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.03);
  l.DrawLatex(0.55,0.85,"200 < p_{T}^{jet} < 400 GeV, "+rad_str);
  l.DrawLatex(0.55,0.8,sep);
  TString outname;
  if (type1 == type2) {
    outname = "plot_"+type1+"_"+var+"_"+sample1+"_vs_"+sample2;
  }
  if (sample1 == sample2) {
    outname = "plot_"+type1+"_vs_"+type2+"_"+var+"_"+sample1;
  }
  c->SaveAs(outname+".png");
  c->SaveAs(outname+".pdf");
  c->SaveAs(outname+".C");

}
