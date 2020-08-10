#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <set>


#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"
#include "TParticle.h"
#include "TDatabasePDG.h"
#include "TMath.h"
#include "TVector3.h"
#include "TRandom3.h"

#include "FCNCAnalysis.h"
#include "FCNCTools.h"
#include "helpers.hh"

#include "myFastJetBase.h"
#include "fastjet/ClusterSequence.hh"
#include "fastjet/PseudoJet.hh"  
#include "fastjet/tools/Filter.hh"
#include "fastjet/Selector.hh"
#include "fastjet/contrib/SoftDrop.hh"
#include "fastjet/contrib/QCDAwarePlugin.hh"
#include "fastjet/contrib/RecursiveSymmetryCutBase.hh"

#include "Pythia8/Pythia.h"

using namespace std;
using namespace fastjet;
using namespace fastjet::contrib::QCDAwarePlugin;


// Constructor 
FCNCAnalysis::FCNCAnalysis(double jet_radius, double minpt_jet){
    if(fDebug) cout << "FCNCAnalysis::FCNCAnalysis Start " << endl;
    ftest = 0;
    fDebug = false;
    fOutName = "test.root";
    tool = new FCNCTools();
    boosted_higgs_counter = 0;
    min_jet_pt = minpt_jet;

    // jet def 
    m_jet_def               = new fastjet::JetDefinition(fastjet::antikt_algorithm, jet_radius);
    m_jet_def_largeR_ALTAS  = new fastjet::JetDefinition(fastjet::antikt_algorithm, 1.0);
    m_jet_def_cam = new fastjet::JetDefinition(fastjet::cambridge_algorithm, m_jet_def->R());

    if(fDebug) cout << "FCNCAnalysis::FCNCAnalysis End " << endl;
}

// Destructor 
FCNCAnalysis::~FCNCAnalysis(){
    delete tool;
    delete m_jet_def;
    delete m_jet_def_largeR_ALTAS;
}

// Begin method
void FCNCAnalysis::Begin(){
   // Declare TTree
   tF = new TFile(fOutName.c_str(), "RECREATE");
   tT = new TTree("EventTree", "Event Tree for FCNC");
    
   DeclareBranches();
   ResetBranches();
   

   return;
}

// End
void FCNCAnalysis::End(){
    
    tT->Write();
    tF->Close();
    cout << "There were " << boosted_higgs_counter << " events having a higgs with p > m" << endl;
    return;
}

