void quark_vs_gluon_angularity_by_eta(TString type, TString var, TString xlabel, int rebin) {
  TString filename;
  if (type == "dijets") filename = "/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_dijets_rewt.root";
  if (type == "zplusjets") filename = "/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output/Radius_04/output_zplusjets.root";
  
  TFile *f1 = TFile::Open(filename);

  TH2F *h2q = (TH2F*)f1->Get("h_qjet_"+var+"_eta");
  TH2F *h2g = (TH2F*)f1->Get("h_gjet_"+var+"_eta");

  h2q->RebinY(5);
  h2g->RebinY(5);

  double etalow, etahigh;

  TProfile *separation_power_by_eta = new TProfile("separation_power_by_eta","separation_power_by_eta",10,-2.5,2.5,0,1);
  
  for (int i = 1; i <= h2q->GetNbinsY(); i++) {
    
    TH1F *hq = (TH1F*)h2q->ProjectionX("hq",i,i);
    TH1F *hg = (TH1F*)h2g->ProjectionX("hg",i,i);
    etalow = h2q->GetYaxis()->GetBinLowEdge(i);
    etahigh = etalow + h2q->GetYaxis()->GetBinWidth(i);

    TString dRrange; dRrange.Form("%.1f < #eta < %.1f",etalow,etahigh);

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

    separation_power_by_eta->Fill(etalow,separation_power);
    
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
    if (type == "dijets") l.DrawLatex(0.45,0.85,"Dijets, p_{T}^{jet} > 20 GeV");
    if (type == "zplusjets") l.DrawLatex(0.45,0.85,"Z+jets, p_{T}^{jet} > 20 GeV");
    l.DrawLatex(0.45,0.8,dRrange);
    l.DrawLatex(0.45,0.75,sep);
    TString dRstring; dRstring.Form("eta_%.1f_%.1f_",etalow,etahigh);
    TString outname = "qjet_vs_gjet_"+var+"_"+dRstring+type;
    c->SaveAs(outname+".png");
    c->SaveAs(outname+".pdf");
  }

  TCanvas *c1 = new TCanvas();
  separation_power_by_eta->GetXaxis()->SetTitle("#eta");
  separation_power_by_eta->GetYaxis()->SetTitle("Q/G Separation Power");
  if (type == "zplusjets") separation_power_by_eta->GetYaxis()->SetRangeUser(0,0.3);
  if (type == "dijets") separation_power_by_eta->GetYaxis()->SetRangeUser(0,0.4);
  separation_power_by_eta->Draw("pl");
  TLatex l1;
  l1.SetNDC();
  l1.SetTextSize(0.04);
  if (var == "ptD") {
    l1.DrawLatex(0.2,0.85,"Q/G Separation Power by #eta for p_{T}^{D}");
  }
  else { 
    l1.DrawLatex(0.2,0.85,"Q/G Separation Power by #eta for "+var);
  }
  if (type == "dijets") l1.DrawLatex(0.2,0.9,"Dijets, p_{T}^{jet} > 20 GeV");
  if (type == "zplusjets") l1.DrawLatex(0.2,0.9,"Z+jets, p_{T}^{jet} > 20 GeV");
  c1->SaveAs("qjet_vs_gjet_"+var+"_sep_power_by_eta.png");
  c1->SaveAs("qjet_vs_gjet_"+var+"_sep_power_by_eta.pdf");
}
