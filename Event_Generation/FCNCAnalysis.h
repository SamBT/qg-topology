#ifndef  FCNCAnalysis_H
#define  FCNCAnalysis_H

#include <vector>
#include <math.h>
#include <string>

#include "fastjet/ClusterSequence.hh"
#include "fastjet/PseudoJet.hh"  
#include "fastjet/tools/Filter.hh"
#include "fastjet/Selector.hh"

#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"
#include "TParticle.h"
#include "TH1.h"
#include "TH1F.h"
#include "TCanvas.h"

#include "FCNCTools.h"
#include "myFastJetBase.h"
#include "Pythia8/Pythia.h"

using namespace std;

extern TH1F *higgs_products;
extern TH1F *qjet_dR_leading_subleading;
extern TH1F *gjet_dR_leading_subleading;
extern bool HiggsTagger;

class FCNCAnalysis{
     private:
        int boosted_higgs_counter;
        int  ftest;
        int  fDebug;
        string fOutName;
	double min_jet_pt;

        TFile *tF;
        TTree *tT;
        FCNCTools *tool;
	
	float fTMETx;
	float fTMETy;
	float fTLepx;
	float fTLepy;
	float fTLepz;

	float fTlep1x;
	float fTlep1y;
	float fTlep1z;
	int fTlep1id;
	float fTEventMass;

	float fTlep2x;
	float fTlep2y;
	float fTlep2z;
	int fTlep12d;

	float fTjetm;
	float fTjetpt;

        // Tree Vars ---------------------------------------
        int              fTEventNumber;
        int              fTPassBoost;
        int              fTPassResolve;
	int fTwhichfat;
        // Els
        static const int MaxNEles    = 5;
        int              fTNElesFilled;
        vector<float>            fTElesPt ;
	vector<float>            fTElesEta;
	vector<float>            fTElesPhi;
	vector<float>            fTElesE;
        vector<int>              fTElesCharge;
        // Muons
        static const int MaxNMuons    = 5;
        int              fTNMuonsFilled;
        vector<float>            fTMuonsPt;
        vector<float>            fTMuonsEta;
        vector<float>            fTMuonsPhi;
        vector<float>            fTMuonsE;
        vector<int>              fTMuonsCharge;
        // Bosons 
        static const int MaxNBosons    = 5;
        int              fTNBosonsFilled;
        vector<float>            fTBosonPt;
        vector<float>            fTBosonEta;
        vector<float>            fTBosonPhi;
        vector<float>            fTBosonM;
        vector<int>              fTBosonID;

        static const int MaxNJetSmallR = 20;
        int              fTNJetsSmallRFilled;
        vector<float>            fTJsmallPt;
        vector<float>            fTJsmallEta;
        vector<float>            fTJsmallPhi;
        vector<float>            fTJsmallM;
        vector<float>            fTJsmallCharge;
	vector<float>            fTJsmallTrackpT;
	vector<float>            fTJsmallTrackMass;
        vector<float>            fTJsmallTrackpTR;
        vector<float>            fTJsmallTrackMassR;
	vector<int>              fTJsmallBtag;
	vector<int>              fTJsmallCtag;
	vector<int>              fTJsmallFtag;
        vector<int>              fTJsmallWPicked;
	vector<int>              fTJsmallBPicked;
	vector<int>              fTsmallntrack;
	vector<int>              fTsmallntrackR;

	//Quark jet variables
	int                      fTNQjetsSmallR;
        vector<float>            fTJsmallQjetPt;
        vector<float>            fTJsmallQjetEta;
        vector<float>            fTJsmallQjetPhi;
        vector<float>            fTJsmallQjetM;
        vector<float>            fTJsmallQjetCharge;
        vector<float>            fTJsmallQjetMult;
        vector<float>            fTJsmallQjetpTD;
	vector<float>            fTJsmallQjetLHA;
	vector<float>            fTJsmallQjetWidth;
	vector<float>            fTJsmallQjetMass;	
	vector<float>            fTJsmallQjetPt_SD;
        vector<float>            fTJsmallQjetEta_SD;
        vector<float>            fTJsmallQjetPhi_SD;
        vector<float>            fTJsmallQjetM_SD;
        vector<float>            fTJsmallQjetMult_SD;
        vector<float>            fTJsmallQjetpTD_SD;
        vector<float>            fTJsmallQjetLHA_SD;
        vector<float>            fTJsmallQjetWidth_SD;
        vector<float>            fTJsmallQjetMass_SD;