// Analyze
void FCNCAnalysis::AnalyzeEvent(int ievt, Pythia8::Pythia* pythia8){
    if(fDebug) cout << "FCNCAnalysis::AnalyzeEvent Begin " << endl;

    // -------------------------
    if (!pythia8->next()) return;
    if(fDebug) cout << "FCNCAnalysis::AnalyzeEvent Event Number " << ievt << endl;

    // reset branches 
    ResetBranches();
    
    // new event-----------------------
    fTEventNumber = ievt;
    std::vector <fastjet::PseudoJet>           particlesForJets;
    std::vector <fastjet::PseudoJet>           partonsForJets;

    vector<int> W1_daughters;
    vector<int> W2_daughters;
    double METpx=0.;
    double METpy=0.;

    std::vector <fastjet::PseudoJet>           bhadrons;
    std::vector <fastjet::PseudoJet>           chadrons;
    std::vector <fastjet::PseudoJet>           HS;

    int mode = -1;
    vector<fastjet::PseudoJet> higgs_quarks;
    vector<fastjet::PseudoJet> higgs_gluons;
    vector<int> finalPartonIndices;
    vector<int> HiggsIndices;
    int HiggsIndex = -999;
    int daughter_id;
    //double min_jet_pt = 200;
    bool uncounted = true;
    int Zboson_index = -1;
    fastjet::PseudoJet Zboson;

    //std::cout << "weights! " << pythia8->info.weight(0) << " " << pythia8->info.weight(1) << std::endl;

    // Particle loop -----------------------------------------------------------
    for (unsigned int ip=0; ip<pythia8->event.size(); ++ip){

      fastjet::PseudoJet p(pythia8->event[ip].px(), pythia8->event[ip].py(), pythia8->event[ip].pz(),pythia8->event[ip].e());
      p.set_user_info(new MyUserInfo(pythia8->event[ip].id(),ip,pythia8->event[ip].charge()));
      p.set_user_index(pythia8->event[ip].id());

      if (pythia8->event[ip].id() == 23) {Zboson_index = ip; Zboson = p;}

      if (HiggsTagger && pythia8->event[ip].id() == 25) {
	if (uncounted && sqrt(p.px()*p.px() + p.py()*p.py() + p.pz()*p.pz()) > p.m()) {uncounted = false; boosted_higgs_counter += 1;}
        HiggsIndices.push_back(ip);
        if (HiggsIndex == -999) HiggsIndex = ip;
      }
      if (pythia8->event[ip].isFinalPartonLevel()) finalPartonIndices.push_back(ip);
      if (!HiggsTagger && pythia8->event[ip].isFinalPartonLevel()) partonsForJets.push_back(p);

      if (tool->IsBHadron(pythia8->event[ip].id())){
	bhadrons.push_back(p);
      }

      if (pythia8->event[ip].id() == 25) {
	vector<int> children = pythia8->event[ip].daughterList();
	for (int y = 0; y < children.size(); y++) {
	  daughter_id = pythia8->event[children[y]].id();
	  fastjet::PseudoJet j(pythia8->event[children[y]].px(),pythia8->event[children[y]].py(),pythia8->event[children[y]].pz(),pythia8->event[children[y]].e());
	  if (fabs(daughter_id) > 0 && fabs(daughter_id) <= 5) {
	    higgs_quarks.push_back(j);
	  }
	  if (daughter_id == 21) {
	    higgs_gluons.push_back(j);
	  }
	  higgs_products->Fill(pythia8->event[children[y]].id());
	}
      }

      // particles for jets --------------
      if (!pythia8->event[ip].isFinal() )      continue;
      if (fabs(pythia8->event[ip].id())  ==12) continue;
      if (fabs(pythia8->event[ip].id())  ==13) continue;
      if (fabs(pythia8->event[ip].id())  ==14) continue;
      if (fabs(pythia8->event[ip].id())  ==16) continue;

      particlesForJets.push_back(p);
      
    } // end particle loop -----------------------------------------------

    if (HiggsTagger) {
      for (int kk = 0; kk < finalPartonIndices.size(); kk++) {
	fastjet::PseudoJet parton(pythia8->event[finalPartonIndices[kk]].px(), pythia8->event[finalPartonIndices[kk]].py(), pythia8->event[finalPartonIndices[kk]].pz(),pythia8->event[finalPartonIndices[kk]].e());
	parton.set_user_info(new MyUserInfo(pythia8->event[finalPartonIndices[kk]].id(),finalPartonIndices[kk],pythia8->event[finalPartonIndices[kk]].charge()));
	parton.set_user_index(pythia8->event[finalPartonIndices[kk]].id());
	bool HiggsChild = false;
	/*	for (int rr = 0; rr < HiggsIndices.size(); rr++) {
	  if (pythia8->event[finalPartonIndices[kk]].isAncestor(HiggsIndices[rr])) HiggsChild = true;
	  }*/
	if (pythia8->event[finalPartonIndices[kk]].isAncestor(HiggsIndex)) HiggsChild = true;
	if (HiggsChild) partonsForJets.push_back(parton);
      }
    }

    //Using QCD-aware method to get flavor labeled parton jets, to which the hadron-level jets will be matched
    AntiKtMeasure *aktdm = new AntiKtMeasure(m_jet_def->R());
    QCDAwarePlugin *qcdawareakt = new QCDAwarePlugin(aktdm);
    ClusterSequence qcdawareaktcs(partonsForJets, qcdawareakt);
    vector<fastjet::PseudoJet> aktPartonJets = sorted_by_pt(qcdawareaktcs.inclusive_jets(min_jet_pt));

    // small R jets: ATLAS Style ------------------------------------------
    fastjet::ClusterSequence cs(particlesForJets, *m_jet_def);
    vector<fastjet::PseudoJet> myJets = fastjet::sorted_by_pt(cs.inclusive_jets(min_jet_pt)); 
    int nbjets = 0;
    TRandom3 *rand = new TRandom3(0);
    vector<int> used_indices;
    vector<fastjet::PseudoJet> qjets, gjets;
    for (unsigned int ij = 0; ij < myJets.size(); ij++){
        if(fTNJetsSmallRFilled == MaxNJetSmallR) {cout << "Warning: More than " << MaxNJetSmallR << " small R jets" << endl; continue;}
        if(myJets[ij].pt() < min_jet_pt) continue;
        fTJsmallPt.push_back(myJets[ij].pt());
        fTJsmallEta.push_back(myJets[ij].eta());
        fTJsmallPhi.push_back(myJets[ij].phi());
        fTJsmallM.push_back(myJets[ij].m());
	fTJsmallBtag.push_back(tool->Btag(myJets[ij],bhadrons,chadrons,m_jet_def->R(),1.,1000000000,1000000000));
	fTJsmallTrackMass.push_back(tool->JetTrackMass(myJets[ij],1));
	fTJsmallTrackpT.push_back(tool->JetTrackMass(myJets[ij],2));
	fTJsmallTrackMassR.push_back(tool->JetTrackMass(myJets[ij],-1));
        fTJsmallTrackpTR.push_back(tool->JetTrackMass(myJets[ij],-2));
	fTsmallntrack.push_back(tool->JetTrackMass(myJets[ij],3));
	fTsmallntrackR.push_back(tool->JetTrackMass(myJets[ij],-3));
	nbjets+=fTJsmallBtag[fTNJetsSmallRFilled];
	fTNJetsSmallRFilled++;

	bool isquarkjet = false;
	bool isgluonjet = false;
	bool iscbt = false;
	fastjet::PseudoJet loop_parton;
	double dR, E_parton, z_i, theta_i, mult, ptD, LHA, width, mass, sum_constituent_pt, mult_sd, ptD_sd, LHA_sd, width_sd, mass_sd;
	E_parton = 0; z_i = 0; theta_i = 0; mult = 0; ptD = 0; LHA = 0; width = 0; mass = 0; sum_constituent_pt = 0;
	int parton_id;
	double min_parton_E = 0;

	// Loop through all truth-level particles in event; match partons (quarks or gluons) to jet by dR < radius
	// If highest energy parton inside jet cone is a quark, then we call it a quark jet; if gluon, call it a gluon jet
	if (!HiggsTagger) {
	  int index = -1;
	  for (unsigned int k = 0; k < pythia8->event.size(); k++) {
	    if (std::find(used_indices.begin(), used_indices.end(), k) != used_indices.end()) continue;
	    parton_id = pythia8->event[k].id();
	    if (fabs(parton_id) != 21 && fabs(parton_id) > 5) continue;
	    loop_parton = fastjet::PseudoJet(pythia8->event[k].px(), pythia8->event[k].py(), pythia8->event[k].pz(), pythia8->event[k].e());
	    dR = loop_parton.delta_R(myJets[ij]);
	    if (dR < m_jet_def->R() && loop_parton.e() > E_parton && loop_parton.e() > min_parton_E) {
	      index = k;
	      E_parton = loop_parton.e();
	      if (parton_id != 21) {
		if (parton_id == 4 || parton_id == 5) {
		  iscbt = true;
		}
		else {
		  iscbt = false;
		}
		isquarkjet = true;
		isgluonjet = false;
	      }
	      if (parton_id == 21) {
		isquarkjet = false;
		isgluonjet = true;
	      }
	    }
	  }
	  if (index != -1) used_indices.push_back(index);
	}
	if (HiggsTagger) {
	  int remove = -1;
	  for (unsigned int t = 0; t < partonsForJets.size(); t++) {
	    PseudoJet ptn = partonsForJets[t]; int ptn_id = ptn.user_index();
	    if (ptn.delta_R(myJets[ij]) < m_jet_def->R() && ptn.e() > E_parton && std::find(used_indices.begin(),used_indices.end(),t) == used_indices.end()) {
	      if (fabs(ptn_id) <= 5 && ptn_id != 0) {
		isquarkjet = true;
		isgluonjet = false;
		if (ptn_id == 4 || ptn_id == 5) {iscbt = true;}
		else {iscbt = false;}
		E_parton = ptn.e();
		remove = t;
	      }
	      if (ptn_id == 21) {
		isquarkjet = false;
		isgluonjet = true;
		E_parton = ptn.e();
		remove = t;
	      }
	    }
	  }
	  if (remove != -1) used_indices.push_back(remove);
	}

	mult = Angularity(0,0,m_jet_def->R(),myJets[ij]);
        ptD = Angularity(2,0,m_jet_def->R(),myJets[ij]);
        LHA = Angularity(1,0.5,m_jet_def->R(),myJets[ij]);
        width = Angularity(1,1,m_jet_def->R(),myJets[ij]);
        mass = Angularity(1,2,m_jet_def->R(),myJets[ij]);

	fastjet::ClusterSequence recluster_seq(myJets[ij].constituents(), *m_jet_def_cam);
	vector<fastjet::PseudoJet> myjet_reclustered = fastjet::sorted_by_pt(recluster_seq.inclusive_jets(0.));
	fastjet::contrib::SoftDrop sd(0.0, 0.1); //beta = 0, zcut = 0.1
	fastjet::PseudoJet mysoftdroppedjet = sd(myjet_reclustered[0]);
	mult_sd = Angularity(0,0,m_jet_def->R(),mysoftdroppedjet);
	ptD_sd = Angularity(2,0,m_jet_def->R(),mysoftdroppedjet);
	LHA_sd = Angularity(1,0.5,m_jet_def->R(),mysoftdroppedjet);
	width_sd = Angularity(1,1,m_jet_def->R(),mysoftdroppedjet);
	mass_sd = Angularity(1,2,m_jet_def->R(),mysoftdroppedjet);
	
	if (isquarkjet) num_qjets_allowcbt++;
	if (isquarkjet && !iscbt) {
	  qjets.push_back(myJets[ij]);
	  fTJsmallQjetPt.push_back(myJets[ij].pt());
	  fTJsmallQjetEta.push_back(myJets[ij].eta());
	  fTJsmallQjetPhi.push_back(myJets[ij].phi());
	  fTJsmallQjetM.push_back(myJets[ij].m());
	  fTJsmallQjetMult.push_back(mult);
	  fTJsmallQjetpTD.push_back(ptD);
	  fTJsmallQjetLHA.push_back(LHA);
	  fTJsmallQjetWidth.push_back(width);
	  fTJsmallQjetMass.push_back(mass);
	  fTJsmallQjetPt_SD.push_back(mysoftdroppedjet.pt());
          fTJsmallQjetEta_SD.push_back(mysoftdroppedjet.eta());
          fTJsmallQjetPhi_SD.push_back(mysoftdroppedjet.phi());
          fTJsmallQjetM_SD.push_back(mysoftdroppedjet.m());
          fTJsmallQjetMult_SD.push_back(mult_sd);
          fTJsmallQjetpTD_SD.push_back(ptD_sd);
          fTJsmallQjetLHA_SD.push_back(LHA_sd);
          fTJsmallQjetWidth_SD.push_back(width_sd);
          fTJsmallQjetMass_SD.push_back(mass_sd);
	  fTNQjetsSmallR++;
	}
	if (isgluonjet) {
	  gjets.push_back(myJets[ij]);
	  fTJsmallGjetPt.push_back(myJets[ij].pt());
          fTJsmallGjetEta.push_back(myJets[ij].eta());
          fTJsmallGjetPhi.push_back(myJets[ij].phi());
          fTJsmallGjetM.push_back(myJets[ij].m());
          fTJsmallGjetMult.push_back(mult);
          fTJsmallGjetpTD.push_back(ptD);
          fTJsmallGjetLHA.push_back(LHA);
          fTJsmallGjetWidth.push_back(width);
          fTJsmallGjetMass.push_back(mass);
	  fTJsmallGjetPt_SD.push_back(mysoftdroppedjet.pt());
          fTJsmallGjetEta_SD.push_back(mysoftdroppedjet.eta());
          fTJsmallGjetPhi_SD.push_back(mysoftdroppedjet.phi());
          fTJsmallGjetM_SD.push_back(mysoftdroppedjet.m());
          fTJsmallGjetMult_SD.push_back(mult_sd);
          fTJsmallGjetpTD_SD.push_back(ptD_sd);
          fTJsmallGjetLHA_SD.push_back(LHA_sd);
          fTJsmallGjetWidth_SD.push_back(width_sd);
          fTJsmallGjetMass_SD.push_back(mass_sd);
          fTNGjetsSmallR++;
	  num_gjets++;
	}

	if (isquarkjet && !iscbt) {
	  quark_or_gluon_by_index.push_back(1);
	}
	else if (isgluonjet) {
	  quark_or_gluon_by_index.push_back(2);
	}
	else {
	  quark_or_gluon_by_index.push_back(0);
	}
	

	//dR match to parton-level QCD aware jets and fill the QCDa branches
	bool matched = false;
	int matched_id;
	double min_R = 999999;
	for (int ii = 0; ii < aktPartonJets.size(); ii++) {
	  if (aktPartonJets[ii].delta_R(myJets[ij]) < m_jet_def->R() && aktPartonJets[ii].delta_R(myJets[ij]) < min_R) {
	    matched = true;
	    matched_id = aktPartonJets[ii].user_index();
	  }
	}
	if (matched) {
	  if (fabs(matched_id) <= 5 && matched_id != 0 && isquarkjet) num_qjets_QCDa_agree++;
	  if (fabs(matched_id) <= 3 && matched_id != 0) {
	    QCDaQjetPt.push_back(myJets[ij].pt());
	    QCDaQjetEta.push_back(myJets[ij].eta());
	    QCDaQjetPhi.push_back(myJets[ij].phi());
	    QCDaQjetM.push_back(myJets[ij].m());
	    QCDaQjetMult.push_back(mult);
	    QCDaQjetpTD.push_back(ptD);
	    QCDaQjetLHA.push_back(LHA);
	    QCDaQjetWidth.push_back(width);
	    QCDaQjetMass.push_back(mass);
	    QCDaQjetPt_SD.push_back(mysoftdroppedjet.pt());
	    QCDaQjetEta_SD.push_back(mysoftdroppedjet.eta());
	    QCDaQjetPhi_SD.push_back(mysoftdroppedjet.phi());
	    QCDaQjetM_SD.push_back(mysoftdroppedjet.m());
	    QCDaQjetMult_SD.push_back(mult_sd);
	    QCDaQjetpTD_SD.push_back(ptD_sd);
	    QCDaQjetLHA_SD.push_back(LHA_sd);
	    QCDaQjetWidth_SD.push_back(width_sd);
	    QCDaQjetMass_SD.push_back(mass_sd);
	    QCDaNQjetsSmallR++;
	  }
	  if (matched_id == 21) {
	    QCDaGjetPt.push_back(myJets[ij].pt());
	    QCDaGjetEta.push_back(myJets[ij].eta());
	    QCDaGjetPhi.push_back(myJets[ij].phi());
	    QCDaGjetM.push_back(myJets[ij].m());
	    QCDaGjetMult.push_back(mult);
	    QCDaGjetpTD.push_back(ptD);
	    QCDaGjetLHA.push_back(LHA);
	    QCDaGjetWidth.push_back(width);
	    QCDaGjetMass.push_back(mass);
	    QCDaGjetPt_SD.push_back(mysoftdroppedjet.pt());
	    QCDaGjetEta_SD.push_back(mysoftdroppedjet.eta());
	    QCDaGjetPhi_SD.push_back(mysoftdroppedjet.phi());
	    QCDaGjetM_SD.push_back(mysoftdroppedjet.m());
	    QCDaGjetMult_SD.push_back(mult_sd);
	    QCDaGjetpTD_SD.push_back(ptD_sd);
	    QCDaGjetLHA_SD.push_back(LHA_sd);
	    QCDaGjetWidth_SD.push_back(width_sd);
	    QCDaGjetMass_SD.push_back(mass_sd);
	    QCDaNGjetsSmallR++;
	    if (isgluonjet) num_gjets_QCDa_agree++;
	  }
	}
	if (matched && fabs(matched_id) <= 3 && matched_id != 0) {
          QCDa_quark_or_gluon_by_index.push_back(1);
        }
        else if (matched && matched_id == 21) {
          QCDa_quark_or_gluon_by_index.push_back(2);
        }
        else {
          QCDa_quark_or_gluon_by_index.push_back(0);
        }
	    
	
    }

    if (qjets.size() >= 2) qjet_dR_leading_subleading->Fill(qjets[0].delta_R(qjets[1]));
    if (gjets.size() >= 2) gjet_dR_leading_subleading->Fill(gjets[0].delta_R(gjets[1]));
    if (Zboson_index != -1) Zboson_pT = Zboson.pt();
    
    fTEventMass = -1;
    tT->Fill();
      
    if(fDebug) cout << "FCNCAnalysis::AnalyzeEvent End " << endl;
    return;
}



