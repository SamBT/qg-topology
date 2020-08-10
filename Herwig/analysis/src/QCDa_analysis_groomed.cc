#include "analysis.hh"


int main (int argc, char **argv) {
  gROOT->ProcessLine(".x rootlogon.C");
  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();
  
  TChain *chain = new TChain("EventTree");
  chain->Add(argv[1]);

  cout << "Looping through " << argv[1] << endl;

  TString str = argv[1];
  bool justLeading = false;
  bool isHiggsBoosted = false;
  if (str.Contains("Zplusjets") || str.Contains("qqbar2Zg") || str.Contains("gg2Hg")) justLeading = true;
  if (str.Contains("H2gg_boosted") || str.Contains("H2qqbar_boosted")) isHiggsBoosted = true;
  
  p = new EventTree(chain);

  int numev = p->fChain->GetEntries();

  TH1F *h_njets = new TH1F("h_njets","h_njets",20,0,20);

  TH1F *h_qjet_njets = new TH1F("h_qjet_njets","h_qjet_njets",20,0,20);
  TH1F *h_qjet_pt = new TH1F("h_qjet_pt","h_qjet_pt",100,45,245);
  TH1F *h_qjet_eta = new TH1F("h_qjet_eta","h_qjet_eta",64,-6.4,6.4);
  TH1F *h_qjet_phi = new TH1F("h_qjet_phi","h_qjet_phi",70,0,7);
  TH1F *h_qjet_M = new TH1F("h_qjet_M","h_qjet_M",400,0,40);
  TH1F *h_qjet_multiplicity = new TH1F("h_qjet_multiplicity","h_qjet_multiplicity",70,0,70);
  TH1F *h_qjet_ptD = new TH1F("h_qjet_ptD","h_qjet_ptD",100,0,1);
  TH1F *h_qjet_LHA = new TH1F("h_qjet_LHA","h_qjet_LHA",100,0,1);
  TH1F *h_qjet_width = new TH1F("h_qjet_width","h_qjet_width",100,0,1);
  TH1F *h_qjet_mass = new TH1F("h_qjet_mass","h_qjet_mass",100,0,1);

  TH1F *h_qjet_leading_multiplicity = new TH1F("h_qjet_leading_multiplicity","h_qjet_leading_multiplicity",70,0,70);
  TH1F *h_qjet_leading_ptD = new TH1F("h_qjet_leading_ptD","h_qjet_leading_ptD",100,0,1);
  TH1F *h_qjet_leading_LHA = new TH1F("h_qjet_leading_LHA","h_qjet_leading_LHA",100,0,1);
  TH1F *h_qjet_leading_width = new TH1F("h_qjet_leading_width","h_qjet_leading_width",100,0,1);
  TH1F *h_qjet_leading_mass = new TH1F("h_qjet_leading_mass","h_qjet_leading_mass",100,0,1);
  TH1F *h_qjet_leading_eta = new TH1F("h_qjet_leading_eta","h_qjet_leading_eta",64,-6.4,6.4);
  TH1F *h_qjet_leading_pt = new TH1F("h_qjet_leading_pt","h_qjet_leading_pt",100,45,245);
  TH1F *h_qjet_subleading_multiplicity = new TH1F("h_qjet_subleading_multiplicity","h_qjet_subleading_multiplicity",70,0,70);
  TH1F *h_qjet_subleading_ptD = new TH1F("h_qjet_subleading_ptD","h_qjet_subleading_ptD",100,0,1);
  TH1F *h_qjet_subleading_LHA = new TH1F("h_qjet_subleading_LHA","h_qjet_subleading_LHA",100,0,1);
  TH1F *h_qjet_subleading_width = new TH1F("h_qjet_subleading_width","h_qjet_subleading_width",100,0,1);
  TH1F *h_qjet_subleading_mass = new TH1F("h_qjet_subleading_mass","h_qjet_subleading_mass",100,0,1);
  TH1F *h_qjet_subleading_eta = new TH1F("h_qjet_subleading_eta","h_qjet_subleading_eta",64,-6.4,6.4);
  TH1F *h_qjet_subleading_pt = new TH1F("h_qjet_subleading_pt","h_qjet_subleading_pt",100,45,245);

  TH1F *h_gjet_njets = new TH1F("h_gjet_njets","h_gjet_njets",20,0,20);
  TH1F *h_gjet_pt = new TH1F("h_gjet_pt","h_gjet_pt",100,45,245);
  TH1F *h_gjet_eta = new TH1F("h_gjet_eta","h_gjet_eta",64,-6.4,6.4);
  TH1F *h_gjet_phi = new TH1F("h_gjet_phi","h_gjet_phi",70,0,7);
  TH1F *h_gjet_M = new TH1F("h_gjet_M","h_gjet_M",400,0,40);
  TH1F *h_gjet_multiplicity = new TH1F("h_gjet_multiplicity","h_gjet_multiplicity",70,0,70);
  TH1F *h_gjet_ptD = new TH1F("h_gjet_ptD","h_gjet_ptD",100,0,1);
  TH1F *h_gjet_LHA = new TH1F("h_gjet_LHA","h_gjet_LHA",100,0,1);
  TH1F *h_gjet_width = new TH1F("h_gjet_width","h_gjet_width",100,0,1);
  TH1F *h_gjet_mass = new TH1F("h_gjet_mass","h_gjet_mass",100,0,1);

  TH1F *h_gjet_leading_multiplicity = new TH1F("h_gjet_leading_multiplicity","h_gjet_leading_multiplicity",70,0,70);
  TH1F *h_gjet_leading_ptD = new TH1F("h_gjet_leading_ptD","h_gjet_leading_ptD",100,0,1);
  TH1F *h_gjet_leading_LHA = new TH1F("h_gjet_leading_LHA","h_gjet_leading_LHA",100,0,1);
  TH1F *h_gjet_leading_width = new TH1F("h_gjet_leading_width","h_gjet_leading_width",100,0,1);
  TH1F *h_gjet_leading_mass = new TH1F("h_gjet_leading_mass","h_gjet_leading_mass",100,0,1);
  TH1F *h_gjet_leading_eta = new TH1F("h_gjet_leading_eta","h_gjet_leading_eta",64,-6.4,6.4);
  TH1F *h_gjet_leading_pt = new TH1F("h_gjet_leading_pt","h_gjet_leading_pt",100,45,245);
  TH1F *h_gjet_subleading_multiplicity = new TH1F("h_gjet_subleading_multiplicity","h_gjet_subleading_multiplicity",70,0,70);
  TH1F *h_gjet_subleading_ptD = new TH1F("h_gjet_subleading_ptD","h_gjet_subleading_ptD",100,0,1);
  TH1F *h_gjet_subleading_LHA = new TH1F("h_gjet_subleading_LHA","h_gjet_subleading_LHA",100,0,1);
  TH1F *h_gjet_subleading_width = new TH1F("h_gjet_subleading_width","h_gjet_subleading_width",100,0,1);
  TH1F *h_gjet_subleading_mass = new TH1F("h_gjet_subleading_mass","h_gjet_subleading_mass",100,0,1);
  TH1F *h_gjet_subleading_eta = new TH1F("h_gjet_subleading_eta","h_gjet_subleading_eta",64,-6.4,6.4);
  TH1F *h_gjet_subleading_pt = new TH1F("h_gjet_subleading_pt","h_gjet_subleading_pt",100,45,245);

  for( int i = 0 ; i < numev ; i ++ ) {	
    get_event(i);
    int max_index = 2;
    int nqjets_filled = 0; int ngjets_filled = 0;
    if (justLeading) max_index = 1;
    if (p->NJetsFilledSmallR == 0) continue;
    if (p->QCDa_quark_or_gluon_by_index->size() == 0) continue;
    if (p->NJetsFilledSmallR == 1 || p->QCDa_quark_or_gluon_by_index->size() == 1) max_index = 1;
    if (isHiggsBoosted && p->JsmallM->at(0) > 80) continue;

    h_njets->Fill(p->NJetsFilledSmallR);
    h_qjet_njets->Fill(p->QCDaNQjetsSmallR);
    h_gjet_njets->Fill(p->QCDaNGjetsSmallR);

    for (int n = 0; n < max_index; n++) {
      if (p->JsmallPt->at(n) < 50 || fabs(p->JsmallEta->at(n)) > 2.0) continue;
      if (p->QCDa_quark_or_gluon_by_index->at(n) == 1 && nqjets_filled+1 <= p->QCDaNQjetsSmallR) {
	h_qjet_pt->Fill(p->QCDaQjetPtSmallR_SD->at(nqjets_filled));
        h_qjet_eta->Fill(p->QCDaQjetEtaSmallR_SD->at(nqjets_filled));
        h_qjet_phi->Fill(p->QCDaQjetPhiSmallR_SD->at(nqjets_filled));
        h_qjet_M->Fill(p->QCDaQjetMSmallR_SD->at(nqjets_filled));
        h_qjet_multiplicity->Fill(p->QCDaQjetMultSmallR_SD->at(nqjets_filled));
        h_qjet_ptD->Fill(p->QCDaQjetpTDSmallR_SD->at(nqjets_filled));
        h_qjet_LHA->Fill(p->QCDaQjetLHASmallR_SD->at(nqjets_filled));
        h_qjet_width->Fill(p->QCDaQjetWidthSmallR_SD->at(nqjets_filled));
        h_qjet_mass->Fill(p->QCDaQjetMassSmallR_SD->at(nqjets_filled));
	nqjets_filled += 1;
      }
      if (ngjets_filled+1 <= p->QCDaNGjetsSmallR && p->QCDaGjetPtSmallR->at(ngjets_filled) == p->JsmallPt->at(n)) {
	h_gjet_pt->Fill(p->QCDaGjetPtSmallR_SD->at(ngjets_filled));
        h_gjet_eta->Fill(p->QCDaGjetEtaSmallR_SD->at(ngjets_filled));
        h_gjet_phi->Fill(p->QCDaGjetPhiSmallR_SD->at(ngjets_filled));
        h_gjet_M->Fill(p->QCDaGjetMSmallR_SD->at(ngjets_filled));
        h_gjet_multiplicity->Fill(p->QCDaGjetMultSmallR_SD->at(ngjets_filled));
        h_gjet_ptD->Fill(p->QCDaGjetpTDSmallR_SD->at(ngjets_filled));
        h_gjet_LHA->Fill(p->QCDaGjetLHASmallR_SD->at(ngjets_filled));
        h_gjet_width->Fill(p->QCDaGjetWidthSmallR_SD->at(ngjets_filled));
        h_gjet_mass->Fill(p->QCDaGjetMassSmallR_SD->at(ngjets_filled));
	ngjets_filled += 1;
      }
    }

    for (int k = 0; k < p->QCDaNQjetsSmallR; k++) {
      if (p->QCDaQjetPtSmallR->at(k) < 50 || fabs(p->QCDaQjetEtaSmallR->at(k)) > 2.0) continue;
      if (k == 0) {
	h_qjet_leading_multiplicity->Fill(p->QCDaQjetMultSmallR_SD->at(k));
	h_qjet_leading_ptD->Fill(p->QCDaQjetpTDSmallR_SD->at(k));
	h_qjet_leading_LHA->Fill(p->QCDaQjetLHASmallR_SD->at(k));
	h_qjet_leading_width->Fill(p->QCDaQjetWidthSmallR_SD->at(k));
	h_qjet_leading_mass->Fill(p->QCDaQjetMassSmallR_SD->at(k));
	h_qjet_leading_eta->Fill(p->QCDaQjetEtaSmallR_SD->at(k));
	h_qjet_leading_pt->Fill(p->QCDaQjetPtSmallR_SD->at(k));
      }
      if (k == 1) {
	h_qjet_subleading_multiplicity->Fill(p->QCDaQjetMultSmallR_SD->at(k));
	h_qjet_subleading_ptD->Fill(p->QCDaQjetpTDSmallR_SD->at(k));
	h_qjet_subleading_LHA->Fill(p->QCDaQjetLHASmallR_SD->at(k));
	h_qjet_subleading_width->Fill(p->QCDaQjetWidthSmallR_SD->at(k));
	h_qjet_subleading_mass->Fill(p->QCDaQjetMassSmallR_SD->at(k));
	h_qjet_subleading_eta->Fill(p->QCDaQjetEtaSmallR_SD->at(k));
	h_qjet_subleading_pt->Fill(p->QCDaQjetPtSmallR_SD->at(k));
      }
    }

    for (int j = 0; j < p->QCDaNGjetsSmallR; j++) {
      if (p->QCDaGjetPtSmallR->at(j) < 50 || fabs(p->QCDaGjetEtaSmallR->at(j)) > 2.0) continue;
      if (j == 0) {
	h_gjet_leading_multiplicity->Fill(p->QCDaGjetMultSmallR_SD->at(j));
	h_gjet_leading_ptD->Fill(p->QCDaGjetpTDSmallR_SD->at(j));
	h_gjet_leading_LHA->Fill(p->QCDaGjetLHASmallR_SD->at(j));
	h_gjet_leading_width->Fill(p->QCDaGjetWidthSmallR_SD->at(j));
	h_gjet_leading_mass->Fill(p->QCDaGjetMassSmallR_SD->at(j));
	h_gjet_leading_eta->Fill(p->QCDaGjetEtaSmallR_SD->at(j));
	h_gjet_leading_pt->Fill(p->QCDaGjetPtSmallR_SD->at(j));
      }
      if (j == 1) {
	h_gjet_subleading_multiplicity->Fill(p->QCDaGjetMultSmallR_SD->at(j));
	h_gjet_subleading_ptD->Fill(p->QCDaGjetpTDSmallR_SD->at(j));
	h_gjet_subleading_LHA->Fill(p->QCDaGjetLHASmallR_SD->at(j));
	h_gjet_subleading_width->Fill(p->QCDaGjetWidthSmallR_SD->at(j));
	h_gjet_subleading_mass->Fill(p->QCDaGjetMassSmallR_SD->at(j));
	h_gjet_subleading_eta->Fill(p->QCDaGjetEtaSmallR_SD->at(j));
        h_gjet_subleading_pt->Fill(p->QCDaGjetPtSmallR_SD->at(j));
      }
    }    
  }
  
  TFile f("output.root","recreate");
  h_njets->Write();
  

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

  return 0 ;
}







