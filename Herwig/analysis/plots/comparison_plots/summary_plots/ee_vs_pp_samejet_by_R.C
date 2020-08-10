#include "helper.hh"
void ee_vs_pp_samejet_by_R(TString angularity, int rebin, int isleading, int groomed) {

  vector<TString> samp1;
  vector<TString> samp2;
  vector<TString> labels;
  samp1 = {"H2qqbar","H2gg"};
  samp2 = {"H2qqbar_ee","H2gg_ee"};
  labels = {"H #rightarrow q#bar{q} (Quark Jets)","H #rightarrow gg (Gluon Jets)"};
  vector<TGraph*> sep_graphs;
  vector<TString> radii = {"04","05","06","07","08","09","1","11","12","13","14","15"};
  double xvals[12] = {0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5};
  TString yaxis = "pp vs e^{+}e^{-} Separation";
  if (isleading) angularity = "leading_"+angularity;
  double ymax = 0;

  for (int i = 0; i < samp1.size(); i++) {
    double yvals[12];
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
      TString type;
      if (i == 0) type = "qjet";
      if (i == 1) type = "gjet";
      TH1F *h1 = (TH1F*)f1->Get("h_"+type+"_"+angularity);
      TH1F *h2 = (TH1F*)f2->Get("h_"+type+"_"+angularity);
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
      yvals[j] = separation_power;
      if (separation_power > ymax) ymax = separation_power;
    }
    TGraph *seps = new TGraph(12,xvals,yvals);
    seps->SetNameTitle("graph_"+samp1[i]+"_"+samp2[i],"graph_"+samp1[i]+"_"+samp2[i]);
    sep_graphs.push_back(seps);
  }

  TString message = "All Jets";
  if (isleading) message = "Leading Jets";
  if (groomed) message = message+", Groomed";

  TCanvas *c = new TCanvas();
  TLegend leg(0.2,0.8,0.4,0.9);
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
    sep_graphs[l]->GetXaxis()->SetRangeUser(0.3,1.6);
    sep_graphs[l]->GetYaxis()->SetRangeUser(0,1.5*ymax);
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
  l.DrawLatex(0.2,0.78,"p_{T}^{jet} > 20 GeV");
  l.DrawLatex(0.2,0.73,message);
  TString outname = "by_radius_ee_vs_pp_"+angularity+"_sep";
  if (groomed) outname = "groomed_"+outname;
  c->SaveAs(outname+".C");
  c->SaveAs(outname+".pdf");
}
  
