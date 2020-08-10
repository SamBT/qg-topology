#include "helper.hh"
void individual_samejet_sep_by_R(TString sample1, TString sample2, TString angularity, TString type, int rebin, int isleading, int groomed) {

  TString label = samp_labels[sample1]+" vs "+samp_labels[sample2];
  vector<TString> radii = {"04","05","06","07","08","09","1"};
  double xvals[7] = {0.4,0.5,0.6,0.7,0.8,0.9,1.0};
  TString yaxis;
  if (type == "qjet") yaxis = "Quark Jet "+ang_labels[angularity]+" Separation";
  if (type == "gjet") yaxis = "Gluon Jet "+ang_labels[angularity]+" Separation";
  if (isleading) angularity = "leading_"+angularity;
  double ymax = 0;

  double yvals[7];
  for (int j = 0; j < radii.size(); j++) {
    TFile *f1;
    TFile *f2;
    if (groomed) {
      f1 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_groomed_"+sample1+"_rewt.root");
      f2 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_groomed_"+sample2+"_rewt.root");
    }
    else {
      f1 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_"+sample1+"_rewt.root");
      f2 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_"+sample2+"_rewt.root");
    }
    TH1F *h1 = (TH1F*)f1->Get("h_"+type+"_"+angularity);
    TH1F *h2 = (TH1F*)f2->Get("h_"+type+"_"+angularity);
    h1->Sumw2();
    h2->Sumw2();
    h1->Scale(1/h1->Integral());
    h2->Scale(1/h2->Integral());
    TH1F *diff = integrand(h1,h2);
    double err;
    double separation_power = 0.5*diff->IntegralAndError(1,diff->GetNbinsX(),err);
    yvals[j] = separation_power;
    if (separation_power > ymax) ymax = separation_power;
  }
  TGraph *sep_graph = new TGraph(7,xvals,yvals);

  TString message = "All Jets";
  if (isleading) message = "Leading Jets";
  if (groomed) message = message+", Groomed";

  TCanvas *c = new TCanvas();
  TLegend leg(0.2,0.7,0.4,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.03);
  leg.SetShadowColor(0);
  sep_graph->Draw("ALPsame");
  sep_graph->GetXaxis()->SetTitle("Jet Radius");
  sep_graph->GetYaxis()->SetTitle(yaxis);
  sep_graph->GetYaxis()->SetTitleSize(0.04);
  sep_graph->GetYaxis()->SetLabelSize(0.04);
  sep_graph->GetXaxis()->SetLabelSize(0.04);
  sep_graph->GetXaxis()->SetRangeUser(0.3,1.1);
  sep_graph->GetYaxis()->SetRangeUser(0,1.5*ymax);
  sep_graph->SetLineColor(1);
  sep_graph->SetLineStyle(1);
  sep_graph->SetMarkerStyle(20);
  sep_graph->SetMarkerColor(1);
  //c->Update();
  leg.AddEntry(sep_graph,label,"lp");
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.03);
  if (groomed) {l.DrawLatex(0.42,0.9,"p_{T}^{jet} < 400 GeV");}
  else {l.DrawLatex(0.42,0.9,"200 < p_{T}^{jet} < 400 GeV");}
  l.DrawLatex(0.42,0.85,message);
  TString outname = "graph_"+sample1+"_vs_"+sample2+"_"+type+"_"+angularity+"_sep_by_R";
  if (groomed) outname = "groomed_"+outname;
  c->SaveAs(outname+".C");
  c->SaveAs(outname+".pdf");
}

