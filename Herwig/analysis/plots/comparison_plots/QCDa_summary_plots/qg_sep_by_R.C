#include "helper.hh"
void qg_sep_by_R(TString angularity, int rebin, int isleading, int groomed) {

  vector<TString> samples = {"zplusjets","dijets"};
  vector<TString> labels = {"Z+jets","Dijets"};
  vector<TGraph*> sep_graphs;
  vector<TString> radii = {"04","05","06","07","08","09","1","11","12","13","14","15"};
  TString yaxis = "Quark vs. Gluon Jet "+ang_labels[angularity]+" Separation";
  if (isleading) angularity = "leading_"+angularity;
  double xvals[12] = {0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5};
  double ymax = 0;

  for (int i = 0; i < samples.size(); i++) {
    double yvals[12];
    for (int j = 0; j < radii.size(); j++) {
      TFile *f;
      if (groomed) {
	f = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_groomed_"+samples[i]+"_rewt.root");
      }
      else {
	f = TFile::Open(analysis_path+"/Radius_"+radii[j]+"/output_"+samples[i]+"_rewt.root");
      }
      TH1F *hq = (TH1F*)f->Get("h_qjet_"+angularity);
      TH1F *hg = (TH1F*)f->Get("h_gjet_"+angularity);
      hq->Sumw2();
      hg->Sumw2();
      hq->Scale(1/hq->Integral());
      hg->Scale(1/hg->Integral());
      TH1F *diff = integrand(hq,hg);
      double err;
      double separation_power = 0.5*diff->IntegralAndError(1,diff->GetNbinsX(),err);
      yvals[j] = separation_power;
      if (separation_power > ymax) ymax = separation_power;
    }
    TGraph *seps = new TGraph(12,xvals,yvals);
    seps->SetNameTitle("graph_"+samples[i],"graph_"+samples[i]);
    sep_graphs.push_back(seps);
  }

  TString message = "All Jets";
  if (isleading) message = "Leading Jets";
  if (groomed) message = message+", Groomed";

  TCanvas *c = new TCanvas();
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
  l.DrawLatex(0.42,0.9,"p_{T}^{jet} > 20 GeV");
  l.DrawLatex(0.42,0.85,message);
  TString outname = "graph_qg_"+angularity+"_sep_by_R";
  if (groomed) outname = "groomed_"+outname;
  c->SaveAs(outname+".C");
  c->SaveAs(outname+".pdf");
}
  
