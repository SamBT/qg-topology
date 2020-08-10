void plot_dijets_fraction_njets(int njets) {
  TString rootname; rootname.Form("output_dijets_%ijets.root",njets);
  TFile *f = TFile::Open("/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/"+rootname);

  if (njets == 1) {
    TH1F *hq = (TH1F*)f->Get("h_q_fraction_ptcut");
    TH1F *hg = (TH1F*)f->Get("h_g_fraction_ptcut");
    
    hg->Add(hq);

    int nbins = hq->GetNbinsX();

    double pt[nbins+2];
    double y_q[nbins+2];
    double y_g[nbins+2];

    for (int i = 1; i <= nbins; i++) {
      pt[i] = hq->GetBinLowEdge(i);
      y_q[i] = hq->GetBinContent(i);
      y_g[i] = hg->GetBinContent(i);
    }
    pt[0] = pt[1];
    pt[nbins+1] = pt[nbins];
    y_q[0] = 0;
    y_q[nbins+1] = 0;
    y_g[0] = 0;
    y_g[nbins+1] = 0;
    

    TGraph *q = new TGraph(nbins+2,pt,y_q);
    TGraph *g = new TGraph(nbins+2,pt,y_g);

    q->SetFillColor(kBlue-9);
    g->SetFillColor(kRed-9);
    q->SetLineWidth(1);
    g->SetLineWidth(1);
    g->GetYaxis()->SetRangeUser(0,1);
    hq->GetXaxis()->SetTitle("p_{T} Cut on All Jets");
    hq->GetYaxis()->SetTitle("Fraction of Jets");
    hq->GetYaxis()->SetRangeUser(0,1.2);
    hq->GetXaxis()->SetRangeUser(15,200);

    q->SetMarkerSize(0.5);
    g->SetMarkerSize(0.5);

    TCanvas *c = new TCanvas();
    hq->Draw("axis");
    g->Draw("lpf");
    q->Draw("lpfsame");
    TLatex l;
    l.DrawLatex(20,1.1,"Dijets, 1 Jet");
    l.DrawLatex(pt[3],y_q[3] - 0.5*y_q[3],"Q");
    l.DrawLatex(pt[3],y_q[3]+0.5*(1-y_q[3]),"G");
    c->SaveAs("fractions_dijets_1jet.png");
    c->SaveAs("fractions_dijets_1jet.pdf");
  }
  if (njets == 2) {
    TH1F *hqq = (TH1F*)f->Get("h_qq_fraction_ptcut");
    TH1F *hgg = (TH1F*)f->Get("h_gg_fraction_ptcut");
    TH1F *hqg = (TH1F*)f->Get("h_qg_fraction_ptcut");
    

    hgg->Add(hqq); hgg->Add(hqg);
    
    hqg->Add(hqq);

    int nbins = hqq->GetNbinsX();

    double pt[nbins+2];
    double y_qq[nbins+2];
    double y_gg[nbins+2];
    double y_qg[nbins+2];

    for (int i = 1; i <= nbins; i++) {
      pt[i] = hqq->GetBinLowEdge(i);
      y_qq[i] = hqq->GetBinContent(i);
      y_qg[i] = hqg->GetBinContent(i);
      y_gg[i] = hgg->GetBinContent(i);
    }
    pt[0] = pt[1];
    pt[nbins+1] = pt[nbins];
    y_qq[0] = 0;
    y_qq[nbins+1] = 0;
    y_qg[0] = 0;
    y_qg[nbins+1] = 0;
    y_gg[0] = 0;
    y_gg[nbins+1] = 0;


    TGraph *qq = new TGraph(nbins+2,pt,y_qq);
    TGraph *qg = new TGraph(nbins+2,pt,y_qg);
    TGraph *gg = new TGraph(nbins+2,pt,y_gg);

    qq->SetFillColor(kBlue-9);
    qg->SetFillColor(kViolet-9);
    gg->SetFillColor(kRed-9);
    qq->SetLineWidth(1);
    qg->SetLineWidth(1);
    gg->SetLineWidth(1);
    hqq->GetXaxis()->SetTitle("p_{T} Cut on All Jets");
    hqq->GetYaxis()->SetTitle("Fraction of Jets");
    hqq->GetYaxis()->SetRangeUser(0,1.2);
    hqq->GetXaxis()->SetRangeUser(15,200);

    qq->SetMarkerSize(0.5);
    qg->SetMarkerSize(0.5);
    gg->SetMarkerSize(0.5);

    TCanvas *c = new TCanvas();
    hqq->Draw("axis");
    gg->Draw("lpf");
    qg->Draw("lpfsame");
    qq->Draw("lpfsame");
    TLatex l;
    l.DrawLatex(20,1.1,"Dijets, 2 jets");
    l.SetTextSize(0.04);
    l.DrawLatex(pt[3],y_qq[3] - 0.5*y_qq[3],"QQ");
    l.DrawLatex(pt[3],y_qq[3]+0.5*(y_qg[3]-y_qq[3]),"QG");
    l.DrawLatex(pt[3],y_qg[3]+0.5*(1-y_qg[3]),"GG");
    c->SaveAs("fractions_dijets_2jets.png");
    c->SaveAs("fractions_dijets_2jets.pdf");
  }
  if (njets == 3) {
    TH1F *hqqq = (TH1F*)f->Get("h_qqq_fraction_ptcut");
    TH1F *hggg = (TH1F*)f->Get("h_ggg_fraction_ptcut");
    TH1F *hqqg = (TH1F*)f->Get("h_qqg_fraction_ptcut");
    TH1F *hqgg = (TH1F*)f->Get("h_qgg_fraction_ptcut");


    hggg->Add(hqqq); hggg->Add(hqqg); hggg->Add(hqgg);
    
    hqgg->Add(hqqq); hqgg->Add(hqqg);

    hqqg->Add(hqqq);

    int nbins = hqqq->GetNbinsX();

    double pt[nbins+2];
    double y_qqq[nbins+2];
    double y_ggg[nbins+2];
    double y_qqg[nbins+2];
    double y_qgg[nbins+2];

    for (int i = 1; i <= nbins; i++) {
      pt[i] = hqqq->GetBinLowEdge(i);
      y_qqq[i] = hqqq->GetBinContent(i);
      y_qqg[i] = hqqg->GetBinContent(i);
      y_qgg[i] = hqgg->GetBinContent(i);
      y_ggg[i] = hggg->GetBinContent(i);
    }
    pt[0] = pt[1];
    pt[nbins+1] = pt[nbins];
    y_qqq[0] = 0;
    y_qqq[nbins+1] = 0;
    y_qqg[0] = 0;
    y_qqg[nbins+1] = 0;
    y_qgg[0] = 0;
    y_qgg[nbins+1] = 0;
    y_ggg[0] = 0;
    y_ggg[nbins+1] = 0;


    TGraph *qqq = new TGraph(nbins+2,pt,y_qqq);
    TGraph *qqg = new TGraph(nbins+2,pt,y_qqg);
    TGraph *qgg = new TGraph(nbins+2,pt,y_qgg);
    TGraph *ggg = new TGraph(nbins+2,pt,y_ggg);

    qqq->SetFillColor(kBlue-9);
    qqg->SetFillColor(kViolet-9);
    qgg->SetFillColor(kPink+1);
    ggg->SetFillColor(kRed-9);
    qqq->SetLineWidth(1);
    qqg->SetLineWidth(1);
    qgg->SetLineWidth(1);
    ggg->SetLineWidth(1);
    hqqq->GetXaxis()->SetTitle("p_{T} Cut on All Jets");
    hqqq->GetYaxis()->SetTitle("Fraction of Jets");
    hqqq->GetYaxis()->SetRangeUser(0,1.2);
    hqqq->GetXaxis()->SetRangeUser(15,200);

    qqq->SetMarkerSize(0.5);
    qqg->SetMarkerSize(0.5);
    qgg->SetMarkerSize(0.5);
    ggg->SetMarkerSize(0.5);

    TCanvas *c = new TCanvas();
    hqqq->Draw("axis");
    ggg->Draw("lpf");
    qgg->Draw("lpfsame");
    qqg->Draw("lpfsame");
    qqq->Draw("lpfsame");
    TLatex l;
    l.DrawLatex(20,1.1,"Dijets, 3 jets");
    l.SetTextSize(0.03);
    l.DrawLatex(pt[3],y_qqq[3] - 0.5*y_qqq[3],"QQQ");
    l.DrawLatex(pt[3],y_qqq[3]+0.5*(y_qqg[3]-y_qqq[3]),"QQG");
    l.DrawLatex(pt[3],y_qqg[3]+0.5*(y_qgg[3]-y_qqg[3]),"QGG");
    l.DrawLatex(pt[3],y_qgg[3]+0.5*(1-y_qgg[3]),"GGG");
    c->SaveAs("fractions_dijets_3jets.png");
    c->SaveAs("fractions_dijets_3jets.pdf");
  }
}
    
    
    
