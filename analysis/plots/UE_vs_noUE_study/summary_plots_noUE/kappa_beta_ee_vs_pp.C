#include "helper.hh"
void kappa_beta_ee_vs_pp(TString radius, int rebin, int isleading, int groomed) {
  vector<TString> samp1;
  vector<TString> samp2;
  vector<TString> type;
  vector<TString> labels;
  samp1 = {"H2qqbar","H2gg"};
  samp2 = {"H2qqbar_ee","H2gg_ee"};
  type = {"qjet","gjet"};
  labels = {"H #rightarrow q#bar{q} (Quark Jets)","H #rightarrow gg (Gluon Jets)"};
  vector<TH1F*> sep_hists;
  vector<TString> angularities = {"multiplicity","ptD","LHA","width","mass"};
  vector<TString> kap_bet = {"(0,0)","(2,0)","(1,0.5)","(1,1)","(1,2)"};
  if (isleading) {
    for (int k = 0; k < angularities.size(); k++) {
      angularities[k] = "leading_"+angularities[k];
    }
  }

  TString yaxis = "pp vs. e^{+}e^{-} Separation";
  double ymax = 0;

  for (int i = 0; i < samp1.size(); i++) {
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
      TH1F *h1 = (TH1F*)f1->Get("h_"+type[i]+"_"+angularities[j]);
      TH1F *h2 = (TH1F*)f2->Get("h_"+type[i]+"_"+angularities[j]);
      h1->Sumw2();
      h2->Sumw2();
      h1->Scale(1/h1->Integral());
      h2->Scale(1/h2->Integral());
      TH1F *diff = integrand(h1,h2);
      /*TH1F *sum = (TH1F*)h1->Clone();
      sum->Add(h2);
      TH1F *diff = (TH1F*)h1->Clone();
      diff->Add(h2,-1);
      for (int i = 1; i <= diff->GetNbinsX(); i++) {
	diff->SetBinContent(i,diff->GetBinContent(i)*diff->GetBinContent(i));
      }
      diff->Divide(sum);*/
      double err;
      double separation_power = 0.5*diff->IntegralAndError(1,diff->GetNbinsX(),err);
      seps->SetBinContent(j+1,separation_power);
      seps->SetBinError(j+1,0.000001);
      seps->GetXaxis()->SetBinLabel(j+1,kap_bet[j]);
    }
    if (seps->GetMaximum() > ymax) ymax = seps->GetMaximum();
    seps->GetXaxis()->SetTitle("(#kappa,#beta)");
    seps->GetYaxis()->SetTitle(yaxis);
    seps->GetXaxis()->SetRangeUser(0,6);
    seps->GetYaxis()->SetRangeUser(0,0.25);
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
  TLegend leg(0.60,0.8,0.80,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.03);
  leg.SetShadowColor(0);
  for (int l = 0; l < sep_hists.size(); l++) {
    sep_hists[l]->SetMarkerSize(0);
    sep_hists[l]->GetYaxis()->SetRangeUser(0,0.18);
    sep_hists[l]->SetLabelSize(0.04,"y");
    sep_hists[l]->GetYaxis()->SetTitleOffset(1.5);
    sep_hists[l]->Draw("E same");
    leg.AddEntry(sep_hists[l],labels[l],"l");
  }
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.2,0.87,"PYTHIA 8.2");
  l.SetTextSize(0.03);
  //if (type == "qjet") l.DrawLatex(0.2,0.82,"Quark Jets, "+rad_str);
  //if (type == "gjet") l.DrawLatex(0.2,0.82,"Gluon Jets, "+rad_str);
  message = "#it{pp} vs. #it{e}^{+}#it{e}^{-}, "+rad_str;
  if (groomed) {l.DrawLatex(0.2,0.82,message+", Groomed");} else {l.DrawLatex(0.2,0.82,message);}
  //l.DrawLatex(0.42,0.9,"p_{T}^{jet} > 20 GeV, "+rad_str);
  //l.DrawLatex(0.42,0.85,message);
  TLine line;
  line.SetLineColor(0);
  line.SetLineWidth(5);
  //line.DrawLine(1,0.001,1,1.01*ymax);line.DrawLine(2,0.001,2,1.01*ymax);line.DrawLine(3,0.001,3,1.01*ymax);line.DrawLine(4,0.001,4,1.01*ymax);line.DrawLine(5,0.001,5,1.01*ymax);
  TString outname = "angularity_grid_pp_ee_sep_R"+radius;
  if (isleading) outname = "angularity_grid_pp_ee_leading_sep_R"+radius;
  if (groomed) outname = "groomed_"+outname;
  c->SaveAs(outname+".C");
  c->SaveAs(outname+".pdf");
}
  
