#include "analysis.hh"


int main (int argc, char **argv) {
  gROOT->ProcessLine(".x rootlogon.C");
  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();
  
  TChain *chain = new TChain("EventTree");
  chain->Add(argv[3]);

  cout << "Looping through & reweighting " << argv[3] << endl;
  
  p = new EventTree(chain);
    
  int numev = p->fChain->GetEntries();

  TFile *fd, *fz;
  if (argv[1] == argv[2]) {
    fd = TFile::Open(argv[1]);
    fz = fd;
  }
  else {
    fd = TFile::Open(argv[1]);
    fz = TFile::Open(argv[2]);
  }

  TH1F *qjet_eta_denom = (TH1F*)fd->Get("h_qjet_eta");
  TH1F *qjet_pt_denom = (TH1F*)fd->Get("h_qjet_pt");
  TH1F *qjet_eta_num = (TH1F*)fz->Get("h_qjet_eta");
  TH1F *qjet_pt_num = (TH1F*)fz->Get("h_qjet_pt");  
  TH1F *gjet_eta_denom = (TH1F*)fd->Get("h_gjet_eta");
  TH1F *gjet_pt_denom = (TH1F*)fd->Get("h_gjet_pt");
  //
  TH1F *leading_qjet_eta_denom = (TH1F*)fd->Get("h_qjet_leading_eta");
  TH1F *leading_qjet_pt_denom = (TH1F*)fd->Get("h_qjet_leading_pt");
  TH1F *leading_qjet_eta_num = (TH1F*)fz->Get("h_qjet_leading_eta");
  TH1F *leading_qjet_pt_num = (TH1F*)fz->Get("h_qjet_leading_pt");
  TH1F *leading_gjet_eta_denom = (TH1F*)fd->Get("h_gjet_leading_eta");
  TH1F *leading_gjet_pt_denom = (TH1F*)fd->Get("h_gjet_leading_pt");
  //
  TH1F *subleading_qjet_eta_denom = (TH1F*)fd->Get("h_qjet_subleading_eta");
  TH1F *subleading_qjet_pt_denom = (TH1F*)fd->Get("h_qjet_subleading_pt");
  TH1F *subleading_qjet_eta_num = (TH1F*)fz->Get("h_qjet_subleading_eta");
  TH1F *subleading_qjet_pt_num = (TH1F*)fz->Get("h_qjet_subleading_pt");
  TH1F *subleading_gjet_eta_denom = (TH1F*)fd->Get("h_gjet_subleading_eta");
  TH1F *subleading_gjet_pt_denom = (TH1F*)fd->Get("h_gjet_subleading_pt");
  
  qjet_eta_denom->SetNameTitle("qjet_eta_denom","qjet_eta_denom");
  qjet_pt_denom->SetNameTitle("qjet_pt_denom","qjet_pt_denom");
  qjet_eta_num->SetNameTitle("qjet_eta_num","qjet_eta_num");
  qjet_pt_num->SetNameTitle("qjet_pt_num","qjet_pt_num");
  gjet_eta_denom->SetNameTitle("gjet_eta_denom","gjet_eta_denom");
  gjet_pt_denom->SetNameTitle("gjet_pt_denom","gjet_pt_denom");
  //
  leading_qjet_eta_denom->SetNameTitle("leading_qjet_eta_denom","leading_qjet_eta_denom");
  leading_qjet_pt_denom->SetNameTitle("leading_qjet_pt_denom","leading_qjet_pt_denom");
  leading_qjet_eta_num->SetNameTitle("leading_qjet_eta_num","leading_qjet_eta_num");
  leading_qjet_pt_num->SetNameTitle("leading_qjet_pt_num","leading_qjet_pt_num");
  leading_gjet_eta_denom->SetNameTitle("leading_gjet_eta_denom","leading_gjet_eta_denom");
  leading_gjet_pt_denom->SetNameTitle("leading_gjet_pt_denom","leading_gjet_pt_denom");
  //
  subleading_qjet_eta_denom->SetNameTitle("subleading_qjet_eta_denom","subleading_qjet_eta_denom");
  subleading_qjet_pt_denom->SetNameTitle("subleading_qjet_pt_denom","subleading_qjet_pt_denom");
  subleading_qjet_eta_num->SetNameTitle("subleading_qjet_eta_num","subleading_qjet_eta_num");
  subleading_qjet_pt_num->SetNameTitle("subleading_qjet_pt_num","subleading_qjet_pt_num");
  subleading_gjet_eta_denom->SetNameTitle("subleading_gjet_eta_denom","subleading_gjet_eta_denom");
  subleading_gjet_pt_denom->SetNameTitle("subleading_gjet_pt_denom","subleading_gjet_pt_denom");

  qjet_eta_denom->Scale(1/qjet_eta_denom->Integral());
  qjet_pt_denom->Scale(1/qjet_pt_denom->Integral());
  qjet_eta_num->Scale(1/qjet_eta_num->Integral());
  qjet_pt_num->Scale(1/qjet_pt_num->Integral());
  gjet_eta_denom->Scale(1/gjet_eta_denom->Integral());
  gjet_pt_denom->Scale(1/gjet_pt_denom->Integral());
  //
  leading_qjet_eta_denom->Scale(1/leading_qjet_eta_denom->Integral());
  leading_qjet_pt_denom->Scale(1/leading_qjet_pt_denom->Integral());
  leading_qjet_eta_num->Scale(1/leading_qjet_eta_num->Integral());
  leading_qjet_pt_num->Scale(1/leading_qjet_pt_num->Integral());
  leading_gjet_eta_denom->Scale(1/leading_gjet_eta_denom->Integral());
  leading_gjet_pt_denom->Scale(1/leading_gjet_pt_denom->Integral());
  //
  subleading_qjet_eta_denom->Scale(1/subleading_qjet_eta_denom->Integral());
  subleading_qjet_pt_denom->Scale(1/subleading_qjet_pt_denom->Integral());
  subleading_qjet_eta_num->Scale(1/subleading_qjet_eta_num->Integral());
  subleading_qjet_pt_num->Scale(1/subleading_qjet_pt_num->Integral());
  subleading_gjet_eta_denom->Scale(1/subleading_gjet_eta_denom->Integral());
  subleading_gjet_pt_denom->Scale(1/subleading_gjet_pt_denom->Integral());
  
  TH1F *qjet_pt_wts = (TH1F*)qjet_pt_num->Clone();
  TH1F *qjet_eta_wts = (TH1F*)qjet_eta_num->Clone();
  TH1F *gjet_pt_wts = (TH1F*)qjet_pt_num->Clone();
  TH1F *gjet_eta_wts = (TH1F*)qjet_eta_num->Clone();
  //
  TH1F *leading_qjet_pt_wts = (TH1F*)leading_qjet_pt_num->Clone();
  TH1F *leading_qjet_eta_wts = (TH1F*)leading_qjet_eta_num->Clone();
  TH1F *leading_gjet_pt_wts = (TH1F*)leading_qjet_pt_num->Clone();
  TH1F *leading_gjet_eta_wts = (TH1F*)leading_qjet_eta_num->Clone();
  //
  TH1F *subleading_qjet_pt_wts = (TH1F*)subleading_qjet_pt_num->Clone();
  TH1F *subleading_qjet_eta_wts = (TH1F*)subleading_qjet_eta_num->Clone();
  TH1F *subleading_gjet_pt_wts = (TH1F*)subleading_qjet_pt_num->Clone();
  TH1F *subleading_gjet_eta_wts = (TH1F*)subleading_qjet_eta_num->Clone();

  qjet_pt_wts->SetNameTitle("qjet_pt_wts","qjet_pt_wts");
  qjet_eta_wts->SetNameTitle("qjet_eta_wts","qjet_eta_wts");
  gjet_pt_wts->SetNameTitle("gjet_pt_wts","gjet_pt_wts");
  gjet_eta_wts->SetNameTitle("gjet_eta_wts","gjet_eta_wts");
  //
  leading_qjet_pt_wts->SetNameTitle("leading_qjet_pt_wts","leading_qjet_pt_wts");
  leading_qjet_eta_wts->SetNameTitle("leading_qjet_eta_wts","leading_qjet_eta_wts");
  leading_gjet_pt_wts->SetNameTitle("leading_gjet_pt_wts","leading_gjet_pt_wts");
  leading_gjet_eta_wts->SetNameTitle("leading_gjet_eta_wts","leading_gjet_eta_wts");
  //
  subleading_qjet_pt_wts->SetNameTitle("subleading_qjet_pt_wts","subleading_qjet_pt_wts");
  subleading_qjet_eta_wts->SetNameTitle("subleading_qjet_eta_wts","subleading_qjet_eta_wts");
  subleading_gjet_pt_wts->SetNameTitle("subleading_gjet_pt_wts","subleading_gjet_pt_wts");
  subleading_gjet_eta_wts->SetNameTitle("subleading_gjet_eta_wts","subleading_gjet_eta_wts");

  qjet_pt_wts->Divide(qjet_pt_denom);
  qjet_eta_wts->Divide(qjet_eta_denom);
  gjet_pt_wts->Divide(gjet_pt_denom);
  gjet_eta_wts->Divide(gjet_eta_denom);
  //
  leading_qjet_pt_wts->Divide(leading_qjet_pt_denom);
  leading_qjet_eta_wts->Divide(leading_qjet_eta_denom);
  leading_gjet_pt_wts->Divide(leading_gjet_pt_denom);
  leading_gjet_eta_wts->Divide(leading_gjet_eta_denom);
  //
  subleading_qjet_pt_wts->Divide(subleading_qjet_pt_denom);
  subleading_qjet_eta_wts->Divide(subleading_qjet_eta_denom);
  subleading_gjet_pt_wts->Divide(subleading_gjet_pt_denom);
  subleading_gjet_eta_wts->Divide(subleading_gjet_eta_denom);

  TH1F *h_njets = new TH1F("h_njets","h_njets",20,0,20);
  TH1F *h_nbjets = new TH1F("h_nbjets","h_nbjets",20,0,20);
  TH1F *h_leading_pt = new TH1F("h_leading_pt","h_leading_pt",100,0,1000);

  TH1F *h_qjet_njets = new TH1F("h_qjet_njets","h_qjet_njets",20,0,20);
  TH1F *h_qjet_pt = new TH1F("h_qjet_pt","h_qjet_pt",100,200,400);
  TH1F *h_qjet_eta = new TH1F("h_qjet_eta","h_qjet_eta",64,-6.4,6.4);
  TH1F *h_qjet_phi = new TH1F("h_qjet_phi","h_qjet_phi",70,0,7);
  TH1F *h_qjet_M = new TH1F("h_qjet_M","h_qjet_M",400,0,40);
  TH1F *h_qjet_multiplicity = new TH1F("h_qjet_multiplicity","h_qjet_multiplicity",70,0,70);
  TH1F *h_qjet_ptD = new TH1F("h_qjet_ptD","h_qjet_ptD",100,0,1);
  TH1F *h_qjet_LHA = new TH1F("h_qjet_LHA","h_qjet_LHA",100,0,1);
  TH1F *h_qjet_width = new TH1F("h_qjet_width","h_qjet_width",100,0,1);
  TH1F *h_qjet_mass = new TH1F("h_qjet_mass","h_qjet_mass",100,0,1);
  TH1F *h_qjet_nearestjetdR = new TH1F("h_qjet_nearestjetdR","h_qjet_nearestjetdR",1000,0,10);
  TH2F *h_qjet_multiplicity_nearestdR = new TH2F("h_qjet_multiplicity_nearestdR","h_qjet_multiplicity_nearestdR",70,0,70,100,0,10);
  TH2F *h_qjet_ptD_nearestdR = new TH2F("h_qjet_ptD_nearestdR","h_qjet_ptD_nearestdR",100,0,1,100,0,10);
  TH2F *h_qjet_LHA_nearestdR = new TH2F("h_qjet_LHA_nearestdR","h_qjet_LHA_nearestdR",100,0,1,100,0,10);
  TH2F *h_qjet_width_nearestdR = new TH2F("h_qjet_width_nearestdR","h_qjet_width_nearestdR",100,0,1,100,0,10);
  TH2F *h_qjet_mass_nearestdR = new TH2F("h_qjet_mass_nearestdR","h_qjet_mass_nearestdR",100,0,1,100,0,10);
  TH2F *h_qjet_multiplicity_eta = new TH2F("h_qjet_multiplicity_eta","h_qjet_multiplicity_eta",70,0,70,50,-2.5,2.5);
  TH2F *h_qjet_ptD_eta = new TH2F("h_qjet_ptD_eta","h_qjet_ptD_eta",100,0,1,50,-2.5,2.5);
  TH2F *h_qjet_LHA_eta = new TH2F("h_qjet_LHA_eta","h_qjet_LHA_eta",100,0,1,50,-2.5,2.5);
  TH2F *h_qjet_width_eta = new TH2F("h_qjet_width_eta","h_qjet_width_eta",100,0,1,50,-2.5,2.5);
  TH2F *h_qjet_mass_eta = new TH2F("h_qjet_mass_eta","h_qjet_mass_eta",100,0,1,50,-2.5,2.5);

  TH1F *h_qjet_leading_multiplicity = new TH1F("h_qjet_leading_multiplicity","h_qjet_leading_multiplicity",70,0,70);
  TH1F *h_qjet_leading_ptD = new TH1F("h_qjet_leading_ptD","h_qjet_leading_ptD",100,0,1);
  TH1F *h_qjet_leading_LHA = new TH1F("h_qjet_leading_LHA","h_qjet_leading_LHA",100,0,1);
  TH1F *h_qjet_leading_width = new TH1F("h_qjet_leading_width","h_qjet_leading_width",100,0,1);
  TH1F *h_qjet_leading_mass = new TH1F("h_qjet_leading_mass","h_qjet_leading_mass",100,0,1);
  TH1F *h_qjet_leading_eta = new TH1F("h_qjet_leading_eta","h_qjet_leading_eta",64,-6.4,6.4);
  TH1F *h_qjet_leading_pt = new TH1F("h_qjet_leading_pt","h_qjet_leading_pt",100,200,400);
  TH1F *h_qjet_subleading_multiplicity = new TH1F("h_qjet_subleading_multiplicity","h_qjet_subleading_multiplicity",70,0,70);
  TH1F *h_qjet_subleading_ptD = new TH1F("h_qjet_subleading_ptD","h_qjet_subleading_ptD",100,0,1);
  TH1F *h_qjet_subleading_LHA = new TH1F("h_qjet_subleading_LHA","h_qjet_subleading_LHA",100,0,1);
  TH1F *h_qjet_subleading_width = new TH1F("h_qjet_subleading_width","h_qjet_subleading_width",100,0,1);
  TH1F *h_qjet_subleading_mass = new TH1F("h_qjet_subleading_mass","h_qjet_subleading_mass",100,0,1);
  TH1F *h_qjet_subleading_eta = new TH1F("h_qjet_subleading_eta","h_qjet_subleading_eta",64,-6.4,6.4);
  TH1F *h_qjet_subleading_pt = new TH1F("h_qjet_subleading_pt","h_qjet_subleading_pt",100,200,400);

  TH1F *h_gjet_njets = new TH1F("h_gjet_njets","h_gjet_njets",20,0,20);
  TH1F *h_gjet_pt = new TH1F("h_gjet_pt","h_gjet_pt",100,200,400);
  TH1F *h_gjet_eta = new TH1F("h_gjet_eta","h_gjet_eta",64,-6.4,6.4);
  TH1F *h_gjet_phi = new TH1F("h_gjet_phi","h_gjet_phi",70,0,7);
  TH1F *h_gjet_M = new TH1F("h_gjet_M","h_gjet_M",400,0,40);
  TH1F *h_gjet_multiplicity = new TH1F("h_gjet_multiplicity","h_gjet_multiplicity",70,0,70);
  TH1F *h_gjet_ptD = new TH1F("h_gjet_ptD","h_gjet_ptD",100,0,1);
  TH1F *h_gjet_LHA = new TH1F("h_gjet_LHA","h_gjet_LHA",100,0,1);
  TH1F *h_gjet_width = new TH1F("h_gjet_width","h_gjet_width",100,0,1);
  TH1F *h_gjet_mass = new TH1F("h_gjet_mass","h_gjet_mass",100,0,1);
  TH1F *h_gjet_nearestjetdR = new TH1F("h_gjet_nearestjetdR","h_gjet_nearestjetdR",1000,0,10);
  TH2F *h_gjet_multiplicity_nearestdR = new TH2F("h_gjet_multiplicity_nearestdR","h_gjet_multiplicity_nearestdR",70,0,70,100,0,10);
  TH2F *h_gjet_ptD_nearestdR = new TH2F("h_gjet_ptD_nearestdR","h_gjet_ptD_nearestdR",100,0,1,100,0,10);
  TH2F *h_gjet_LHA_nearestdR = new TH2F("h_gjet_LHA_nearestdR","h_gjet_LHA_nearestdR",100,0,1,100,0,10);
  TH2F *h_gjet_width_nearestdR = new TH2F("h_gjet_width_nearestdR","h_gjet_width_nearestdR",100,0,1,100,0,10);
  TH2F *h_gjet_mass_nearestdR = new TH2F("h_gjet_mass_nearestdR","h_gjet_mass_nearestdR",100,0,1,100,0,10);
  TH2F *h_gjet_multiplicity_eta = new TH2F("h_gjet_multiplicity_eta","h_gjet_multiplicity_eta",70,0,70,50,-2.5,2.5);
  TH2F *h_gjet_ptD_eta = new TH2F("h_gjet_ptD_eta","h_gjet_ptD_eta",100,0,1,50,-2.5,2.5);
  TH2F *h_gjet_LHA_eta = new TH2F("h_gjet_LHA_eta","h_gjet_LHA_eta",100,0,1,50,-2.5,2.5);
  TH2F *h_gjet_width_eta = new TH2F("h_gjet_width_eta","h_gjet_width_eta",100,0,1,50,-2.5,2.5);
  TH2F *h_gjet_mass_eta = new TH2F("h_gjet_mass_eta","h_gjet_mass_eta",100,0,1,50,-2.5,2.5);

  TH1F *h_gjet_leading_multiplicity = new TH1F("h_gjet_leading_multiplicity","h_gjet_leading_multiplicity",70,0,70);
  TH1F *h_gjet_leading_ptD = new TH1F("h_gjet_leading_ptD","h_gjet_leading_ptD",100,0,1);
  TH1F *h_gjet_leading_LHA = new TH1F("h_gjet_leading_LHA","h_gjet_leading_LHA",100,0,1);
  TH1F *h_gjet_leading_width = new TH1F("h_gjet_leading_width","h_gjet_leading_width",100,0,1);
  TH1F *h_gjet_leading_mass = new TH1F("h_gjet_leading_mass","h_gjet_leading_mass",100,0,1);
  TH1F *h_gjet_leading_eta = new TH1F("h_gjet_leading_eta","h_gjet_leading_eta",64,-6.4,6.4);
  TH1F *h_gjet_leading_pt = new TH1F("h_gjet_leading_pt","h_gjet_leading_pt",100,200,400);
  TH1F *h_gjet_subleading_multiplicity = new TH1F("h_gjet_subleading_multiplicity","h_gjet_subleading_multiplicity",70,0,70);
  TH1F *h_gjet_subleading_ptD = new TH1F("h_gjet_subleading_ptD","h_gjet_subleading_ptD",100,0,1);
  TH1F *h_gjet_subleading_LHA = new TH1F("h_gjet_subleading_LHA","h_gjet_subleading_LHA",100,0,1);
  TH1F *h_gjet_subleading_width = new TH1F("h_gjet_subleading_width","h_gjet_subleading_width",100,0,1);
  TH1F *h_gjet_subleading_mass = new TH1F("h_gjet_subleading_mass","h_gjet_subleading_mass",100,0,1);
  TH1F *h_gjet_subleading_eta = new TH1F("h_gjet_subleading_eta","h_gjet_subleading_eta",64,-6.4,6.4);
  TH1F *h_gjet_subleading_pt = new TH1F("h_gjet_subleading_pt","h_gjet_subleading_pt",100,200,400);


  for( int i = 0 ; i < numev ; i ++ ) {	
    get_event(i);
    int bjetcounter = 0;

    double wt, wt_pt, wt_eta, leading_wt, leading_wt_pt, leading_wt_eta, subleading_wt, subleading_wt_pt, subleading_wt_eta;
    
    if (p->NJetsFilledSmallR == 0) continue;

    h_njets->Fill(p->NJetsFilledSmallR);
    h_leading_pt->Fill(p->JsmallPt->at(0));
    for (int i = 0; i < p->NJetsFilledSmallR; i++) {
      if (p->JsmallBtag->at(i)) bjetcounter += 1;
    }
    h_nbjets->Fill(bjetcounter);

    h_qjet_njets->Fill(p->NQjetsSmallR);
    h_gjet_njets->Fill(p->NGjetsSmallR);

    double eta, phi, dR, dRmin;
    dRmin = 99999;

    for (int k = 0; k < p->NQjetsSmallR; k++) {
      if (p->QjetPtSmallR->at(k) < 200 || p->QjetPtSmallR->at(k) > 400 || fabs(p->QjetEtaSmallR->at(k)) > 2.0) continue;

      for (int r = 1; r <= qjet_pt_denom->GetNbinsX(); r++) {
	if (p->QjetPtSmallR->at(k) > qjet_pt_denom->GetBinLowEdge(r) && p->QjetPtSmallR->at(k) < qjet_pt_denom->GetBinLowEdge(r) + qjet_pt_denom->GetBinWidth(r)) {
	  wt_pt = qjet_pt_wts->GetBinContent(r);
	  leading_wt_pt = leading_qjet_pt_wts->GetBinContent(r);
	  subleading_wt_pt = subleading_qjet_pt_wts->GetBinContent(r);
	  break;
	}
      }
      for (int r = 1; r <= qjet_eta_denom->GetNbinsX(); r++) {
	if (p->QjetEtaSmallR->at(k) > qjet_eta_denom->GetBinLowEdge(r) && p->QjetEtaSmallR->at(k) < qjet_eta_denom->GetBinLowEdge(r) + qjet_eta_denom->GetBinWidth(r)) {
	  wt_eta = qjet_eta_wts->GetBinContent(r);
	  leading_wt_eta = leading_qjet_eta_wts->GetBinContent(r);
	  subleading_wt_eta = subleading_qjet_eta_wts->GetBinContent(r);
	  break;
	}
      }
      wt = wt_pt*wt_eta;
      leading_wt = leading_wt_pt*leading_wt_eta;
      subleading_wt = subleading_wt_pt*subleading_wt_eta;

      if (k == 0) {
	h_qjet_leading_pt->Fill(p->QjetPtSmallR->at(k),leading_wt_pt);
	h_qjet_leading_eta->Fill(p->QjetEtaSmallR->at(k),leading_wt_eta);
	h_qjet_leading_multiplicity->Fill(p->QjetMultSmallR->at(k), leading_wt);
	h_qjet_leading_ptD->Fill(p->QjetpTDSmallR->at(k),leading_wt);
	h_qjet_leading_LHA->Fill(p->QjetLHASmallR->at(k),leading_wt);
	h_qjet_leading_width->Fill(p->QjetWidthSmallR->at(k),leading_wt);
	h_qjet_leading_mass->Fill(p->QjetMassSmallR->at(k),leading_wt);
      }
      if (k == 1) {
	h_qjet_subleading_pt->Fill(p->QjetPtSmallR->at(k),subleading_wt_pt);
	h_qjet_subleading_eta->Fill(p->QjetEtaSmallR->at(k),subleading_wt_eta);
	h_qjet_subleading_multiplicity->Fill(p->QjetMultSmallR->at(k),subleading_wt);
	h_qjet_subleading_ptD->Fill(p->QjetpTDSmallR->at(k),subleading_wt);
	h_qjet_subleading_LHA->Fill(p->QjetLHASmallR->at(k),subleading_wt);
	h_qjet_subleading_width->Fill(p->QjetWidthSmallR->at(k),subleading_wt);
	h_qjet_subleading_mass->Fill(p->QjetMassSmallR->at(k),subleading_wt);
      }

      h_qjet_pt->Fill(p->QjetPtSmallR->at(k),wt_pt);
      h_qjet_eta->Fill(p->QjetEtaSmallR->at(k),wt_eta);
      h_qjet_phi->Fill(p->QjetPhiSmallR->at(k),wt);
      h_qjet_M->Fill(p->QjetMSmallR->at(k),wt);
      h_qjet_multiplicity->Fill(p->QjetMultSmallR->at(k), wt);
      h_qjet_ptD->Fill(p->QjetpTDSmallR->at(k),wt);
      h_qjet_LHA->Fill(p->QjetLHASmallR->at(k),wt);
      h_qjet_width->Fill(p->QjetWidthSmallR->at(k),wt);
      h_qjet_mass->Fill(p->QjetMassSmallR->at(k),wt);

      h_qjet_multiplicity_eta->Fill(p->QjetMultSmallR->at(k),p->QjetEtaSmallR->at(k),wt);
      h_qjet_ptD_eta->Fill(p->QjetpTDSmallR->at(k),p->QjetEtaSmallR->at(k),wt);
      h_qjet_LHA_eta->Fill(p->QjetLHASmallR->at(k),p->QjetEtaSmallR->at(k),wt);
      h_qjet_width_eta->Fill(p->QjetWidthSmallR->at(k),p->QjetEtaSmallR->at(k),wt);
      h_qjet_mass_eta->Fill(p->QjetMassSmallR->at(k),p->QjetEtaSmallR->at(k),wt);

      eta = p->QjetEtaSmallR->at(k);
      phi = p->QjetPhiSmallR->at(k);
      dRmin = 999999;

      for (int l = 0; l < p->NJetsFilledSmallR; l++) {
	if (p->JsmallPt->at(l) < 20) continue;
        if (eta == p->JsmallEta->at(l) && phi == p->JsmallPhi->at(l)) continue;
        dR = sqrt( pow(eta - p->JsmallEta->at(l),2) + pow(phi - p->JsmallPhi->at(l),2) );
        if (dR < dRmin) dRmin = dR;
      }
      h_qjet_nearestjetdR->Fill(dRmin);
      h_qjet_multiplicity_nearestdR->Fill(p->QjetMultSmallR->at(k),dRmin,wt);
      h_qjet_ptD_nearestdR->Fill(p->QjetpTDSmallR->at(k),dRmin,wt);
      h_qjet_LHA_nearestdR->Fill(p->QjetLHASmallR->at(k),dRmin,wt);
      h_qjet_width_nearestdR->Fill(p->QjetWidthSmallR->at(k),dRmin,wt);
      h_qjet_mass_nearestdR->Fill(p->QjetMassSmallR->at(k),dRmin,wt);
    }

    for (int j = 0; j < p->NGjetsSmallR; j++) {
      if (p->GjetPtSmallR->at(j) < 200 || p->GjetPtSmallR->at(j) > 400 || fabs(p->GjetEtaSmallR->at(j)) > 2.0) continue;

      for (int r = 1; r <= gjet_pt_denom->GetNbinsX(); r++) {
        if (p->GjetPtSmallR->at(j) > gjet_pt_denom->GetBinLowEdge(r) && p->GjetPtSmallR->at(j) < gjet_pt_denom->GetBinLowEdge(r) + gjet_pt_denom->GetBinWidth(r)) {
          wt_pt = gjet_pt_wts->GetBinContent(r);
	  leading_wt_pt = leading_gjet_pt_wts->GetBinContent(r);
	  subleading_wt_pt = subleading_gjet_pt_wts->GetBinContent(r);
          break;
	}
      } 
      for (int r = 1; r <= gjet_eta_denom->GetNbinsX(); r++) {
        if (p->GjetEtaSmallR->at(j) > gjet_eta_denom->GetBinLowEdge(r) && p->GjetEtaSmallR->at(j) < gjet_eta_denom->GetBinLowEdge(r) + gjet_eta_denom->GetBinWidth(r)) {
	  wt_eta = gjet_eta_wts->GetBinContent(r);
	  leading_wt_eta = leading_gjet_eta_wts->GetBinContent(r);
	  subleading_wt_eta = subleading_gjet_eta_wts->GetBinContent(r);
          break;
        }
      }
      wt = wt_pt*wt_eta;
      leading_wt = leading_wt_pt*leading_wt_eta;
      subleading_wt = subleading_wt_pt*subleading_wt_eta;

      if (j == 0) {
	h_gjet_leading_pt->Fill(p->GjetPtSmallR->at(j),leading_wt_pt);
        h_gjet_leading_eta->Fill(p->GjetEtaSmallR->at(j),leading_wt_eta);
        h_gjet_leading_multiplicity->Fill(p->GjetMultSmallR->at(j), leading_wt);
        h_gjet_leading_ptD->Fill(p->GjetpTDSmallR->at(j),leading_wt);
        h_gjet_leading_LHA->Fill(p->GjetLHASmallR->at(j),leading_wt);
        h_gjet_leading_width->Fill(p->GjetWidthSmallR->at(j),leading_wt);
        h_gjet_leading_mass->Fill(p->GjetMassSmallR->at(j),leading_wt);
      } 
      if (j == 1) {
	h_gjet_subleading_pt->Fill(p->GjetPtSmallR->at(j),subleading_wt_pt);
        h_gjet_subleading_eta->Fill(p->GjetEtaSmallR->at(j),subleading_wt_eta);
        h_gjet_subleading_multiplicity->Fill(p->GjetMultSmallR->at(j),subleading_wt);
        h_gjet_subleading_ptD->Fill(p->GjetpTDSmallR->at(j),subleading_wt);
        h_gjet_subleading_LHA->Fill(p->GjetLHASmallR->at(j),subleading_wt);
        h_gjet_subleading_width->Fill(p->GjetWidthSmallR->at(j),subleading_wt);
        h_gjet_subleading_mass->Fill(p->GjetMassSmallR->at(j),subleading_wt);
      }

      h_gjet_pt->Fill(p->GjetPtSmallR->at(j),wt_pt);
      h_gjet_eta->Fill(p->GjetEtaSmallR->at(j),wt_eta);
      h_gjet_phi->Fill(p->GjetPhiSmallR->at(j),wt);
      h_gjet_M->Fill(p->GjetMSmallR->at(j),wt);
      h_gjet_multiplicity->Fill(p->GjetMultSmallR->at(j),wt);
      h_gjet_ptD->Fill(p->GjetpTDSmallR->at(j),wt);
      h_gjet_LHA->Fill(p->GjetLHASmallR->at(j),wt);
      h_gjet_width->Fill(p->GjetWidthSmallR->at(j),wt);
      h_gjet_mass->Fill(p->GjetMassSmallR->at(j),wt);

      h_gjet_multiplicity_eta->Fill(p->GjetMultSmallR->at(j),p->GjetEtaSmallR->at(j),wt);
      h_gjet_ptD_eta->Fill(p->GjetpTDSmallR->at(j),p->GjetEtaSmallR->at(j),wt);
      h_gjet_LHA_eta->Fill(p->GjetLHASmallR->at(j),p->GjetEtaSmallR->at(j),wt);
      h_gjet_width_eta->Fill(p->GjetWidthSmallR->at(j),p->GjetEtaSmallR->at(j),wt);
      h_gjet_mass_eta->Fill(p->GjetMassSmallR->at(j),p->GjetEtaSmallR->at(j),wt);

      eta = p->GjetEtaSmallR->at(j);
      phi = p->GjetPhiSmallR->at(j);
      dRmin = 999999;

      for (int l = 0; l < p->NJetsFilledSmallR; l++) {
	if (p->JsmallPt->at(l) < 20) continue;
        if (eta == p->JsmallEta->at(l) && phi == p->JsmallPhi->at(l)) continue;
        dR = sqrt( pow(eta - p->JsmallEta->at(l),2) + pow(phi - p->JsmallPhi->at(l),2) );
        if (dR < dRmin) dRmin = dR;
      }
      h_gjet_nearestjetdR->Fill(dRmin);
      h_gjet_multiplicity_nearestdR->Fill(p->GjetMultSmallR->at(j),dRmin,wt);
      h_gjet_ptD_nearestdR->Fill(p->GjetpTDSmallR->at(j),dRmin,wt);
      h_gjet_LHA_nearestdR->Fill(p->GjetLHASmallR->at(j),dRmin,wt);
      h_gjet_width_nearestdR->Fill(p->GjetWidthSmallR->at(j),dRmin,wt);
      h_gjet_mass_nearestdR->Fill(p->GjetMassSmallR->at(j),dRmin,wt);
    }
    
    
  }

  TFile f("output.root","recreate");
  h_nbjets->Write();
  h_njets->Write();
  h_leading_pt->Write();

  h_qjet_njets->Write();
  h_qjet_pt->Write();
  h_qjet_eta->Write();
  h_qjet_phi->Write();
  h_qjet_M->Write();
  h_qjet_multiplicity->Write();
  h_qjet_ptD->Write();
  h_qjet_LHA->Write();
  h_qjet_width->Write();
  h_qjet_mass->Write();
  h_qjet_nearestjetdR->Write();
  h_qjet_multiplicity_nearestdR->Write();
  h_qjet_ptD_nearestdR->Write();
  h_qjet_LHA_nearestdR->Write();
  h_qjet_width_nearestdR->Write();
  h_qjet_mass_nearestdR->Write();
  h_qjet_multiplicity_eta->Write();
  h_qjet_ptD_eta->Write();
  h_qjet_LHA_eta->Write();
  h_qjet_width_eta->Write();
  h_qjet_mass_eta->Write();
  
  h_qjet_leading_multiplicity->Write();
  h_qjet_leading_ptD->Write();
  h_qjet_leading_LHA->Write();
  h_qjet_leading_width->Write();
  h_qjet_leading_mass->Write();
  h_qjet_leading_pt->Write();
  h_qjet_leading_eta->Write();
  h_qjet_subleading_multiplicity->Write();
  h_qjet_subleading_ptD->Write();
  h_qjet_subleading_LHA->Write();
  h_qjet_subleading_width->Write();
  h_qjet_subleading_mass->Write();
  h_qjet_subleading_pt->Write();
  h_qjet_subleading_eta->Write();

  h_gjet_njets->Write();
  h_gjet_pt->Write();
  h_gjet_eta->Write();
  h_gjet_phi->Write();
  h_gjet_M->Write();
  h_gjet_multiplicity->Write();
  h_gjet_ptD->Write();
  h_gjet_LHA->Write();
  h_gjet_width->Write();
  h_gjet_mass->Write();
  h_gjet_nearestjetdR->Write();
  h_gjet_multiplicity_nearestdR->Write();
  h_gjet_ptD_nearestdR->Write();
  h_gjet_LHA_nearestdR->Write();
  h_gjet_width_nearestdR->Write();
  h_gjet_mass_nearestdR->Write();
  h_gjet_multiplicity_eta->Write();
  h_gjet_ptD_eta->Write();
  h_gjet_LHA_eta->Write();
  h_gjet_width_eta->Write();
  h_gjet_mass_eta->Write();

  h_gjet_leading_multiplicity->Write();
  h_gjet_leading_ptD->Write();
  h_gjet_leading_LHA->Write();
  h_gjet_leading_width->Write();
  h_gjet_leading_mass->Write();
  h_gjet_leading_pt->Write();
  h_gjet_leading_eta->Write();
  h_gjet_subleading_multiplicity->Write();
  h_gjet_subleading_ptD->Write();
  h_gjet_subleading_LHA->Write();
  h_gjet_subleading_width->Write();
  h_gjet_subleading_mass->Write();
  h_gjet_subleading_pt->Write();
  h_gjet_subleading_eta->Write();

  qjet_pt_wts->Write();
  qjet_eta_wts->Write();
  gjet_pt_wts->Write();
  gjet_eta_wts->Write();

  return 0 ;
}







