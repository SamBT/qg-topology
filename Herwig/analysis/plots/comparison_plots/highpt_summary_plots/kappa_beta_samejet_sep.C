#include "helper.hh"
void kappa_beta_samejet_sep(TString radius, TString type, int rebin, int isleading, int groomed) {
  vector<TString> samp1;
  vector<TString> samp2;
  vector<TString> labels;
  if (type == "qjet") {
    samp1 = {"dijets","dijets","dijets","zplusjets","zplusjets"};
    samp2 = {"zplusjets","H2qqbar","H2qqbar_boosted","H2qqbar","H2qqbar_boosted"};
  }
  else {
    samp1 = {"dijets","dijets","dijets","zplusjets","zplusjets","qqbar2Zg"};
    samp2 = {"zplusjets","H2gg","H2gg_boosted","H2gg","H2gg_boosted","gg2Hg"};
  }
  vector<TH1F*> sep_hists;
  vector<TString> angularities = {"multiplicity","ptD","LHA","width","mass"};
  vector<TString> kap_bet = {"(0,0)","(2,0)","(1,0.5)","(1,1)","(1,2)"};
  if (isleading) {
    for (int k = 0; k < angularities.size(); k++) {
      angularities[k] = "leading_"+angularities[k];
    }
  }

  TString yaxis;
  if (type == "qjet") yaxis = "Quark Jet Separation";
  if (type == "gjet") yaxis = "Gluon Jet Separation";
  double ymax = 0;

  for (int i = 0; i < samp1.size(); i++) {
    labels.push_back(samp_labels[samp1[i]]+" vs. "+samp_labels[samp2[i]]);
    TFile *f1;
    TFile *f2;
    if (groomed) {
      f1 = TFile::Open(analysis_path+"/Radius_"+radius+"/output_groomed_"+samp1[i]+"_rewt.root");
      f2 = TFile::Open(analysis_path+"/Radius_"+radius+"/output_groomed_"+samp2[i]+"_rewt.root");
    }
    else {
      f1 = TFile::Open(analysis_path+"/Radius_"+radius+"/output_"+samp1[i]+"_rewt.root");
      f2 = TFile::Open(analysis_path+"/Radius_"+radius+"/output_"+samp2[i]+"_rewt.root");
    }
    TH1F *seps = new TH1F("seps_"+samp1[i]+"_"+samp2[i],"seps_"+samp1[i]+"_"+samp2[i],5,0,5);
    for (int j = 0; j < angularities.size(); j++) {
      TH1F *h1 = (TH1F*)f1->Get("h_"+type+"_"+angularities[j]);
      TH1F *h2 = (TH1F*)f2->Get("h_"+type+"_"+angularities[j]);
      h1->Sumw2();
      h2->Sumw2();
      h1->Scale(1/h1->Integral());
      h2->Scale(1/h2->Integral());
      TH1F *diff = integrand(h1,h2);
      double err;
      double separation_power = 0.5*diff->IntegralAndError(1,diff->GetNbinsX(),err);
      seps->SetBinContent(j+1,separation_power);
      seps->SetBinError(j+1,0.5*err);
      seps->GetXaxis()->SetBinLabel(j+1,kap_bet[j]);
    }
    if (seps->GetMaximum() > ymax) ymax = seps->GetMaximum();
    seps->GetXaxis()->SetTitle("(#kappa,#beta)");
    seps->GetYaxis()->SetTitle(yaxis);
    seps->GetXaxis()->SetRangeUser(0,6);
    seps->GetYaxis()->SetRangeUser(0,0.25);
    if (i+1 == 5) {seps->SetLineColor(kOrange+7);} else {seps->SetLineColor(i+1);}
    seps->SetLineStyle(i+1);
    sep_hists.push_back(seps);
  }

  TString rad_str;
  if ((int)atof(radius) > 1) {
    rad_str.Form("R = 0.%i",(int)atof(radius));
  }
  else {
    rad_str.Form("R = %i.0",(int)atof(radius));
  }

  TString message = "All Jets";
  if (isleading) message = "Leading Jets";
  if (groomed) message = message+", Groomed";

  TCanvas *c = new TCanvas();
  TLegend leg(0.7,0.75,0.9,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.03);
  leg.SetShadowColor(0);
  for (int l = 0; l < sep_hists.size(); l++) {
    sep_hists[l]->SetMarkerSize(0);
    sep_hists[l]->GetYaxis()->SetRangeUser(0,1.5*ymax);
    sep_hists[l]->Draw("Esame");
    leg.AddEntry(sep_hists[l],labels[l],"l");
  }
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.03);
  if (groomed) {l.DrawLatex(0.42,0.9,"p_{T}^{jet} < 400 GeV, "+rad_str);}
  else {l.DrawLatex(0.42,0.9,"200 < p_{T}^{jet} < 400 GeV, "+rad_str);}
  l.DrawLatex(0.42,0.85,message);
  TString outname = "angularity_grid_"+type+"_sep_R"+radius;
  if (isleading) outname = "angularity_grid_"+type+"_leading_sep_R"+radius;
  if (groomed) outname = "groomed_"+outname;
  c->SaveAs(outname+".C");
  c->SaveAs(outname+".pdf");
}
  
