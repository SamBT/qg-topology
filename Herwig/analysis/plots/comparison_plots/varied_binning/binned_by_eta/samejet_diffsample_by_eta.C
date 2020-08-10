void samejet_diffsample_by_eta(TString type, TString var, TString xlabel, int rebin) {
  TFile *fd = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_rewt.root");
  TFile *fz = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets.root");

  TH2F *h2d = (TH2F*)fd->Get("h_"+type+"_"+var+"_eta");
  TH2F *h2z = (TH2F*)fz->Get("h_"+type+"_"+var+"_eta");

  h2d->RebinY(5);
  h2z->RebinY(5);

  double etalow, etahigh;

  TProfile *separation_power_by_eta = new TProfile("separation_power_by_eta","separation_power_by_eta",10,-2.5,2.5,0,1);
  
  for (int i = 1; i <= h2d->GetNbinsY(); i++) {

    TH1F *hd = (TH1F*)h2d->ProjectionX("hd",i,i);
    TH1F *hz = (TH1F*)h2z->ProjectionX("hz",i,i);
    etalow = h2d->GetYaxis()->GetBinLowEdge(i);
    etahigh = etalow + h2d->GetYaxis()->GetBinWidth(i);

    TString dRrange; dRrange.Form("%.1f < #eta < %.1f",etalow,etahigh);

    hd->Rebin(rebin);
    hz->Rebin(rebin);
    hz->SetLineColor(2);
  
    //Normalizing to unity
    hd->Scale(1/hd->Integral());
    hz->Scale(1/hz->Integral());

    TH1F *sum = (TH1F*)hd->Clone();
    sum->Add(hz);
    
    TH1F *diff = (TH1F*)hd->Clone();
    diff->Add(hz,-1);
    
    //Squaring the difference of the two hists
    for (int i = 1; i <= diff->GetNbinsX(); i++) {
      diff->SetBinContent(i,diff->GetBinContent(i)*diff->GetBinContent(i));
    }
    
    diff->Divide(sum);
    double separation_power = 0.5*diff->Integral();

    separation_power_by_eta->Fill(etalow,separation_power);
    
    TString sep; sep.Form("Separation Power = %.3f",separation_power);
    
    double max = hd->GetMaximum();
    if (hz->GetMaximum() > max) max = hz->GetMaximum();

    TCanvas *c = new TCanvas();
    hz->GetYaxis()->SetRangeUser(0,1.5*max);
    hz->GetXaxis()->SetTitle(xlabel);
    hz->GetYaxis()->SetTitle("a.u.");
    hz->Draw("hist");
    hd->Draw("histsame");
    TLegend leg(0.2,0.8,0.4,0.9);
    leg.SetLineColor(0);
    leg.SetFillStyle(0);    
    leg.SetTextSize(0.04);
    leg.SetShadowColor(0);
    leg.AddEntry(hd,"Dijets","l");
    leg.AddEntry(hz,"Z+jets","l");
    leg.Draw();
    TLatex l;
    l.SetNDC();
    l.SetTextSize(0.04);
    if (type == "qjet") l.DrawLatex(0.45,0.85,"Quark Jets, p_{T}^{jet} > 20 GeV");
    if (type == "gjet") l.DrawLatex(0.45,0.85,"Gluon Jets, p_{T}^{jet} > 20 GeV");
    l.DrawLatex(0.45,0.8,dRrange);
    l.DrawLatex(0.45,0.75,sep);
    TString dRstring; dRstring.Form("eta_%.1f_%.1f_",etalow,etahigh);
    TString outname = "compare_"+type+"_"+var+"_"+dRstring;
    c->SaveAs(outname+".png");
    c->SaveAs(outname+".pdf");
  }

  TCanvas *c1 = new TCanvas();
  separation_power_by_eta->GetXaxis()->SetTitle("#eta");
  separation_power_by_eta->GetYaxis()->SetTitle("Separation Power");
  separation_power_by_eta->GetYaxis()->SetRangeUser(0,0.2);
  separation_power_by_eta->Draw("pl");
  TLatex l1;
  l1.SetNDC();
  l1.SetTextSize(0.04);
  if (var == "ptD") {
    l1.DrawLatex(0.2,0.85,"Separation Power by #eta for p_{T}^{D}");
  }
  else { 
    l1.DrawLatex(0.2,0.85,"Separation Power by #eta for "+var);
  }
  if (type == "qjet") l1.DrawLatex(0.2,0.9,"Quark Jets, p_{T}^{jet} > 20 GeV");
  if (type == "gjet") l1.DrawLatex(0.2,0.9,"Gluon Jets, p_{T}^{jet} > 20 GeV");
  c1->SaveAs(type+"_"+var+"_sep_power_by_eta.png");
  c1->SaveAs(type+"_"+var+"_sep_power_by_eta.pdf");
}
