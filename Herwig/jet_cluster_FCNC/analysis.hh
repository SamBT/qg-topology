#include "TGraphAsymmErrors.h"
#include "TEfficiency.h"
#include "TLatex.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TROOT.h"
#include "THStack.h"
#include "TString.h"
#include "TH1.h"
#include "TH2F.h"
#include "TRandom.h"
#include "TRandom3.h"
#include "RooRealVar.h"
#include "RooExponential.h"
#include "RooPlot.h"
#include "RooGaussian.h"
#include "RooPolynomial.h"
#include "RooAddPdf.h"
#include "RooAbsData.h"
#include "RooAbsRealLValue.h"
#include "RooAbsPdf.h"
#include "RooMinuit.h"
#include "RooCategory.h"
#include "RooDataSet.h"
#include "RooArgSet.h"
#include "RooDataHist.h"
#include "RooNLLVar.h"
#include "RooSimultaneous.h"
#include "RooExponential.h"
#include "RooGlobalFunc.h"
#include "RooCBShape.h"
#include "RooFormula.h"
#include "RooRandom.h"
#include "RooFitResult.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "hepmc3_tree.hh"
#include "header.hh"
using namespace std;
using namespace RooFit;
#include <sys/stat.h>


hepmc3_tree *p;

void get_event(int i) {
  if ( p->LoadTree(i) < 0) { 
    cout<<"\nProblem in LoadTree."
        <<"\nEntry: "<<i<<endl;
    exit(0);
  }
  p->fChain->GetEntry(i);
}

