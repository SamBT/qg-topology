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
  TH1F *h_qjet_M = new TH1F("h_qjet_M","h_qjet_M",100,0,100);
  TH1F *h_qjet_multiplicity = new TH1F("h_qjet_multiplicity","h_qjet_multiplicity",70,0,70);
  TH1F *h_qjet_ptD = new TH1F("h_qjet_ptD","h_qjet_ptD",100,0,1);
  TH1F *h_qjet_LHA = new TH1F("h_qjet_LHA","h_qjet_LHA",100,0,1);
  TH1F *h_qjet_width = new TH1F("h_qjet_width","h_qjet_width",100,0,1);
  TH1F *h_qjet_mass = new TH1F("h_qjet_mass","h_qjet_mass",100,0,1);

  TH1F *h_gjet_njets = new TH1F("h_gjet_njets","h_gjet_njets",20,0,20);
  TH1F *h_gjet_pt = new TH1F("h_gjet_pt","h_gjet_pt",100,45,245);
  TH1F *h_gjet_eta = new TH1F("h_gjet_eta","h_gjet_eta",64,-6.4,6.4);
  TH1F *h_gjet_phi = new TH1F("h_gjet_phi","h_gjet_phi",70,0,7);
  TH1F *h_gjet_M = new TH1F("h_gjet_M","h_gjet_M",100,0,100);
  TH1F *h_gjet_multiplicity = new TH1F("h_gjet_multiplicity","h_gjet_multiplicity",70,0,70);
  TH1F *h_gjet_ptD = new TH1F("h_gjet_ptD","h_gjet_ptD",100,0,1);
  TH1F *h_gjet_LHA = new TH1F("h_gjet_LHA","h_gjet_LHA",100,0,1);
  TH1F *h_gjet_width = new TH1F("h_gjet_width","h_gjet_width",100,0,1);
  TH1F *h_gjet_mass = new TH1F("h_gjet_mass","h_gjet_mass",100,0,1);

  int default_nqjets = 0;
  int QCDa_nqjets = 0;
  int default_ngjets = 0;
  int QCDa_ngjets = 0;
  int default_Nneither = 0;
  int QCDa_Nneither = 0;
  int default_qjet_QCDa_qjet = 0;
  int default_qjet_QCDa_gjet = 0;
  int default_qjet_QCDa_neither = 0;
  int default_gjet_QCDa_qjet = 0;
  int default_gjet_QCDa_gjet = 0;
  int default_gjet_QCDa_neither= 0;
  int default_neither_QCDa_qjet = 0;
  int default_neither_QCDa_gjet = 0;
  int default_neither_QCDa_neither= 0;

  int problem_quarks = 0; int problem_gluons = 0;

  for( int i = 0 ; i < numev ; i ++ ) {	
    get_event(i);
    int max_index = 2;
    int nqjets_filled = 0; int ngjets_filled = 0;
    int QCDa_nqjets_filled = 0; int QCDa_ngjets_filled = 0;
    if (justLeading) max_index = 1;
    if (p->NJetsFilledSmallR == 0) continue;
    if (p->NJetsFilledSmallR == 1) max_index = 1;
    if (isHiggsBoosted && p->JsmallM->at(0) > 80) continue;
    

    h_njets->Fill(p->NJetsFilledSmallR);
    h_qjet_njets->Fill(p->NQjetsSmallR);
    h_gjet_njets->Fill(p->NGjetsSmallR);

    for (int n = 0; n < max_index; n++) {
      if (p->JsmallPt->at(n) < 50 || p->JsmallPt->at(n) > 150 || fabs(p->JsmallEta->at(n)) > 2.0) continue;
      
      /*if (p->QCDa_quark_or_gluon_by_index->at(n) == 1) QCDa_nqjets++;
      if (p->QCDa_quark_or_gluon_by_index->at(n) == 2) QCDa_ngjets++;
      if (p->QCDa_quark_or_gluon_by_index->at(n) == 0) QCDa_Nneither++;

      if (p->quark_or_gluon_by_index->at(n) == 1) default_nqjets++;
      if (p->quark_or_gluon_by_index->at(n) == 2) default_ngjets++;
      if (p->quark_or_gluon_by_index->at(n) == 0) default_Nneither++;*/
      //Collecting statistics on agreement of QCD-aware and default methods
      if (nqjets_filled+1 <= p->QjetPtSmallR->size() && p->QjetPtSmallR->at(nqjets_filled) == p->JsmallPt->at(n)) {
	default_nqjets++;
	nqjets_filled++;
	if (QCDa_nqjets_filled+1 <= p->QCDaQjetPtSmallR->size() && p->QCDaQjetPtSmallR->at(QCDa_nqjets_filled) == p->JsmallPt->at(n)) {QCDa_nqjets++; default_qjet_QCDa_qjet++; QCDa_nqjets_filled++;}
	else if (QCDa_ngjets_filled+1 <= p->QCDaGjetPtSmallR->size() && p->QCDaGjetPtSmallR->at(QCDa_ngjets_filled) == p->JsmallPt->at(n)) {QCDa_ngjets++; default_qjet_QCDa_gjet++; QCDa_ngjets_filled++;}
	else {QCDa_Nneither++; default_qjet_QCDa_neither++;}
      }
      else if (ngjets_filled+1 <= p->GjetPtSmallR->size() && p->GjetPtSmallR->at(ngjets_filled) == p->JsmallPt->at(n)) {
	default_ngjets++;
	ngjets_filled++;
        if (QCDa_nqjets_filled+1 <= p->QCDaQjetPtSmallR->size() && p->QCDaQjetPtSmallR->at(QCDa_nqjets_filled) == p->JsmallPt->at(n)) {QCDa_nqjets++; default_gjet_QCDa_qjet++; QCDa_nqjets_filled++;}
	else if (QCDa_ngjets_filled+1 <= p->QCDaGjetPtSmallR->size() && p->QCDaGjetPtSmallR->at(QCDa_ngjets_filled) == p->JsmallPt->at(n)) {QCDa_ngjets++; default_gjet_QCDa_gjet++; QCDa_ngjets_filled++;}
	else {QCDa_Nneither++; default_gjet_QCDa_neither++;}
      }
      else {
        default_Nneither++;
        if (QCDa_nqjets_filled+1 <= p->QCDaQjetPtSmallR->size() && p->QCDaQjetPtSmallR->at(QCDa_nqjets_filled) == p->JsmallPt->at(n)) {QCDa_nqjets++; default_neither_QCDa_qjet++; QCDa_nqjets_filled++;}
        else if (QCDa_ngjets_filled+1 <= p->QCDaGjetPtSmallR->size() && p->QCDaGjetPtSmallR->at(QCDa_ngjets_filled) == p->JsmallPt->at(n)) {QCDa_ngjets++; default_neither_QCDa_gjet++; QCDa_ngjets_filled++;}
        else {QCDa_Nneither++; default_neither_QCDa_neither++;}
      }

      if (p->QCDa_quark_or_gluon_by_index->at(n) != 1 && p->QCDa_quark_or_gluon_by_index->at(n) != 2 && p->QCDa_quark_or_gluon_by_index->at(n) != 0) cout << "bad thing" << endl;

      /*if (p->quark_or_gluon_by_index->at(n) == 1) {
	if (p->QjetPtSmallR->at(nqjets_filled) != p->JsmallPt->at(n)) problem_quarks++;
	h_qjet_pt->Fill(p->QjetPtSmallR->at(nqjets_filled));
        h_qjet_eta->Fill(p->QjetEtaSmallR->at(nqjets_filled));
        h_qjet_phi->Fill(p->QjetPhiSmallR->at(nqjets_filled));
        h_qjet_M->Fill(p->QjetMSmallR->at(nqjets_filled));
        h_qjet_multiplicity->Fill(p->QjetMultSmallR->at(nqjets_filled));
        h_qjet_ptD->Fill(p->QjetpTDSmallR->at(nqjets_filled));
        h_qjet_LHA->Fill(p->QjetLHASmallR->at(nqjets_filled));
        h_qjet_width->Fill(p->QjetWidthSmallR->at(nqjets_filled));
        h_qjet_mass->Fill(p->QjetMassSmallR->at(nqjets_filled));
	nqjets_filled += 1;
      }
      if (p->quark_or_gluon_by_index->at(n) == 2) {
	if (p->GjetPtSmallR->at(ngjets_filled) != p->JsmallPt->at(n)) problem_gluons++;
	h_gjet_pt->Fill(p->GjetPtSmallR->at(ngjets_filled));
        h_gjet_eta->Fill(p->GjetEtaSmallR->at(ngjets_filled));
        h_gjet_phi->Fill(p->GjetPhiSmallR->at(ngjets_filled));
        h_gjet_M->Fill(p->GjetMSmallR->at(ngjets_filled));
        h_gjet_multiplicity->Fill(p->GjetMultSmallR->at(ngjets_filled));
        h_gjet_ptD->Fill(p->GjetpTDSmallR->at(ngjets_filled));
        h_gjet_LHA->Fill(p->GjetLHASmallR->at(ngjets_filled));
        h_gjet_width->Fill(p->GjetWidthSmallR->at(ngjets_filled));
        h_gjet_mass->Fill(p->GjetMassSmallR->at(ngjets_filled));
	ngjets_filled += 1;
	}*/
    }

  }
  
  cout << "Statistics of the sample:" << endl;

  cout << "There were " << problem_quarks << " problem qjets, and " << problem_gluons << " problem gjets" << endl;
  
  cout << "1.) The default tagger labeled " << default_nqjets << " quark jets, and QCD-aware labeled " << QCDa_nqjets << "." << endl;
  cout << "QCD-aware thought a default-tagged quark jet was a quark jet " << ((double)default_qjet_QCDa_qjet/default_nqjets)*100 << "% of the time, a gluon jet " << ((double)default_qjet_QCDa_gjet/default_nqjets)*100 << "% of the time, and neither " << ((double)default_qjet_QCDa_neither/default_nqjets)*100 << "% of the time" << endl;

  cout << "2.) The default tagger labeled " << default_ngjets << " gluon jets, and QCD-aware labeled " << QCDa_ngjets << "." << endl;
  cout << "QCD-aware thought a default-tagged gluon jet was a quark jet " << ((double)default_gjet_QCDa_qjet/default_ngjets)*100 << "% of the time, a gluon jet " << ((double)default_gjet_QCDa_gjet/default_ngjets)*100 << "% of the time, and neither " << ((double)default_gjet_QCDa_neither/default_ngjets)*100 << "% of the time" << endl;

  cout << "3.) The default tagger labeled " << default_Nneither << " jets as neither quark nor gluon, and QCD-aware labeled " << QCDa_Nneither << " jets as neither quark nor gluon." << endl;
  cout << "QCD-aware thought a default-tagged 'neither' jet was a quark jet " << ((double)default_neither_QCDa_qjet/default_Nneither)*100 << "% of the time, a gluon jet " << ((double)default_neither_QCDa_gjet/default_Nneither)*100 << "% of the time, and neither " << ((double)default_neither_QCDa_neither/default_Nneither)*100 << "% of the time" << endl;

  

  /*
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
  */
  return 0 ;
}