	int                      QCDaNQjetsSmallR;
        vector<float>            QCDaQjetPt;
        vector<float>            QCDaQjetEta;
        vector<float>            QCDaQjetPhi;
        vector<float>            QCDaQjetM;
        vector<float>            QCDaQjetCharge;
        vector<float>            QCDaQjetMult;
        vector<float>            QCDaQjetpTD;
        vector<float>            QCDaQjetLHA;
        vector<float>            QCDaQjetWidth;
        vector<float>            QCDaQjetMass;
        vector<float>            QCDaQjetPt_SD;
        vector<float>            QCDaQjetEta_SD;
        vector<float>            QCDaQjetPhi_SD;
        vector<float>            QCDaQjetM_SD;
        vector<float>            QCDaQjetMult_SD;
        vector<float>            QCDaQjetpTD_SD;
        vector<float>            QCDaQjetLHA_SD;
        vector<float>            QCDaQjetWidth_SD;
        vector<float>            QCDaQjetMass_SD;

	//Gluon Jet Variables
	int                      fTNGjetsSmallR;
        vector<float>            fTJsmallGjetPt;
        vector<float>            fTJsmallGjetEta;
        vector<float>            fTJsmallGjetPhi;
        vector<float>            fTJsmallGjetM;
        vector<float>            fTJsmallGjetCharge;
        vector<float>            fTJsmallGjetMult;
        vector<float>            fTJsmallGjetpTD;
        vector<float>            fTJsmallGjetLHA;
        vector<float>            fTJsmallGjetWidth;
        vector<float>            fTJsmallGjetMass;
	vector<float>            fTJsmallGjetPt_SD;
        vector<float>            fTJsmallGjetEta_SD;
        vector<float>            fTJsmallGjetPhi_SD;
        vector<float>            fTJsmallGjetM_SD;
        vector<float>            fTJsmallGjetMult_SD;
        vector<float>            fTJsmallGjetpTD_SD;
        vector<float>            fTJsmallGjetLHA_SD;
        vector<float>            fTJsmallGjetWidth_SD;
        vector<float>            fTJsmallGjetMass_SD;

	int                      QCDaNGjetsSmallR;
        vector<float>            QCDaGjetPt;
        vector<float>            QCDaGjetEta;
        vector<float>            QCDaGjetPhi;
        vector<float>            QCDaGjetM;
        vector<float>            QCDaGjetCharge;
        vector<float>            QCDaGjetMult;
        vector<float>            QCDaGjetpTD;
        vector<float>            QCDaGjetLHA;
        vector<float>            QCDaGjetWidth;
        vector<float>            QCDaGjetMass;
        vector<float>            QCDaGjetPt_SD;
        vector<float>            QCDaGjetEta_SD;
        vector<float>            QCDaGjetPhi_SD;
        vector<float>            QCDaGjetM_SD;
        vector<float>            QCDaGjetMult_SD;
        vector<float>            QCDaGjetpTD_SD;
        vector<float>            QCDaGjetLHA_SD;
        vector<float>            QCDaGjetWidth_SD;
        vector<float>            QCDaGjetMass_SD;

	vector<int>              quark_or_gluon_by_index;
	vector<int>              QCDa_quark_or_gluon_by_index;

	float num_qjets_allowcbt;
	float num_qjets_QCDa_agree;
	float num_gjets;
	float num_gjets_QCDa_agree;
	float Zboson_pT;
       
	vector<float>            fTJsmallScale;
	vector<float>            fTJsmallAngle;
	vector<float>            fTJsmallDrop;
	vector<float>            fTJsmallAdd;

	vector<float>            fTJsmallScaleP;
        vector<float>            fTJsmallAngleP;
        vector<float>            fTJsmallDropP;
        vector<float>            fTJsmallAddP;

	float fTtopmass; 
	float fTtopmass2;

        static const int MaxNJetLargeR = 20;
        int              fTNJetsLargeRFilled;
        vector<float>            fTJlargeRPt;
        vector<float>            fTJlargeREta;
        vector<float>            fTJlargeRPhi;
        vector<float>            fTJlargeRM;
        vector<float>            fTJlargeRMungroomed;
        vector<float>            fTJlargeRCharge;
        vector<int>              fTJlargeRBtag;
        vector<int>              fTJlargeWplusMatch;
        vector<int>              fTJlargeWminusMatch;
        vector<int>              fTJlargeZpMatch;
        vector<int>              fTJlargeHpMatch;

	int fTmode;

        fastjet::JetDefinition     *m_jet_def;
        fastjet::JetDefinition     *m_jet_def_largeR_ALTAS;
	fastjet::JetDefinition     *m_jet_def_cam;


    public:
        FCNCAnalysis (double jet_radius, double minpt_jet);
        ~FCNCAnalysis ();

        void Begin();
        void AnalyzeEvent(int iEvt, Pythia8::Pythia *pythia8);
        void End();
        void DeclareBranches();
        void ResetBranches();
        void Debug(int debug){
            fDebug = debug;
        }
        void SetOutName(string outname){
            fOutName = outname;
        }
        
};

#endif

