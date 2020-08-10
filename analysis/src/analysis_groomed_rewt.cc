#include "analysis.hh"


int main (int argc, char **argv) {
  gROOT->ProcessLine(".x rootlogon.C");
  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();
  
  TChain *chain = new TChain("EventTree");
  chain->Add(argv[3]);

  cout << "Looping through & re-weighting" << argv[3] << endl;

  TString str = argv[3];
  bool justLeading = false;
  bool isHiggsBoosted = false;
  if (str.Contains("Zplusjets") || str.Contains("qqbar2Zg") || str.Contains("gg2Hg")) justLeading = true;
  if (str.Contains("H2gg_boosted") || str.Contains("H2qqbar_boosted")) isHiggsBoosted = true;
  
  p = new EventTree(chain);
  int numev = p->fChain->GetEntries();

  //Preparing stuff for re-weighting
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
  qjet_eta_denom->SetNameTitle("qjet_eta_denom","qjet_eta_denom");
  qjet_pt_denom->SetNameTitle("qjet_pt_denom","qjet_pt_denom");
  qjet_eta_num->SetNameTitle("qjet_eta_num","qjet_eta_num");
  qjet_pt_num->SetNameTitle("qjet_pt_num","qjet_pt_num");
  gjet_eta_denom->SetNameTitle("gjet_eta_denom","gjet_eta_denom");
  gjet_pt_denom->SetNameTitle("gjet_pt_denom","gjet_pt_denom");
  qjet_eta_denom->Scale(1/qjet_eta_denom->Integral());
  qjet_pt_denom->Scale(1/qjet_pt_denom->Integral());
  qjet_eta_num->Scale(1/qjet_eta_num->Integral());
  qjet_pt_num->Scale(1/qjet_pt_num->Integral());
  gjet_eta_denom->Scale(1/gjet_eta_denom->Integral());
  gjet_pt_denom->Scale(1/gjet_pt_denom->Integral());
  
  TH1F *qjet_pt_wts = (TH1F*)qjet_pt_num->Clone();
  TH1F *qjet_eta_wts = (TH1F*)qjet_eta_num->Clone();
  TH1F *gjet_pt_wts = (TH1F*)qjet_pt_num->Clone();
  TH1F *gjet_eta_wts = (TH1F*)qjet_eta_num->Clone();
  qjet_pt_wts->SetNameTitle("qjet_pt_wts","qjet_pt_wts");
  qjet_eta_wts->SetNameTitle("qjet_eta_wts","qjet_eta_wts");
  gjet_pt_wts->SetNameTitle("gjet_pt_wts","gjet_pt_wts");
  gjet_eta_wts->SetNameTitle("gjet_eta_wts","gjet_eta_wts");
  qjet_pt_wts->Divide(qjet_pt_denom);
  qjet_eta_wts->Divide(qjet_eta_denom);
  gjet_pt_wts->Divide(gjet_pt_denom);
  gjet_eta_wts->Divide(gjet_eta_denom);


  //////////Defining Histos//////////

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
  TH1F *h_gjet_M = new TH1F("h_gjet_M","h_gjet_M",100,0,100);
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
    if (p->NJetsFilledSmallR ==1) max_index = 1;
    if (isHiggsBoosted && p->JsmallM->at(0) > 80) continue;

    h_njets->Fill(p->NJetsFilledSmallR);
    h_qjet_njets->Fill(p->NQjetsSmallR);
    h_gjet_njets->Fill(p->NGjetsSmallR);
    
    double wt_pt, wt_eta, wt;

    for (int n = 0; n < max_index; n++) {
      if (p->JsmallPt->at(n) < 50 || p->JsmallPt->at(n) > 150 || fabs(p->JsmallEta->at(n)) > 2.0) continue;
      if (p->quark_or_gluon_by_index->at(n) == 1) {
	wt_pt = qjet_pt_wts->GetBinContent(qjet_pt_denom->GetXaxis()->FindBin(p->QjetPtSmallR->at(nqjets_filled)));
	wt_eta = qjet_eta_wts->GetBinContent(qjet_eta_denom->GetXaxis()->FindBin(p->QjetEtaSmallR->at(nqjets_filled)));
	wt = wt_pt*wt_eta;
	
	h_qjet_pt->Fill(p->QjetPtSmallR_SD->at(nqjets_filled),wt_pt);
        h_qjet_eta->Fill(p->QjetEtaSmallR_SD->at(nqjets_filled),wt_eta);
        h_qjet_phi->Fill(p->QjetPhiSmallR_SD->at(nqjets_filled),wt);
        h_qjet_M->Fill(p->QjetMSmallR_SD->at(nqjets_filled),wt);
        h_qjet_multiplicity->Fill(p->QjetMultSmallR_SD->at(nqjets_filled),wt);
        h_qjet_ptD->Fill(p->QjetpTDSmallR_SD->at(nqjets_filled),wt);
        h_qjet_LHA->Fill(p->QjetLHASmallR_SD->at(nqjets_filled),wt);
        h_qjet_width->Fill(p->QjetWidthSmallR_SD->at(nqjets_filled),wt);
        h_qjet_mass->Fill(p->QjetMassSmallR_SD->at(nqjets_filled),wt);
	nqjets_filled += 1;
      }
      if (p->quark_or_gluon_by_index->at(n) == 2) {
	wt_pt = gjet_pt_wts->GetBinContent(gjet_pt_denom->GetXaxis()->FindBin(p->GjetPtSmallR->at(ngjets_filled)));
	wt_eta = gjet_eta_wts->GetBinContent(gjet_eta_denom->GetXaxis()->FindBin(p->GjetEtaSmallR->at(ngjets_filled)));
	wt = wt_pt*wt_eta;

	h_gjet_pt->Fill(p->GjetPtSmallR_SD->at(ngjets_filled),wt_pt);
        h_gjet_eta->Fill(p->GjetEtaSmallR_SD->at(ngjets_filled),wt_eta);
        h_gjet_phi->Fill(p->GjetPhiSmallR_SD->at(ngjets_filled),wt);
        h_gjet_M->Fill(p->GjetMSmallR_SD->at(ngjets_filled),wt);
        h_gjet_multiplicity->Fill(p->GjetMultSmallR_SD->at(ngjets_filled),wt);
        h_gjet_ptD->Fill(p->GjetpTDSmallR_SD->at(ngjets_filled),wt);
        h_gjet_LHA->Fill(p->GjetLHASmallR_SD->at(ngjets_filled),wt);
        h_gjet_width->Fill(p->GjetWidthSmallR_SD->at(ngjets_filled),wt);
        h_gjet_mass->Fill(p->GjetMassSmallR_SD->at(ngjets_filled),wt);
	ngjets_filled += 1;
      }
    }

    for (int k = 0; k < p->NQjetsSmallR; k++) {
      if (p->QjetPtSmallR->at(k) < 50 || fabs(p->QjetEtaSmallR->at(k)) > 2.0) continue;
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
    }

    for (int j = 0; j < p->NGjetsSmallR; j++) {
      if (p->GjetPtSmallR->at(j) < 50 || fabs(p->GjetEtaSmallR->at(j)) > 2.0) continue;
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







