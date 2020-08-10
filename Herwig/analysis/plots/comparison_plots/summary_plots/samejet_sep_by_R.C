#include "helper.hh"
void samejet_sep_by_R(TString angularity, TString type, int rebin, int isleading, int groomed) {

  vector<TString> samp1;
  vector<TString> samp2;
  vector<TString> labels;
  if (type == "qjet") {
    samp1 = {"dijets","dijets","zplusjets"};
    samp2 = {"zplusjets","H2qqbar","H2qqbar"};
    labels = {"Dijets vs Z+jets","Dijets vs H #rightarrow q#bar{q}","Z+jets vs H #rightarrow q#bar{q}"};
  }
  else {
    samp1 = {"dijets","dijets","zplusjets","qqbar2Zg"};
    samp2 = {"zplusjets","H2gg","H2gg","gg2Hg"};
    labels = {"Dijets vs Z+jets","Dijets vs H #rightarrow gg","Z+jets vs H #rightarrow gg","q#bar{q} #rightarrow Zg vs gg #rightarrow Hg"};
  }
  vector<TGraph*> sep_graphs;
  vector<TString> radii = {"02","03","04","05","06","07","08","09","1","11","12","13","14","15"};
  double xvals[14] = {0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5};
  TString yaxis;
  if (type == "qjet") yaxis = "Quark Jet Separation";
  if (type == "gjet") yaxis = "Gluon Jet Separation";
  TString label = ang_labels[angularity];
  if (isleading) angularity = "leading_"+angularity;
  double ymax = 0;

  for (int i = 0; i < samp1.size(); i++) {
    double yvals[14];
    for (int j = 0; j < radii.size(); j++) {
      TFile *f1;
      TFile *f2;
      if (groomed) {
	f1 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_groomed_"+samp1[i]+"_rewt.root");
	f2 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_groomed_"+samp2[i]+"_rewt.root");
      }
      else {
	f1 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_"+samp1[i]+"_rewt.root");
	f2 = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_"+samp2[i]+"_rewt.root");
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
    TGraph *seps = new TGraph(14,xvals,yvals);
    seps->SetNameTitle("graph_"+samp1[i]+"_"+samp2[i],"graph_"+samp1[i]+"_"+samp2[i]);
    sep_graphs.push_back(seps);
  }

  TString message = "All Jets";
  if (isleading) message = "Leading Jets";
  if (groomed) message = message+", Groomed";

  TCanvas *c = new TCanvas("c","c",4);
  TLegend leg(0.2,0.7,0.4,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.03);
  leg.SetShadowColor(0);
  for (int l = 0; l < sep_graphs.size(); l++) {
    if (l == 0) {sep_graphs[l]->Draw("ALPsame");}
    else {sep_graphs[l]->Draw("LPsame");}
    sep_graphs[l]->GetXaxis()->SetTitle("Jet Radius");
    sep_graphs[l]->GetYaxis()->SetTitle(yaxis);
    sep_graphs[l]->GetYaxis()->SetTitleSize(0.04);
    sep_graphs[l]->GetYaxis()->SetLabelSize(0.04);
    sep_graphs[l]->GetXaxis()->SetLabelSize(0.04);
    sep_graphs[l]->GetXaxis()->SetRangeUser(0.1,1.6);
    sep_graphs[l]->GetYaxis()->SetRangeUser(0,0.016);
    sep_graphs[l]->GetYaxis()->SetNdivisions(505);
    sep_graphs[l]->GetYaxis()->SetTitleOffset(2);
    sep_graphs[l]->SetLineColor(l+1);
    sep_graphs[l]->SetLineStyle(l+1);
    sep_graphs[l]->SetMarkerStyle(20+l);
    sep_graphs[l]->SetMarkerColor(l+1);
    //c->Update();
    leg.AddEntry(sep_graphs[l],labels[l],"lp");
  }
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.5,0.87,"HERWIG 7.1");
  l.SetTextSize(0.03);
  if (type == "qjet") message = "Quark Jets, #bf{"+label+"}";
  if (type == "gjet") message = "Gluon Jets, #bf{"+label+"}";
  if (groomed) {l.DrawLatex(0.5,0.82,"Groomed "+message);} else {l.DrawLatex(0.5,0.82,message);}
  //l.DrawLatex(0.42,0.9,"p_{T}^{jet} > 20 GeV");
  //l.DrawLatex(0.42,0.85,message);
  TString outname = "graph_"+type+"_"+angularity+"_sep_by_R";
  if (groomed) outname = "groomed_"+outname;
  c->SaveAs(outname+".C");
  c->SaveAs(outname+".pdf");
}
  
