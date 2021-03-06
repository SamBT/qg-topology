#include "analysis.hh"


int main (int argc, char **argv) {
  gROOT->ProcessLine(".x rootlogon.C");
  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();
  
  TChain *chain = new TChain("EventTree");
  chain->Add(argv[1]);

  cout << "Looping through " << argv[1] << endl;
  
  p = new EventTree(chain);
    
  int numev = p->fChain->GetEntries();

  TH1F *h_njets = new TH1F("h_njets","h_njets",20,0,20);
  TH1F *h_nbjets = new TH1F("h_nbjets","h_nbjets",20,0,20);
  TH1F *h_leading_pt = new TH1F("h_leading_pt","h_leading_pt",100,0,1000);

  TH1F *h_qjet_njets = new TH1F("h_qjet_njets","h_qjet_njets",20,0,20);
  TH1F *h_qjet_pt = new TH1F("h_qjet_pt","h_qjet_pt",100,0,200);
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
  TH1F *h_qjet_leading_pt = new TH1F("h_qjet_leading_pt","h_qjet_leading_pt",100,0,200);
  TH1F *h_qjet_subleading_multiplicity = new TH1F("h_qjet_subleading_multiplicity","h_qjet_subleading_multiplicity",70,0,70);
  TH1F *h_qjet_subleading_ptD = new TH1F("h_qjet_subleading_ptD","h_qjet_subleading_ptD",100,0,1);
  TH1F *h_qjet_subleading_LHA = new TH1F("h_qjet_subleading_LHA","h_qjet_subleading_LHA",100,0,1);
  TH1F *h_qjet_subleading_width = new TH1F("h_qjet_subleading_width","h_qjet_subleading_width",100,0,1);
  TH1F *h_qjet_subleading_mass = new TH1F("h_qjet_subleading_mass","h_qjet_subleading_mass",100,0,1);
  TH1F *h_qjet_subleading_eta = new TH1F("h_qjet_subleading_eta","h_qjet_subleading_eta",64,-6.4,6.4);
  TH1F *h_qjet_subleading_pt = new TH1F("h_qjet_subleading_pt","h_qjet_subleading_pt",100,0,200);

  TH1F *h_gjet_njets = new TH1F("h_gjet_njets","h_gjet_njets",20,0,20);
  TH1F *h_gjet_pt = new TH1F("h_gjet_pt","h_gjet_pt",100,0,200);
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
  TH1F *h_gjet_leading_pt = new TH1F("h_gjet_leading_pt","h_gjet_leading_pt",100,0,200);
  TH1F *h_gjet_subleading_multiplicity = new TH1F("h_gjet_subleading_multiplicity","h_gjet_subleading_multiplicity",70,0,70);
  TH1F *h_gjet_subleading_ptD = new TH1F("h_gjet_subleading_ptD","h_gjet_subleading_ptD",100,0,1);
  TH1F *h_gjet_subleading_LHA = new TH1F("h_gjet_subleading_LHA","h_gjet_subleading_LHA",100,0,1);
  TH1F *h_gjet_subleading_width = new TH1F("h_gjet_subleading_width","h_gjet_subleading_width",100,0,1);
  TH1F *h_gjet_subleading_mass = new TH1F("h_gjet_subleading_mass","h_gjet_subleading_mass",100,0,1);
  TH1F *h_gjet_subleading_eta = new TH1F("h_gjet_subleading_eta","h_gjet_subleading_eta",64,-6.4,6.4);
  TH1F *h_gjet_subleading_pt = new TH1F("h_gjet_subleading_pt","h_gjet_subleading_pt",100,0,200);

  int bad_counter = 0;

  TH1F *test_hist_q = new TH1F("test_hist_q","test_hist_q",100,0,1);

  for( int i = 0 ; i < numev ; i ++ ) {	
    get_event(i);
    int bjetcounter = 0;
    
    if (p->NJetsFilledSmallR == 0) continue;

    h_njets->Fill(p->NJetsFilledSmallR);
    h_leading_pt->Fill(p->JsmallPt->at(0));
    for (int i = 0; i < p->NJetsFilledSmallR; i++) {
      if (p->JsmallBtag->at(i)) bjetcounter += 1;
    }
    h_nbjets->Fill(bjetcounter);

    h_qjet_njets->Fill(p->NQjetsSmallR);
    h_gjet_njets->Fill(p->NGjetsSmallR);

    if (p->NQjetsSmallR + p->NGjetsSmallR != p->NJetsFilledSmallR) bad_counter += 1;

    double eta, phi, dR, dRmin;
    dRmin = 99999;

    for (int k = 0; k < p->NQjetsSmallR; k++) {
      test_hist_q->Fill(p->QjetLHASmallR_SD->at(k));
      if (p->QjetPtSmallR->at(k) < 20 || fabs(p->QjetEtaSmallR->at(k)) > 2.0) continue;
      h_qjet_pt->Fill(p->QjetPtSmallR_SD->at(k));
      h_qjet_eta->Fill(p->QjetEtaSmallR_SD->at(k));
      h_qjet_phi->Fill(p->QjetPhiSmallR_SD->at(k));
      h_qjet_M->Fill(p->QjetMSmallR_SD->at(k));
      h_qjet_multiplicity->Fill(p->QjetMultSmallR_SD->at(k));
      h_qjet_ptD->Fill(p->QjetpTDSmallR_SD->at(k));
      h_qjet_LHA->Fill(p->QjetLHASmallR_SD->at(k));
      h_qjet_width->Fill(p->QjetWidthSmallR_SD->at(k));
      h_qjet_mass->Fill(p->QjetMassSmallR_SD->at(k));

      if (k == 0) {
	h_qjet_leading_multiplicity->Fill(p->QjetMultSmallR_SD->at(k));
	h_qjet_leading_ptD->Fill(p->QjetpTDSmallR_SD->at(k));
	h_qjet_leading_LHA->Fill(p->QjetLHASmallR_SD->at(k));
	h_qjet_leading_width->Fill(p->QjetWidthSmallR_SD->at(k));
	h_qjet_leading_mass->Fill(p->QjetMassSmallR_SD->at(k));
	h_qjet_leading_eta->Fill(p->QjetEtaSmallR_SD->at(k));
	h_qjet_leading_pt->Fill(p->QjetPtSmallR_SD->at(k));
      }
      if (k == 1) {
	h_qjet_subleading_multiplicity->Fill(p->QjetMultSmallR_SD->at(k));
	h_qjet_subleading_ptD->Fill(p->QjetpTDSmallR_SD->at(k));
	h_qjet_subleading_LHA->Fill(p->QjetLHASmallR_SD->at(k));
	h_qjet_subleading_width->Fill(p->QjetWidthSmallR_SD->at(k));
	h_qjet_subleading_mass->Fill(p->QjetMassSmallR_SD->at(k));
	h_qjet_subleading_eta->Fill(p->QjetEtaSmallR_SD->at(k));
	h_qjet_subleading_pt->Fill(p->QjetPtSmallR_SD->at(k));
      }

      h_qjet_multiplicity_eta->Fill(p->QjetMultSmallR_SD->at(k),p->QjetEtaSmallR_SD->at(k));
      h_qjet_ptD_eta->Fill(p->QjetpTDSmallR_SD->at(k),p->QjetEtaSmallR_SD->at(k));
      h_qjet_LHA_eta->Fill(p->QjetLHASmallR_SD->at(k),p->QjetEtaSmallR_SD->at(k));
      h_qjet_width_eta->Fill(p->QjetWidthSmallR_SD->at(k),p->QjetEtaSmallR_SD->at(k));
      h_qjet_mass_eta->Fill(p->QjetMassSmallR_SD->at(k),p->QjetEtaSmallR_SD->at(k));
      
      eta = p->QjetEtaSmallR_SD->at(k);
      phi = p->QjetPhiSmallR_SD->at(k);
      dRmin = 999999;

      for (int l = 0; l < p->NJetsFilledSmallR; l++) {
	if (p->JsmallPt->at(l) < 20) continue;
        if (eta == p->JsmallEta->at(l) && phi == p->JsmallPhi->at(l)) continue;
        dR = sqrt( pow(eta - p->JsmallEta->at(l),2) + pow(phi - p->JsmallPhi->at(l),2) );
        if (dR < dRmin) dRmin = dR;
      }
      h_qjet_nearestjetdR->Fill(dRmin);
      h_qjet_multiplicity_nearestdR->Fill(p->QjetMultSmallR_SD->at(k),dRmin);
      h_qjet_ptD_nearestdR->Fill(p->QjetpTDSmallR_SD->at(k),dRmin);
      h_qjet_LHA_nearestdR->Fill(p->QjetLHASmallR_SD->at(k),dRmin);
      h_qjet_width_nearestdR->Fill(p->QjetWidthSmallR_SD->at(k),dRmin);
      h_qjet_mass_nearestdR->Fill(p->QjetMassSmallR_SD->at(k),dRmin);
    }

    for (int j = 0; j < p->NGjetsSmallR; j++) {
      if (p->GjetPtSmallR->at(j) < 20 || fabs(p->GjetEtaSmallR->at(j)) > 2.0) continue;
      h_gjet_pt->Fill(p->GjetPtSmallR_SD->at(j));
      h_gjet_eta->Fill(p->GjetEtaSmallR_SD->at(j));
      h_gjet_phi->Fill(p->GjetPhiSmallR_SD->at(j));
      h_gjet_M->Fill(p->GjetMSmallR_SD->at(j));
      h_gjet_multiplicity->Fill(p->GjetMultSmallR_SD->at(j));
      h_gjet_ptD->Fill(p->GjetpTDSmallR_SD->at(j));
      h_gjet_LHA->Fill(p->GjetLHASmallR_SD->at(j));
      h_gjet_width->Fill(p->GjetWidthSmallR_SD->at(j));
      h_gjet_mass->Fill(p->GjetMassSmallR_SD->at(j));
      
      if (j == 0) {
	h_gjet_leading_multiplicity->Fill(p->GjetMultSmallR_SD->at(j));
	h_gjet_leading_ptD->Fill(p->GjetpTDSmallR_SD->at(j));
	h_gjet_leading_LHA->Fill(p->GjetLHASmallR_SD->at(j));
	h_gjet_leading_width->Fill(p->GjetWidthSmallR_SD->at(j));
	h_gjet_leading_mass->Fill(p->GjetMassSmallR_SD->at(j));
	h_gjet_leading_eta->Fill(p->GjetEtaSmallR_SD->at(j));
	h_gjet_leading_pt->Fill(p->GjetPtSmallR_SD->at(j));
      }
      if (j == 1) {
	h_gjet_subleading_multiplicity->Fill(p->GjetMultSmallR_SD->at(j));
	h_gjet_subleading_ptD->Fill(p->GjetpTDSmallR_SD->at(j));
	h_gjet_subleading_LHA->Fill(p->GjetLHASmallR_SD->at(j));
	h_gjet_subleading_width->Fill(p->GjetWidthSmallR_SD->at(j));
	h_gjet_subleading_mass->Fill(p->GjetMassSmallR_SD->at(j));
	h_gjet_subleading_eta->Fill(p->GjetEtaSmallR_SD->at(j));
        h_gjet_subleading_pt->Fill(p->GjetPtSmallR_SD->at(j));
      }

      h_gjet_multiplicity_eta->Fill(p->GjetMultSmallR_SD->at(j),p->GjetEtaSmallR_SD->at(j));
      h_gjet_ptD_eta->Fill(p->GjetpTDSmallR_SD->at(j),p->GjetEtaSmallR_SD->at(j));
      h_gjet_LHA_eta->Fill(p->GjetLHASmallR_SD->at(j),p->GjetEtaSmallR_SD->at(j));
      h_gjet_width_eta->Fill(p->GjetWidthSmallR_SD->at(j),p->GjetEtaSmallR_SD->at(j));
      h_gjet_mass_eta->Fill(p->GjetMassSmallR_SD->at(j),p->GjetEtaSmallR_SD->at(j));

      eta = p->GjetEtaSmallR_SD->at(j);
      phi = p->GjetPhiSmallR_SD->at(j);
      dRmin = 999999;

      for (int l = 0; l < p->NJetsFilledSmallR; l++) {
	if (p->JsmallPt->at(l) < 20) continue;
        if (eta == p->JsmallEta->at(l) && phi == p->JsmallPhi->at(l)) continue;
        dR = sqrt( pow(eta - p->JsmallEta->at(l),2) + pow(phi - p->JsmallPhi->at(l),2) );
        if (dR < dRmin) dRmin = dR;
      }
      h_gjet_nearestjetdR->Fill(dRmin);
      h_gjet_multiplicity_nearestdR->Fill(p->GjetMultSmallR_SD->at(j),dRmin);
      h_gjet_ptD_nearestdR->Fill(p->GjetpTDSmallR_SD->at(j),dRmin);
      h_gjet_LHA_nearestdR->Fill(p->GjetLHASmallR_SD->at(j),dRmin);
      h_gjet_width_nearestdR->Fill(p->GjetWidthSmallR_SD->at(j),dRmin);
      h_gjet_mass_nearestdR->Fill(p->GjetMassSmallR_SD->at(j),dRmin);
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

  test_hist_q->Write();

  return 0 ;
}







