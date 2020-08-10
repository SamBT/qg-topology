#include "helper.hh"
void kappa_beta_qg_sep(TString radius, int rebin, int isleading, int groomed) {

  vector<TString> samples = {"zplusjets","dijets"};
  vector<TString> labels = {"Z+jets","Dijets"};
  vector<TH1F*> sep_hists;
  vector<TString> angularities = {"multiplicity","ptD","LHA","width","mass"};
  vector<TString> kap_bet = {"(0,0)","(2,0)","(1,0.5)","(1,1)","(1,2)"};
  if (isleading) {
    for (int k = 0; k < angularities.size(); k++) {
      angularities[k] = "leading_"+angularities[k];
    }
  }
  double ymax = 0;
  for (int i = 0; i < samples.size(); i++) {
    TFile *f;
    if (groomed) {
      f = TFile::Open(analysis_path+"/Radius_"+radius+"/output_groomed_"+samples[i]+"_rewt.root");
    }
    else {
      f = TFile::Open(analysis_path+"/Radius_"+radius+"/output_"+samples[i]+"_rewt.root");
    }
    TH1F *seps = new TH1F("seps_"+samples[i],"seps_"+samples[i],5,0,5);
    for (int j = 0; j < angularities.size(); j++) {
      TH1F *hq = (TH1F*)f->Get("h_qjet_"+angularities[j]);
      TH1F *hg = (TH1F*)f->Get("h_gjet_"+angularities[j]);
      hq->Sumw2();
      hg->Sumw2();
      hq->Scale(1/hq->Integral());
      hg->Scale(1/hg->Integral());
      TH1F *diff = integrand(hq,hg);
      double err;
      double separation_power = 0.5*diff->IntegralAndError(1,diff->GetNbinsX(),err);
      seps->SetBinContent(j+1,separation_power);
      seps->SetBinError(j+1,0.5*err);
      seps->GetXaxis()->SetBinLabel(j+1,kap_bet[j]);
    }
    if (seps->GetMaximum() > ymax) ymax = seps->GetMaximum();
    seps->GetXaxis()->SetTitle("(#kappa,#beta)");
    seps->GetYaxis()->SetTitle("Quark vs. Gluon Jet Separation");
    seps->GetXaxis()->SetRangeUser(0,6);
    //seps->GetYaxis()->SetRangeUser(0,0.25);
    seps->SetLineColor(i+1);
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

  TCanvas *c = new TCanvas("c","c",4);
  TLegend leg(0.7,0.75,0.9,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.03);
  leg.SetShadowColor(0);
  for (int l = 0; l < sep_hists.size(); l++) {
    sep_hists[l]->SetMarkerSize(0);
    sep_hists[l]->GetYaxis()->SetRangeUser(0,1.5*ymax);
    sep_hists[l]->SetLabelSize(0.04,"y");
    sep_hists[l]->Draw("Esame");
    leg.AddEntry(sep_hists[l],labels[l],"l");
  }
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.2,0.87,"PYTHIA 8.2");
  l.SetTextSize(0.03);
  if (groomed) {
    l.DrawLatex(0.2,0.82,"Quark vs. Gluon Jets (Groomed), "+rad_str);
  }
  else {
    l.DrawLatex(0.2,0.82,"Quark vs. Gluon Jets, "+rad_str);
  }
  l.DrawLatex(0.2,0.78,"QCD aware");
  //l.DrawLatex(0.42,0.9,"p_{T}^{jet} > 20 GeV, "+rad_str);
  //l.DrawLatex(0.42,0.85,message);
  TString outname = "angularity_grid_qg_sep_R"+radius;
  if (isleading) outname = "angularity_grid_qg_leading_sep_R"+radius;
  if (groomed) outname = "groomed_"+outname;
  c->SaveAs(outname+".C");
  c->SaveAs(outname+".pdf");
}
  