// declate branches
void FCNCAnalysis::DeclareBranches(){
   
   // Event Properties 
  tT->Branch("EventNumber",               &fTEventNumber, "EventNumber/I");
   
   // smallR jets
  tT->Branch("NJetsFilledSmallR",         &fTNJetsSmallRFilled,"NJetsFilledSmallR/I");
  tT->Branch("JsmallPt",                  &fTJsmallPt);
  tT->Branch("JsmallEta",                 &fTJsmallEta);
  tT->Branch("JsmallPhi",                 &fTJsmallPhi);
  tT->Branch("JsmallM",                   &fTJsmallM);
  tT->Branch("JsmallBtag", &fTJsmallBtag);
   //tT->Branch("JsmallTrackpT", &fTJsmallTrackpT, "JsmallTrackpT[NJetsFilledSmallR]");
   //tT->Branch("JsmallTrackMass", &fTJsmallTrackMass, "JsmallTrackMass[NJetsFilledSmallR]");
   //tT->Branch("smallntrack",&fTsmallntrack,"smallntrack[NJetsFilledSmallR]");
   //tT->Branch("JsmallTrackpTR", &fTJsmallTrackpTR, "JsmallTrackpTR[NJetsFilledSmallR]");
   //tT->Branch("JsmallTrackMassR", &fTJsmallTrackMassR, "JsmallTrackMassR[NJetsFilledSmallR]");
   //tT->Branch("smallntrackR",&fTsmallntrackR,"smallntrackR[NJetsFilledSmallR]");
   tT->Branch("EventMass",               &fTEventMass,            "EventMass");

   //smallR quark jets
   tT->Branch("NQjetsSmallR",&fTNQjetsSmallR,"NQjetsSmallR/I");
   tT->Branch("QjetPtSmallR",&fTJsmallQjetPt);
   tT->Branch("QjetEtaSmallR",&fTJsmallQjetEta);
   tT->Branch("QjetPhiSmallR",&fTJsmallQjetPhi);
   tT->Branch("QjetMSmallR",&fTJsmallQjetM);
   tT->Branch("QjetMultSmallR",&fTJsmallQjetMult);
   tT->Branch("QjetpTDSmallR",&fTJsmallQjetpTD);
   tT->Branch("QjetLHASmallR",&fTJsmallQjetLHA);
   tT->Branch("QjetWidthSmallR",&fTJsmallQjetWidth);
   tT->Branch("QjetMassSmallR",&fTJsmallQjetMass);
   tT->Branch("QjetPtSmallR_SD",&fTJsmallQjetPt_SD);
   tT->Branch("QjetEtaSmallR_SD",&fTJsmallQjetEta_SD);
   tT->Branch("QjetPhiSmallR_SD",&fTJsmallQjetPhi_SD);
   tT->Branch("QjetMSmallR_SD",&fTJsmallQjetM_SD);
   tT->Branch("QjetMultSmallR_SD",&fTJsmallQjetMult_SD);
   tT->Branch("QjetpTDSmallR_SD",&fTJsmallQjetpTD_SD);
   tT->Branch("QjetLHASmallR_SD",&fTJsmallQjetLHA_SD);
   tT->Branch("QjetWidthSmallR_SD",&fTJsmallQjetWidth_SD);
   tT->Branch("QjetMassSmallR_SD",&fTJsmallQjetMass_SD);

   tT->Branch("QCDaNQjetsSmallR",&QCDaNQjetsSmallR,"QCDaNQjetsSmallR/I");
   tT->Branch("QCDaQjetPtSmallR",&QCDaQjetPt);
   tT->Branch("QCDaQjetEtaSmallR",&QCDaQjetEta);
   tT->Branch("QCDaQjetPhiSmallR",&QCDaQjetPhi);
   tT->Branch("QCDaQjetMSmallR",&QCDaQjetM);
   tT->Branch("QCDaQjetMultSmallR",&QCDaQjetMult);
   tT->Branch("QCDaQjetpTDSmallR",&QCDaQjetpTD);
   tT->Branch("QCDaQjetLHASmallR",&QCDaQjetLHA);
   tT->Branch("QCDaQjetWidthSmallR",&QCDaQjetWidth);
   tT->Branch("QCDaQjetMassSmallR",&QCDaQjetMass);
   tT->Branch("QCDaQjetPtSmallR_SD",&QCDaQjetPt_SD);
   tT->Branch("QCDaQjetEtaSmallR_SD",&QCDaQjetEta_SD);
   tT->Branch("QCDaQjetPhiSmallR_SD",&QCDaQjetPhi_SD);
   tT->Branch("QCDaQjetMSmallR_SD",&QCDaQjetM_SD);
   tT->Branch("QCDaQjetMultSmallR_SD",&QCDaQjetMult_SD);
   tT->Branch("QCDaQjetpTDSmallR_SD",&QCDaQjetpTD_SD);
   tT->Branch("QCDaQjetLHASmallR_SD",&QCDaQjetLHA_SD);
   tT->Branch("QCDaQjetWidthSmallR_SD",&QCDaQjetWidth_SD);
   tT->Branch("QCDaQjetMassSmallR_SD",&QCDaQjetMass_SD);

   //smallR gluon jets
   tT->Branch("NGjetsSmallR",&fTNGjetsSmallR,"NGjetsSmallR/I");
   tT->Branch("GjetPtSmallR",&fTJsmallGjetPt);
   tT->Branch("GjetEtaSmallR",&fTJsmallGjetEta);
   tT->Branch("GjetPhiSmallR",&fTJsmallGjetPhi);
   tT->Branch("GjetMSmallR",&fTJsmallGjetM);
   tT->Branch("GjetMultSmallR",&fTJsmallGjetMult);
   tT->Branch("GjetpTDSmallR",&fTJsmallGjetpTD);
   tT->Branch("GjetLHASmallR",&fTJsmallGjetLHA);
   tT->Branch("GjetWidthSmallR",&fTJsmallGjetWidth);
   tT->Branch("GjetMassSmallR",&fTJsmallGjetMass);
   tT->Branch("GjetPtSmallR_SD",&fTJsmallGjetPt_SD);
   tT->Branch("GjetEtaSmallR_SD",&fTJsmallGjetEta_SD);
   tT->Branch("GjetPhiSmallR_SD",&fTJsmallGjetPhi_SD);
   tT->Branch("GjetMSmallR_SD",&fTJsmallGjetM_SD);
   tT->Branch("GjetMultSmallR_SD",&fTJsmallGjetMult_SD);
   tT->Branch("GjetpTDSmallR_SD",&fTJsmallGjetpTD_SD);
   tT->Branch("GjetLHASmallR_SD",&fTJsmallGjetLHA_SD);
   tT->Branch("GjetWidthSmallR_SD",&fTJsmallGjetWidth_SD);
   tT->Branch("GjetMassSmallR_SD",&fTJsmallGjetMass_SD);

   tT->Branch("QCDaNGjetsSmallR",&QCDaNGjetsSmallR,"QCDaNGjetsSmallR/I");
   tT->Branch("QCDaGjetPtSmallR",&QCDaGjetPt);
   tT->Branch("QCDaGjetEtaSmallR",&QCDaGjetEta);
   tT->Branch("QCDaGjetPhiSmallR",&QCDaGjetPhi);
   tT->Branch("QCDaGjetMSmallR",&QCDaGjetM);
   tT->Branch("QCDaGjetMultSmallR",&QCDaGjetMult);
   tT->Branch("QCDaGjetpTDSmallR",&QCDaGjetpTD);
   tT->Branch("QCDaGjetLHASmallR",&QCDaGjetLHA);
   tT->Branch("QCDaGjetWidthSmallR",&QCDaGjetWidth);
   tT->Branch("QCDaGjetMassSmallR",&QCDaGjetMass);
   tT->Branch("QCDaGjetPtSmallR_SD",&QCDaGjetPt_SD);
   tT->Branch("QCDaGjetEtaSmallR_SD",&QCDaGjetEta_SD);
   tT->Branch("QCDaGjetPhiSmallR_SD",&QCDaGjetPhi_SD);
   tT->Branch("QCDaGjetMSmallR_SD",&QCDaGjetM_SD);
   tT->Branch("QCDaGjetMultSmallR_SD",&QCDaGjetMult_SD);
   tT->Branch("QCDaGjetpTDSmallR_SD",&QCDaGjetpTD_SD);
   tT->Branch("QCDaGjetLHASmallR_SD",&QCDaGjetLHA_SD);
   tT->Branch("QCDaGjetWidthSmallR_SD",&QCDaGjetWidth_SD);
   tT->Branch("QCDaGjetMassSmallR_SD",&QCDaGjetMass_SD);
   
   tT->Branch("quark_or_gluon_by_index",&quark_or_gluon_by_index);
   tT->Branch("QCDa_quark_or_gluon_by_index",&QCDa_quark_or_gluon_by_index);

   tT->Branch("num_qjets_allowcbt",&num_qjets_allowcbt);
   tT->Branch("num_gjets",&num_gjets);
   tT->Branch("num_qjets_QCDa_agree",&num_qjets_QCDa_agree);
   tT->Branch("num_gjets_QCDa_agree",&num_gjets_QCDa_agree);
   tT->Branch("Zboson_pT",&Zboson_pT);

   
 
   tT->GetListOfBranches()->ls();
    
   return;
}


