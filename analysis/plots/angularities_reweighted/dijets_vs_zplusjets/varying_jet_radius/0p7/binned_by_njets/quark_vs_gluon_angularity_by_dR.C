void quark_vs_gluon_angularity_by_dR(TString type, TString var, TString xlabel, int rebin, int njets) {
  TString filename;
  if (type == "dijets") filename.Form("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_rewt_%ijets.root",njets);
  if (type == "zplusjets") filename.Form("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets_%ijets.root",njets-1);
  
  TFile *f1 = TFile::Open(filename);

  TH2F *h2q = (TH2F*)f1->Get("h_qjet_"+var+"_nearestdR");
  TH2F *h2g = (TH2F*)f1->Get("h_gjet_"+var+"_nearestdR");

  h2q->RebinY(4);
  h2g->RebinY(4);

  double dRlow, dRhigh;

  TString s; s.Form("%ijets",njets);

  TProfile *separation_power_by_dR = new TProfile("separation_power_by_dR","separation_power_by_dR",9,0.4,4,0,1);

  TString dijets_label; dijets_label.Form("Dijets, N_{jets} = %i, p_{T}^{jet} > 20 GeV",njets);
  TString zplusjets_label; zplusjets_label.Form("Z+%i jets, p_{T}^{jet} > 20 GeV",njets-1);
  
  for (int i = 2; i <= h2q->GetNbinsY(); i++) {
    
    TH1F *hq = (TH1F*)h2q->ProjectionX("hq",i,i);
    TH1F *hg = (TH1F*)h2g->ProjectionX("hg",i,i);
    dRlow = h2q->GetYaxis()->GetBinLowEdge(i);
    dRhigh = dRlow + h2q->GetYaxis()->GetBinWidth(i);
    if (dRlow == 4) break;

    TString dRrange; dRrange.Form("%.1f < #DeltaR_{nearest} < %.1f",dRlow,dRhigh);

    hq->Rebin(rebin);
    hg->Rebin(rebin);
    hg->SetLineColor(2);
  
    //Normalizing to unity
    hq->Scale(1/hq->Integral());
    hg->Scale(1/hg->Integral());
    
    TH1F *sum = (TH1F*)hq->Clone();
    sum->Add(hg);
    
    TH1F *diff = (TH1F*)hq->Clone();
    diff->Add(hg,-1);
    
    //Squaring the difference of the two hists
    for (int i = 1; i <= diff->GetNbinsX(); i++) {
      diff->SetBinContent(i,diff->GetBinContent(i)*diff->GetBinContent(i));
    }
    
    diff->Divide(sum);
    double separation_power = 0.5*diff->Integral();

    separation_power_by_dR->Fill(dRlow,separation_power);
    
    TString sep; sep.Form("Separation Power = %.3f",separation_power);
    
    double max = hq->GetMaximum();
    if (hg->GetMaximum() > max) max = hg->GetMaximum();
    
    TCanvas *c = new TCanvas();
    hg->GetYaxis()->SetRangeUser(0,1.5*max);
    hg->GetXaxis()->SetTitle(xlabel);
    hg->GetYaxis()->SetTitle("a.u.");
    hg->Draw("hist");
    hq->Draw("histsame");
    TLegend leg(0.2,0.8,0.4,0.9);
    leg.SetLineColor(0);
    leg.SetFillStyle(0);    
    leg.SetTextSize(0.04);
    leg.SetShadowColor(0);
    leg.AddEntry(hq,"Quark Jets","l");
    leg.AddEntry(hg,"Gluon Jets","l");
    leg.Draw();
    TLatex l;
    l.SetNDC();
    l.SetTextSize(0.04);
    if (type == "dijets") l.DrawLatex(0.45,0.85,dijets_label);
    if (type == "zplusjets") l.DrawLatex(0.45,0.85,zplusjets_label);
    l.DrawLatex(0.45,0.8,dRrange);
    l.DrawLatex(0.45,0.75,sep);
    TString dRstring; dRstring.Form("dR_%.1f_%.1f_",dRlow,dRhigh);
    TString outname = "qjet_vs_gjet_"+var+"_"+dRstring+type+"_"+s;
    c->SaveAs(outname+".png");
    c->SaveAs(outname+".pdf");
    //   c->SaveAs(outname+".C");
  }

  TCanvas *c1 = new TCanvas();
  separation_power_by_dR->GetXaxis()->SetTitle("#DeltaR to Nearest Jet");
  separation_power_by_dR->GetYaxis()->SetTitle("Q/G Separation Power");
  if (type == "zplusjets") separation_power_by_dR->GetYaxis()->SetRangeUser(0,0.3);
  if (type == "dijets") separation_power_by_dR->GetYaxis()->SetRangeUser(0,0.4);
  separation_power_by_dR->Draw("pl");
  TLatex l1;
  l1.SetNDC();
  l1.SetTextSize(0.04);
  if (var == "ptD") {
    l1.DrawLatex(0.2,0.85,"Q/G Separation Power by #DeltaR for p_{T}^{D}");
  }
  else { 
    l1.DrawLatex(0.2,0.85,"Q/G Separation Power by #DeltaR for "+var);
  }
  if (type == "dijets") l1.DrawLatex(0.2,0.9,dijets_label);
  if (type == "zplusjets") l1.DrawLatex(0.2,0.9,zplusjets_label);
  c1->SaveAs("qjet_vs_gjet_"+var+"_sep_power_by_dR_"+s+".png");
  c1->SaveAs("qjet_vs_gjet_"+var+"_sep_power_by_dR_"+s+".pdf");
  //  c1->SaveAs("qjet_vs_gjet_"+var+"_sep_power_by_dR.eps");
  //  c1->SaveAs("qjet_vs_gjet_"+var+"_sep_power_by_dR.C");
    
}
