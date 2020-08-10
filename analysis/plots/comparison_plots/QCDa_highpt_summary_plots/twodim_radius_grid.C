#include "helper.hh"
void twodim_radius_grid(TString samp1, TString samp2, TString type, int rebin, int isleading, int groomed) {
  vector<TString> angularities = {"multiplicity","ptD","LHA","width","mass"};
  vector<TString> kap_bet = {"(0,0)","(2,0)","(1,0.5)","(1,1)","(1,2)"};
  vector<TString> radii = {"04","05","06","07","08","09","1","11","12","13","14","15"};
  if (isleading) {
    for (int k = 0; k < angularities.size(); k++) {
      angularities[k] = "leading_"+angularities[k];
    }
  }
  
  TH2F *kapbet_rad_sep = new TH2F("kapbet_rad_sep","kapbet_rad_sep",5,0,5,12,0.35,1.55);

  for (int i = 0; i < angularities.size(); i++) {
    for (int j = 0; j < radii.size(); j++) {
      TString hname = "h_"+type+"_"+angularities[i];
      TFile *f1;
      TFile *f2;
      if (groomed) {
	f1 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_groomed_"+samp1+"_rewt.root");
	f2 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_groomed_"+samp2+"_rewt.root");
      }
      else {
	f1 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_"+samp1+"_rewt.root");
	f2 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_"+samp2+"_rewt.root");
      }
      TH1F *h1 = (TH1F*)f1->Get(hname);
      TH1F *h2 = (TH1F*)f2->Get(hname);
      h1->Sumw2();
      h2->Sumw2();
      h1->Scale(1/h1->Integral());
      h2->Scale(1/h2->Integral());
      TH1F *diff = integrand(h1,h2);
      double err;
      double separation_power = 0.5*diff->IntegralAndError(1,diff->GetNbinsX(),err);
      kapbet_rad_sep->SetBinContent(i+1,j+1,separation_power);
      kapbet_rad_sep->GetXaxis()->SetBinLabel(i+1,kap_bet[i]);
    }
  }
  kapbet_rad_sep->GetXaxis()->SetTitle("(#kappa,#beta)");
  kapbet_rad_sep->GetYaxis()->SetTitle("Jet Radius");
  kapbet_rad_sep->GetYaxis()->SetNdivisions(12);
  TString jets, comparison;
  if (type == "qjet") jets = "Quark Jets";
  if (type == "gjet") jets = "Gluon Jets";
  if (isleading) jets = "Leading "+jets;
  if (groomed) {jets = jets+", Groomed, p_{T}^{jet} < 400 GeV";}
  else {jets = jets+", 200 < p_{T}^{jet} < 400 GeV";}
  comparison = samp_labels[samp1] + " vs. " + samp_labels[samp2];
  
  TCanvas *c = new TCanvas();
  c->SetRightMargin(0.18);
  kapbet_rad_sep->Draw("COLZ");
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.15,0.96,comparison+", "+jets);
  TString outname;
  if (isleading) {outname = "allrads_allangs_leading_"+type+"_"+samp1+"_vs_"+samp2+"_col";}
  else {outname = "allrads_allangs_"+type+"_"+samp1+"_vs_"+samp2+"_col";}
  if (groomed) outname = "groomed_"+outname;
  c->SaveAs(outname+".C");
  c->SaveAs(outname+".pdf");

  gStyle->SetPaintTextFormat("1.3f");
  TCanvas *c2 = new TCanvas();
  kapbet_rad_sep->Draw("text");
  TLatex l2;
  l2.SetNDC();
  l2.SetTextSize(0.04);
  l2.DrawLatex(0.15,0.96,comparison+", "+jets);
  TString outname2;
  if (isleading) {outname2 = "allrads_allangs_leading_"+type+"_"+samp1+"_vs_"+samp2+"_text";}
  else {outname2 = "allrads_allangs_"+type+"_"+samp1+"_vs_"+samp2+"_text";}
  if (groomed) outname2 = "groomed_"+outname2;
  c2->SaveAs(outname2+".C");
  c2->SaveAs(outname2+".pdf");
}
  
  
  