// resets vars
void FCNCAnalysis::ResetBranches(){
      // reset branches 
      fTEventNumber                 = -999;

      fTNJetsSmallRFilled=0;
      fTNQjetsSmallR=0;
      fTNGjetsSmallR=0;
      QCDaNQjetsSmallR=0;
      QCDaNGjetsSmallR=0;
      num_qjets_allowcbt=0;
      num_qjets_QCDa_agree=0;
      num_gjets=0;
      num_gjets_QCDa_agree=0;
      Zboson_pT = 0;

      fTJsmallPt.clear();
      fTJsmallPhi.clear();
      fTJsmallEta.clear();
      fTJsmallM.clear();
      fTJsmallBtag.clear();
      fTsmallntrack.clear();
      fTJsmallTrackpT.clear();
      fTJsmallTrackMass.clear();
      fTsmallntrackR.clear();
      fTJsmallTrackpTR.clear();
      fTJsmallTrackMassR.clear();

      fTJsmallQjetPt.clear();
      fTJsmallQjetEta.clear();
      fTJsmallQjetPhi.clear();
      fTJsmallQjetM.clear();
      fTJsmallQjetCharge.clear();
      fTJsmallQjetMult.clear();
      fTJsmallQjetpTD.clear();
      fTJsmallQjetLHA.clear();
      fTJsmallQjetWidth.clear();
      fTJsmallQjetMass.clear();
      fTJsmallQjetPt_SD.clear();
      fTJsmallQjetEta_SD.clear();
      fTJsmallQjetPhi_SD.clear();
      fTJsmallQjetM_SD.clear();
      fTJsmallQjetMult_SD.clear();
      fTJsmallQjetpTD_SD.clear();
      fTJsmallQjetLHA_SD.clear();
      fTJsmallQjetWidth_SD.clear();
      fTJsmallQjetMass_SD.clear();

      QCDaQjetPt.clear();
      QCDaQjetEta.clear();
      QCDaQjetPhi.clear();
      QCDaQjetM.clear();
      QCDaQjetCharge.clear();
      QCDaQjetMult.clear();
      QCDaQjetpTD.clear();
      QCDaQjetLHA.clear();
      QCDaQjetWidth.clear();
      QCDaQjetMass.clear();
      QCDaQjetPt_SD.clear();
      QCDaQjetEta_SD.clear();
      QCDaQjetPhi_SD.clear();
      QCDaQjetM_SD.clear();
      QCDaQjetMult_SD.clear();
      QCDaQjetpTD_SD.clear();
      QCDaQjetLHA_SD.clear();
      QCDaQjetWidth_SD.clear();
      QCDaQjetMass_SD.clear();
      
      fTJsmallGjetPt.clear();
      fTJsmallGjetEta.clear();
      fTJsmallGjetPhi.clear();
      fTJsmallGjetM.clear();
      fTJsmallGjetCharge.clear();
      fTJsmallGjetMult.clear();
      fTJsmallGjetpTD.clear();
      fTJsmallGjetLHA.clear();
      fTJsmallGjetWidth.clear();
      fTJsmallGjetMass.clear();
      fTJsmallGjetPt_SD.clear();
      fTJsmallGjetEta_SD.clear();
      fTJsmallGjetPhi_SD.clear();
      fTJsmallGjetM_SD.clear();
      fTJsmallGjetMult_SD.clear();
      fTJsmallGjetpTD_SD.clear();
      fTJsmallGjetLHA_SD.clear();
      fTJsmallGjetWidth_SD.clear();
      fTJsmallGjetMass_SD.clear();

      QCDaGjetPt.clear();
      QCDaGjetEta.clear();
      QCDaGjetPhi.clear();
      QCDaGjetM.clear();
      QCDaGjetCharge.clear();
      QCDaGjetMult.clear();
      QCDaGjetpTD.clear();
      QCDaGjetLHA.clear();
      QCDaGjetWidth.clear();
      QCDaGjetMass.clear();
      QCDaGjetPt_SD.clear();
      QCDaGjetEta_SD.clear();
      QCDaGjetPhi_SD.clear();
      QCDaGjetM_SD.clear();
      QCDaGjetMult_SD.clear();
      QCDaGjetpTD_SD.clear();
      QCDaGjetLHA_SD.clear();
      QCDaGjetWidth_SD.clear();
      QCDaGjetMass_SD.clear();

      quark_or_gluon_by_index.clear();
      QCDa_quark_or_gluon_by_index.clear();

}

