//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Aug  5 22:47:25 2018 by ROOT version 6.10/04
// from TTree EventTree/Event Tree for FCNC
// found on file: /project/projectdirs/atlas/sambt/Pythia_output_final/lowpT/Zplusjets_1M_R0p2/Zplusjets_1M_R0p2.root
//////////////////////////////////////////////////////////

#ifndef EventTree_h
#define EventTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include <vector>
using namespace std;

class EventTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           EventNumber;
   Int_t           NJetsFilledSmallR;
   vector<float>   *JsmallPt;
   vector<float>   *JsmallEta;
   vector<float>   *JsmallPhi;
   vector<float>   *JsmallM;
   vector<int>     *JsmallBtag;
   Float_t         EventMass;
   Int_t           NQjetsSmallR;
   vector<float>   *QjetPtSmallR;
   vector<float>   *QjetEtaSmallR;
   vector<float>   *QjetPhiSmallR;
   vector<float>   *QjetMSmallR;
   vector<float>   *QjetMultSmallR;
   vector<float>   *QjetpTDSmallR;
   vector<float>   *QjetLHASmallR;
   vector<float>   *QjetWidthSmallR;
   vector<float>   *QjetMassSmallR;
   vector<float>   *QjetPtSmallR_SD;
   vector<float>   *QjetEtaSmallR_SD;
   vector<float>   *QjetPhiSmallR_SD;
   vector<float>   *QjetMSmallR_SD;
   vector<float>   *QjetMultSmallR_SD;
   vector<float>   *QjetpTDSmallR_SD;
   vector<float>   *QjetLHASmallR_SD;
   vector<float>   *QjetWidthSmallR_SD;
   vector<float>   *QjetMassSmallR_SD;
   Int_t           QCDaNQjetsSmallR;
   vector<float>   *QCDaQjetPtSmallR;
   vector<float>   *QCDaQjetEtaSmallR;
   vector<float>   *QCDaQjetPhiSmallR;
   vector<float>   *QCDaQjetMSmallR;
   vector<float>   *QCDaQjetMultSmallR;
   vector<float>   *QCDaQjetpTDSmallR;
   vector<float>   *QCDaQjetLHASmallR;
   vector<float>   *QCDaQjetWidthSmallR;
   vector<float>   *QCDaQjetMassSmallR;
   vector<float>   *QCDaQjetPtSmallR_SD;
   vector<float>   *QCDaQjetEtaSmallR_SD;
   vector<float>   *QCDaQjetPhiSmallR_SD;
   vector<float>   *QCDaQjetMSmallR_SD;
   vector<float>   *QCDaQjetMultSmallR_SD;
   vector<float>   *QCDaQjetpTDSmallR_SD;
   vector<float>   *QCDaQjetLHASmallR_SD;
   vector<float>   *QCDaQjetWidthSmallR_SD;
   vector<float>   *QCDaQjetMassSmallR_SD;
   Int_t           NGjetsSmallR;
   vector<float>   *GjetPtSmallR;
   vector<float>   *GjetEtaSmallR;
   vector<float>   *GjetPhiSmallR;
   vector<float>   *GjetMSmallR;
   vector<float>   *GjetMultSmallR;
   vector<float>   *GjetpTDSmallR;
   vector<float>   *GjetLHASmallR;
   vector<float>   *GjetWidthSmallR;
   vector<float>   *GjetMassSmallR;
   vector<float>   *GjetPtSmallR_SD;
   vector<float>   *GjetEtaSmallR_SD;
   vector<float>   *GjetPhiSmallR_SD;
   vector<float>   *GjetMSmallR_SD;
   vector<float>   *GjetMultSmallR_SD;
   vector<float>   *GjetpTDSmallR_SD;
   vector<float>   *GjetLHASmallR_SD;
   vector<float>   *GjetWidthSmallR_SD;
   vector<float>   *GjetMassSmallR_SD;
   Int_t           QCDaNGjetsSmallR;
   vector<float>   *QCDaGjetPtSmallR;
   vector<float>   *QCDaGjetEtaSmallR;
   vector<float>   *QCDaGjetPhiSmallR;
   vector<float>   *QCDaGjetMSmallR;
   vector<float>   *QCDaGjetMultSmallR;
   vector<float>   *QCDaGjetpTDSmallR;
   vector<float>   *QCDaGjetLHASmallR;
   vector<float>   *QCDaGjetWidthSmallR;
   vector<float>   *QCDaGjetMassSmallR;
   vector<float>   *QCDaGjetPtSmallR_SD;
   vector<float>   *QCDaGjetEtaSmallR_SD;
   vector<float>   *QCDaGjetPhiSmallR_SD;
   vector<float>   *QCDaGjetMSmallR_SD;
   vector<float>   *QCDaGjetMultSmallR_SD;
   vector<float>   *QCDaGjetpTDSmallR_SD;
   vector<float>   *QCDaGjetLHASmallR_SD;
   vector<float>   *QCDaGjetWidthSmallR_SD;
   vector<float>   *QCDaGjetMassSmallR_SD;
   vector<int>     *quark_or_gluon_by_index;
   vector<int>     *QCDa_quark_or_gluon_by_index;
   Float_t         num_qjets_allowcbt;
   Float_t         num_gjets;
   Float_t         num_qjets_QCDa_agree;
   Float_t         num_gjets_QCDa_agree;
   Float_t         Zboson_pT;

   // List of branches
   TBranch        *b_EventNumber;   //!
   TBranch        *b_NJetsFilledSmallR;   //!
   TBranch        *b_JsmallPt;   //!
   TBranch        *b_JsmallEta;   //!
   TBranch        *b_JsmallPhi;   //!
   TBranch        *b_JsmallM;   //!
   TBranch        *b_JsmallBtag;   //!
   TBranch        *b_EventMass;   //!
   TBranch        *b_NQjetsSmallR;   //!
   TBranch        *b_QjetPtSmallR;   //!
   TBranch        *b_QjetEtaSmallR;   //!
   TBranch        *b_QjetPhiSmallR;   //!
   TBranch        *b_QjetMSmallR;   //!
   TBranch        *b_QjetMultSmallR;   //!
   TBranch        *b_QjetpTDSmallR;   //!
   TBranch        *b_QjetLHASmallR;   //!
   TBranch        *b_QjetWidthSmallR;   //!
   TBranch        *b_QjetMassSmallR;   //!
   TBranch        *b_QjetPtSmallR_SD;   //!
   TBranch        *b_QjetEtaSmallR_SD;   //!
   TBranch        *b_QjetPhiSmallR_SD;   //!
   TBranch        *b_QjetMSmallR_SD;   //!
   TBranch        *b_QjetMultSmallR_SD;   //!
   TBranch        *b_QjetpTDSmallR_SD;   //!
   TBranch        *b_QjetLHASmallR_SD;   //!
   TBranch        *b_QjetWidthSmallR_SD;   //!
   TBranch        *b_QjetMassSmallR_SD;   //!
   TBranch        *b_QCDaNQjetsSmallR;   //!
   TBranch        *b_QCDaQjetPtSmallR;   //!
   TBranch        *b_QCDaQjetEtaSmallR;   //!
   TBranch        *b_QCDaQjetPhiSmallR;   //!
   TBranch        *b_QCDaQjetMSmallR;   //!
   TBranch        *b_QCDaQjetMultSmallR;   //!
   TBranch        *b_QCDaQjetpTDSmallR;   //!
   TBranch        *b_QCDaQjetLHASmallR;   //!
   TBranch        *b_QCDaQjetWidthSmallR;   //!
   TBranch        *b_QCDaQjetMassSmallR;   //!
   TBranch        *b_QCDaQjetPtSmallR_SD;   //!
   TBranch        *b_QCDaQjetEtaSmallR_SD;   //!
   TBranch        *b_QCDaQjetPhiSmallR_SD;   //!
   TBranch        *b_QCDaQjetMSmallR_SD;   //!
   TBranch        *b_QCDaQjetMultSmallR_SD;   //!
   TBranch        *b_QCDaQjetpTDSmallR_SD;   //!
   TBranch        *b_QCDaQjetLHASmallR_SD;   //!
   TBranch        *b_QCDaQjetWidthSmallR_SD;   //!
   TBranch        *b_QCDaQjetMassSmallR_SD;   //!
   TBranch        *b_NGjetsSmallR;   //!
   TBranch        *b_GjetPtSmallR;   //!
   TBranch        *b_GjetEtaSmallR;   //!
   TBranch        *b_GjetPhiSmallR;   //!
   TBranch        *b_GjetMSmallR;   //!
   TBranch        *b_GjetMultSmallR;   //!
   TBranch        *b_GjetpTDSmallR;   //!
   TBranch        *b_GjetLHASmallR;   //!
   TBranch        *b_GjetWidthSmallR;   //!
   TBranch        *b_GjetMassSmallR;   //!
   TBranch        *b_GjetPtSmallR_SD;   //!
   TBranch        *b_GjetEtaSmallR_SD;   //!
   TBranch        *b_GjetPhiSmallR_SD;   //!
   TBranch        *b_GjetMSmallR_SD;   //!
   TBranch        *b_GjetMultSmallR_SD;   //!
   TBranch        *b_GjetpTDSmallR_SD;   //!
   TBranch        *b_GjetLHASmallR_SD;   //!
   TBranch        *b_GjetWidthSmallR_SD;   //!
   TBranch        *b_GjetMassSmallR_SD;   //!
   TBranch        *b_QCDaNGjetsSmallR;   //!
   TBranch        *b_QCDaGjetPtSmallR;   //!
   TBranch        *b_QCDaGjetEtaSmallR;   //!
   TBranch        *b_QCDaGjetPhiSmallR;   //!
   TBranch        *b_QCDaGjetMSmallR;   //!
   TBranch        *b_QCDaGjetMultSmallR;   //!
   TBranch        *b_QCDaGjetpTDSmallR;   //!
   TBranch        *b_QCDaGjetLHASmallR;   //!
   TBranch        *b_QCDaGjetWidthSmallR;   //!
   TBranch        *b_QCDaGjetMassSmallR;   //!
   TBranch        *b_QCDaGjetPtSmallR_SD;   //!
   TBranch        *b_QCDaGjetEtaSmallR_SD;   //!
   TBranch        *b_QCDaGjetPhiSmallR_SD;   //!
   TBranch        *b_QCDaGjetMSmallR_SD;   //!
   TBranch        *b_QCDaGjetMultSmallR_SD;   //!
   TBranch        *b_QCDaGjetpTDSmallR_SD;   //!
   TBranch        *b_QCDaGjetLHASmallR_SD;   //!
   TBranch        *b_QCDaGjetWidthSmallR_SD;   //!
   TBranch        *b_QCDaGjetMassSmallR_SD;   //!
   TBranch        *b_quark_or_gluon_by_index;   //!
   TBranch        *b_QCDa_quark_or_gluon_by_index;   //!
   TBranch        *b_num_qjets_allowcbt;   //!
   TBranch        *b_num_gjets;   //!
   TBranch        *b_num_qjets_QCDa_agree;   //!
   TBranch        *b_num_gjets_QCDa_agree;   //!
   TBranch        *b_Zboson_pT;   //!

   EventTree(TTree *tree=0);
   virtual ~EventTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef EventTree_cxx
