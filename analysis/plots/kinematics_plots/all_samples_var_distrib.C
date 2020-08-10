#include "helper.hh"

void all_samples_var_distrib(TString type, TString var, TString radius) {
  vector<TH1F*> histos;
  double ymax = 0;
  vector<TString> loop;
  int col = 1;
  if (type == "qjet") loop = samples_qjet;
  if (type == "gjet") loop = samples_gjet;
  for (int i = 0; i < loop.size(); i++) {
    TFile *f = TFile::Open(analysis_path+"/Radius_"+radius+"/output_"+loop[i]+".root");
    cout << "Sample is " << analysis_path+"/Radius_"+radius+"/output_"+loop[i]+".root" << endl;
    cout << "histo is " << "h_"+type+"_"+var << endl;
    TH1F *h = (TH1F*)f->Get("h_"+type+"_"+var);
    h->SetNameTitle(loop[i]+"_"+var, loop[i]+"_"+var);
    h->Scale(1/h->Integral());
    if (h->GetMaximum() > ymax) ymax = h->GetMaximum();
    if (col == 5) col += 1;
    h->SetLineColor(col);
    h->SetMarkerColor(col);
    h->SetLineStyle(i+1);
    histos.push_back(h);
    col += 1;
  }
  
  TString rad_str;
  if ((int)atof(radius) > 1) {
    rad_str.Form("R = 0.%i",(int)atof(radius));
  }
  else {
    rad_str.Form("R = %i.0",(int)atof(radius));
  }

  TCanvas *c = new TCanvas("c","c",4);
  //Double_t w = 600;
  //Double_t h = 600;
  //TCanvas *c = new TCanvas("c","c",w,h);
  //c->SetWindowSize(w + (w - c->GetWw()), h + (h - c->GetWh()));
  //if (var == "pt") c->SetLogy();
  TLegend leg(0.7,0.65,0.9,0.9);
  leg.SetLineColor(0);
  leg.SetFillStyle(0);    
  leg.SetTextSize(0.03);
  leg.SetShadowColor(0);
  for (int j = 0; j < histos.size(); j++) {
    /*if (var == "pt") {
      histos[j]->GetYaxis()->SetRangeUser(0,10*ymax);
      histos[j]->GetXaxis()->SetTitle("p_{T} [GeV]");
      }*/
    
    histos[j]->GetYaxis()->SetRangeUser(0,1.5*ymax);
    histos[j]->GetYaxis()->SetNdivisions(505);
    histos[j]->GetXaxis()->SetNdivisions(505);
    if (var == "eta") histos[j]->GetXaxis()->SetRangeUser(-2,2);
    if (var == "eta") histos[j]->GetXaxis()->SetTitle("#eta");
    if (var == "pt") {histos[j]->GetXaxis()->SetRangeUser(50,150); histos[j]->GetXaxis()->SetTitle("p_{T} [GeV]");}
    histos[j]->GetYaxis()->SetTitle("Normalized to Unity");
    histos[j]->GetYaxis()->SetTitleSize(0.04);
    histos[j]->SetLabelSize(0.04,"x");
    histos[j]->SetLabelSize(0.04,"y");
    histos[j]->GetYaxis()->SetTitleOffset(1.8);
    histos[j]->Draw("histsame");
    leg.AddEntry(histos[j],samp_labels[loop[j]],"l");
  }
  leg.Draw();
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.04);
  l.DrawLatex(0.2,0.87,"PYTHIA 8.2");
  l.SetTextSize(0.03);
  if (type == "qjet") l.DrawLatex(0.2,0.82,"Quark Jets, "+rad_str);
  if (type == "gjet") l.DrawLatex(0.2,0.82,"Gluon Jets, "+rad_str);
  TString outname = type+"_"+var+"_comparisons_R"+radius;
  c->SaveAs(outname+".C");
  c->SaveAs(outname+".pdf");
}
    
