#include "helper.hh"

void plot_angularity_qvg(TString ang, TString radius, TString sample) {
  TFile *f = TFile::Open(analysis_path+"/Radius_"+radius+"/output_"+sample+"_rewt.root");
  TH1F *h_qjet = (TH1F*)f->Get("h_qjet_"+ang);
  TH1F *h_gjet = (TH1F*)f->Get("h_gjet_"+ang);

  h_qjet->Scale(1/h_qjet->Integral());
  h_gjet->Scale(1/h_gjet->Integral());
  h_qjet->SetLineColor(1); h_qjet->SetLineStyle(1);
  h_gjet->SetLineColor(2); h_gjet->SetLineStyle(2);
  
  TString rad_str;
  if ((int)atof(radius) > 1) {
    rad_str.Form("R = 0.%i",(int)atof(radius));
  }
  else {
    rad_str.Form("R = %i.0",(int)atof(radius));
  }

  double max = h_qjet->GetMaximum();
  if (h_gjet->GetMaximum() > max) max = h_gjet->GetMaximum();

  TCanvas *c = new TCanvas("c","c",4);
  TLegend leg(0.7,0.75,0.9,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.03);
  leg.SetShadowColor(0);
  
  h_qjet->GetXaxis()->SetTitle(ang_labels[ang]);
  h_qjet->GetYaxis()->SetTitle("Normalized to Unity");
  h_qjet->GetYaxis()->SetTitleSize(0.04);
  h_qjet->SetLabelSize(0.04,"y");
  h_qjet->SetLabelSize(0.04,"x");
  h_qjet->GetYaxis()->SetTitleOffset(1.8);
  h_qjet->GetYaxis()->SetNdivisions(505);
  h_qjet->GetYaxis()->SetRangeUser(0,1.5*max);
  
  h_qjet->Draw("histsame");
  h_gjet->Draw("histsame");
  
  leg.AddEntry(h_qjet,"Quark Jets","l");
  leg.AddEntry(h_gjet,"Gluon Jets","l");
  leg.Draw();
  
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.2,0.87,"PYTHIA 8.2");
  l.SetTextSize(0.03);
  l.DrawLatex(0.2,0.82,"#bf{"+samp_labels[sample]+"}, "+rad_str);
  TString outname = "compare_qjet_gjet_"+ang+"_"+sample;
  c->SaveAs(outname+".C");
  c->SaveAs(outname+".pdf");
}
  

  