EventTree::EventTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/project/projectdirs/atlas/sambt/Pythia_output_final/lowpT/Zplusjets_1M_R0p2/Zplusjets_1M_R0p2.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/project/projectdirs/atlas/sambt/Pythia_output_final/lowpT/Zplusjets_1M_R0p2/Zplusjets_1M_R0p2.root");
      }
      f->GetObject("EventTree",tree);

   }
   Init(tree);
}

EventTree::~EventTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t EventTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t EventTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void EventTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   JsmallPt = 0;
   JsmallEta = 0;
   JsmallPhi = 0;
   JsmallM = 0;
   JsmallBtag = 0;
   QjetPtSmallR = 0;
   QjetEtaSmallR = 0;
   QjetPhiSmallR = 0;
   QjetMSmallR = 0;
   QjetMultSmallR = 0;
   QjetpTDSmallR = 0;
   QjetLHASmallR = 0;
   QjetWidthSmallR = 0;
   QjetMassSmallR = 0;
   QjetPtSmallR_SD = 0;
   QjetEtaSmallR_SD = 0;
   QjetPhiSmallR_SD = 0;
   QjetMSmallR_SD = 0;
   QjetMultSmallR_SD = 0;
   QjetpTDSmallR_SD = 0;
   QjetLHASmallR_SD = 0;
   QjetWidthSmallR_SD = 0;
   QjetMassSmallR_SD = 0;
   QCDaQjetPtSmallR = 0;
   QCDaQjetEtaSmallR = 0;
   QCDaQjetPhiSmallR = 0;
   QCDaQjetMSmallR = 0;
   QCDaQjetMultSmallR = 0;
   QCDaQjetpTDSmallR = 0;
   QCDaQjetLHASmallR = 0;
   QCDaQjetWidthSmallR = 0;
   QCDaQjetMassSmallR = 0;
   QCDaQjetPtSmallR_SD = 0;
   QCDaQjetEtaSmallR_SD = 0;
   QCDaQjetPhiSmallR_SD = 0;
   QCDaQjetMSmallR_SD = 0;
   QCDaQjetMultSmallR_SD = 0;
   QCDaQjetpTDSmallR_SD = 0;
   QCDaQjetLHASmallR_SD = 0;
   QCDaQjetWidthSmallR_SD = 0;
   QCDaQjetMassSmallR_SD = 0;
   GjetPtSmallR = 0;
   GjetEtaSmallR = 0;
   GjetPhiSmallR = 0;
   GjetMSmallR = 0;
   GjetMultSmallR = 0;
   GjetpTDSmallR = 0;
   GjetLHASmallR = 0;
   GjetWidthSmallR = 0;
   GjetMassSmallR = 0;
   GjetPtSmallR_SD = 0;
   GjetEtaSmallR_SD = 0;
   GjetPhiSmallR_SD = 0;
   GjetMSmallR_SD = 0;
   GjetMultSmallR_SD = 0;
   GjetpTDSmallR_SD = 0;
   GjetLHASmallR_SD = 0;
   GjetWidthSmallR_SD = 0;
   GjetMassSmallR_SD = 0;
   QCDaGjetPtSmallR = 0;
   QCDaGjetEtaSmallR = 0;
   QCDaGjetPhiSmallR = 0;
   QCDaGjetMSmallR = 0;
   QCDaGjetMultSmallR = 0;
   QCDaGjetpTDSmallR = 0;
   QCDaGjetLHASmallR = 0;
   QCDaGjetWidthSmallR = 0;
   QCDaGjetMassSmallR = 0;
   QCDaGjetPtSmallR_SD = 0;
   QCDaGjetEtaSmallR_SD = 0;
   QCDaGjetPhiSmallR_SD = 0;
   QCDaGjetMSmallR_SD = 0;
   QCDaGjetMultSmallR_SD = 0;
   QCDaGjetpTDSmallR_SD = 0;
   QCDaGjetLHASmallR_SD = 0;
   QCDaGjetWidthSmallR_SD = 0;
   QCDaGjetMassSmallR_SD = 0;
   quark_or_gluon_by_index = 0;
   QCDa_quark_or_gluon_by_index = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("NJetsFilledSmallR", &NJetsFilledSmallR, &b_NJetsFilledSmallR);
   fChain->SetBranchAddress("JsmallPt", &JsmallPt, &b_JsmallPt);
   fChain->SetBranchAddress("JsmallEta", &JsmallEta, &b_JsmallEta);
   fChain->SetBranchAddress("JsmallPhi", &JsmallPhi, &b_JsmallPhi);
   fChain->SetBranchAddress("JsmallM", &JsmallM, &b_JsmallM);
   fChain->SetBranchAddress("JsmallBtag", &JsmallBtag, &b_JsmallBtag);
   fChain->SetBranchAddress("EventMass", &EventMass, &b_EventMass);
   fChain->SetBranchAddress("NQjetsSmallR", &NQjetsSmallR, &b_NQjetsSmallR);
   fChain->SetBranchAddress("QjetPtSmallR", &QjetPtSmallR, &b_QjetPtSmallR);
   fChain->SetBranchAddress("QjetEtaSmallR", &QjetEtaSmallR, &b_QjetEtaSmallR);
   fChain->SetBranchAddress("QjetPhiSmallR", &QjetPhiSmallR, &b_QjetPhiSmallR);
   fChain->SetBranchAddress("QjetMSmallR", &QjetMSmallR, &b_QjetMSmallR);
   fChain->SetBranchAddress("QjetMultSmallR", &QjetMultSmallR, &b_QjetMultSmallR);
   fChain->SetBranchAddress("QjetpTDSmallR", &QjetpTDSmallR, &b_QjetpTDSmallR);
   fChain->SetBranchAddress("QjetLHASmallR", &QjetLHASmallR, &b_QjetLHASmallR);
   fChain->SetBranchAddress("QjetWidthSmallR", &QjetWidthSmallR, &b_QjetWidthSmallR);
   fChain->SetBranchAddress("QjetMassSmallR", &QjetMassSmallR, &b_QjetMassSmallR);
   fChain->SetBranchAddress("QjetPtSmallR_SD", &QjetPtSmallR_SD, &b_QjetPtSmallR_SD);
   fChain->SetBranchAddress("QjetEtaSmallR_SD", &QjetEtaSmallR_SD, &b_QjetEtaSmallR_SD);
   fChain->SetBranchAddress("QjetPhiSmallR_SD", &QjetPhiSmallR_SD, &b_QjetPhiSmallR_SD);
   fChain->SetBranchAddress("QjetMSmallR_SD", &QjetMSmallR_SD, &b_QjetMSmallR_SD);
   fChain->SetBranchAddress("QjetMultSmallR_SD", &QjetMultSmallR_SD, &b_QjetMultSmallR_SD);
   fChain->SetBranchAddress("QjetpTDSmallR_SD", &QjetpTDSmallR_SD, &b_QjetpTDSmallR_SD);
   fChain->SetBranchAddress("QjetLHASmallR_SD", &QjetLHASmallR_SD, &b_QjetLHASmallR_SD);
   fChain->SetBranchAddress("QjetWidthSmallR_SD", &QjetWidthSmallR_SD, &b_QjetWidthSmallR_SD);
   fChain->SetBranchAddress("QjetMassSmallR_SD", &QjetMassSmallR_SD, &b_QjetMassSmallR_SD);
   fChain->SetBranchAddress("QCDaNQjetsSmallR", &QCDaNQjetsSmallR, &b_QCDaNQjetsSmallR);
   fChain->SetBranchAddress("QCDaQjetPtSmallR", &QCDaQjetPtSmallR, &b_QCDaQjetPtSmallR);
   fChain->SetBranchAddress("QCDaQjetEtaSmallR", &QCDaQjetEtaSmallR, &b_QCDaQjetEtaSmallR);
   fChain->SetBranchAddress("QCDaQjetPhiSmallR", &QCDaQjetPhiSmallR, &b_QCDaQjetPhiSmallR);
   fChain->SetBranchAddress("QCDaQjetMSmallR", &QCDaQjetMSmallR, &b_QCDaQjetMSmallR);
   fChain->SetBranchAddress("QCDaQjetMultSmallR", &QCDaQjetMultSmallR, &b_QCDaQjetMultSmallR);
   fChain->SetBranchAddress("QCDaQjetpTDSmallR", &QCDaQjetpTDSmallR, &b_QCDaQjetpTDSmallR);
   fChain->SetBranchAddress("QCDaQjetLHASmallR", &QCDaQjetLHASmallR, &b_QCDaQjetLHASmallR);
   fChain->SetBranchAddress("QCDaQjetWidthSmallR", &QCDaQjetWidthSmallR, &b_QCDaQjetWidthSmallR);
   fChain->SetBranchAddress("QCDaQjetMassSmallR", &QCDaQjetMassSmallR, &b_QCDaQjetMassSmallR);
   fChain->SetBranchAddress("QCDaQjetPtSmallR_SD", &QCDaQjetPtSmallR_SD, &b_QCDaQjetPtSmallR_SD);
   fChain->SetBranchAddress("QCDaQjetEtaSmallR_SD", &QCDaQjetEtaSmallR_SD, &b_QCDaQjetEtaSmallR_SD);
   fChain->SetBranchAddress("QCDaQjetPhiSmallR_SD", &QCDaQjetPhiSmallR_SD, &b_QCDaQjetPhiSmallR_SD);
   fChain->SetBranchAddress("QCDaQjetMSmallR_SD", &QCDaQjetMSmallR_SD, &b_QCDaQjetMSmallR_SD);
   fChain->SetBranchAddress("QCDaQjetMultSmallR_SD", &QCDaQjetMultSmallR_SD, &b_QCDaQjetMultSmallR_SD);
   fChain->SetBranchAddress("QCDaQjetpTDSmallR_SD", &QCDaQjetpTDSmallR_SD, &b_QCDaQjetpTDSmallR_SD);
   fChain->SetBranchAddress("QCDaQjetLHASmallR_SD", &QCDaQjetLHASmallR_SD, &b_QCDaQjetLHASmallR_SD);
   fChain->SetBranchAddress("QCDaQjetWidthSmallR_SD", &QCDaQjetWidthSmallR_SD, &b_QCDaQjetWidthSmallR_SD);
   fChain->SetBranchAddress("QCDaQjetMassSmallR_SD", &QCDaQjetMassSmallR_SD, &b_QCDaQjetMassSmallR_SD);
   fChain->SetBranchAddress("NGjetsSmallR", &NGjetsSmallR, &b_NGjetsSmallR);
   fChain->SetBranchAddress("GjetPtSmallR", &GjetPtSmallR, &b_GjetPtSmallR);
   fChain->SetBranchAddress("GjetEtaSmallR", &GjetEtaSmallR, &b_GjetEtaSmallR);
   fChain->SetBranchAddress("GjetPhiSmallR", &GjetPhiSmallR, &b_GjetPhiSmallR);
   fChain->SetBranchAddress("GjetMSmallR", &GjetMSmallR, &b_GjetMSmallR);
   fChain->SetBranchAddress("GjetMultSmallR", &GjetMultSmallR, &b_GjetMultSmallR);
   fChain->SetBranchAddress("GjetpTDSmallR", &GjetpTDSmallR, &b_GjetpTDSmallR);
   fChain->SetBranchAddress("GjetLHASmallR", &GjetLHASmallR, &b_GjetLHASmallR);
   fChain->SetBranchAddress("GjetWidthSmallR", &GjetWidthSmallR, &b_GjetWidthSmallR);
   fChain->SetBranchAddress("GjetMassSmallR", &GjetMassSmallR, &b_GjetMassSmallR);
   fChain->SetBranchAddress("GjetPtSmallR_SD", &GjetPtSmallR_SD, &b_GjetPtSmallR_SD);
   fChain->SetBranchAddress("GjetEtaSmallR_SD", &GjetEtaSmallR_SD, &b_GjetEtaSmallR_SD);
   fChain->SetBranchAddress("GjetPhiSmallR_SD", &GjetPhiSmallR_SD, &b_GjetPhiSmallR_SD);
   fChain->SetBranchAddress("GjetMSmallR_SD", &GjetMSmallR_SD, &b_GjetMSmallR_SD);
   fChain->SetBranchAddress("GjetMultSmallR_SD", &GjetMultSmallR_SD, &b_GjetMultSmallR_SD);
   fChain->SetBranchAddress("GjetpTDSmallR_SD", &GjetpTDSmallR_SD, &b_GjetpTDSmallR_SD);
   fChain->SetBranchAddress("GjetLHASmallR_SD", &GjetLHASmallR_SD, &b_GjetLHASmallR_SD);
   fChain->SetBranchAddress("GjetWidthSmallR_SD", &GjetWidthSmallR_SD, &b_GjetWidthSmallR_SD);
   fChain->SetBranchAddress("GjetMassSmallR_SD", &GjetMassSmallR_SD, &b_GjetMassSmallR_SD);
   fChain->SetBranchAddress("QCDaNGjetsSmallR", &QCDaNGjetsSmallR, &b_QCDaNGjetsSmallR);
   fChain->SetBranchAddress("QCDaGjetPtSmallR", &QCDaGjetPtSmallR, &b_QCDaGjetPtSmallR);
   fChain->SetBranchAddress("QCDaGjetEtaSmallR", &QCDaGjetEtaSmallR, &b_QCDaGjetEtaSmallR);
   fChain->SetBranchAddress("QCDaGjetPhiSmallR", &QCDaGjetPhiSmallR, &b_QCDaGjetPhiSmallR);
   fChain->SetBranchAddress("QCDaGjetMSmallR", &QCDaGjetMSmallR, &b_QCDaGjetMSmallR);
   fChain->SetBranchAddress("QCDaGjetMultSmallR", &QCDaGjetMultSmallR, &b_QCDaGjetMultSmallR);
   fChain->SetBranchAddress("QCDaGjetpTDSmallR", &QCDaGjetpTDSmallR, &b_QCDaGjetpTDSmallR);
   fChain->SetBranchAddress("QCDaGjetLHASmallR", &QCDaGjetLHASmallR, &b_QCDaGjetLHASmallR);
   fChain->SetBranchAddress("QCDaGjetWidthSmallR", &QCDaGjetWidthSmallR, &b_QCDaGjetWidthSmallR);
   fChain->SetBranchAddress("QCDaGjetMassSmallR", &QCDaGjetMassSmallR, &b_QCDaGjetMassSmallR);
   fChain->SetBranchAddress("QCDaGjetPtSmallR_SD", &QCDaGjetPtSmallR_SD, &b_QCDaGjetPtSmallR_SD);
   fChain->SetBranchAddress("QCDaGjetEtaSmallR_SD", &QCDaGjetEtaSmallR_SD, &b_QCDaGjetEtaSmallR_SD);
   fChain->SetBranchAddress("QCDaGjetPhiSmallR_SD", &QCDaGjetPhiSmallR_SD, &b_QCDaGjetPhiSmallR_SD);
   fChain->SetBranchAddress("QCDaGjetMSmallR_SD", &QCDaGjetMSmallR_SD, &b_QCDaGjetMSmallR_SD);
   fChain->SetBranchAddress("QCDaGjetMultSmallR_SD", &QCDaGjetMultSmallR_SD, &b_QCDaGjetMultSmallR_SD);
   fChain->SetBranchAddress("QCDaGjetpTDSmallR_SD", &QCDaGjetpTDSmallR_SD, &b_QCDaGjetpTDSmallR_SD);
   fChain->SetBranchAddress("QCDaGjetLHASmallR_SD", &QCDaGjetLHASmallR_SD, &b_QCDaGjetLHASmallR_SD);
   fChain->SetBranchAddress("QCDaGjetWidthSmallR_SD", &QCDaGjetWidthSmallR_SD, &b_QCDaGjetWidthSmallR_SD);
   fChain->SetBranchAddress("QCDaGjetMassSmallR_SD", &QCDaGjetMassSmallR_SD, &b_QCDaGjetMassSmallR_SD);
   fChain->SetBranchAddress("quark_or_gluon_by_index", &quark_or_gluon_by_index, &b_quark_or_gluon_by_index);
   fChain->SetBranchAddress("QCDa_quark_or_gluon_by_index", &QCDa_quark_or_gluon_by_index, &b_QCDa_quark_or_gluon_by_index);
   fChain->SetBranchAddress("num_qjets_allowcbt", &num_qjets_allowcbt, &b_num_qjets_allowcbt);
   fChain->SetBranchAddress("num_gjets", &num_gjets, &b_num_gjets);
   fChain->SetBranchAddress("num_qjets_QCDa_agree", &num_qjets_QCDa_agree, &b_num_qjets_QCDa_agree);
   fChain->SetBranchAddress("num_gjets_QCDa_agree", &num_gjets_QCDa_agree, &b_num_gjets_QCDa_agree);
   fChain->SetBranchAddress("Zboson_pT", &Zboson_pT, &b_Zboson_pT);
   Notify();
}

Bool_t EventTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void EventTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t EventTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef EventTree_cxx
