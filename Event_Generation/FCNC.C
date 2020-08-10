#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#include "TString.h"
#include "TSystem.h"
#include "TError.h"
//#include "TPythia8.h"
#include "TClonesArray.h"
#include "TParticle.h"
#include "TDatabasePDG.h"

#include "fastjet/PseudoJet.hh"  
#include "fastjet/ClusterSequence.hh"
#include "fastjet/Selector.hh"

#include "Pythia8/Pythia.h"

#include "FCNCTools.h"
#include "FCNCAnalysis.h"

#include "boost/program_options.hpp"

using std::cout;
using std::endl;
using std::string;
using std::map;
using namespace std;
namespace po = boost::program_options;

TH1F *higgs_products = new TH1F("higgs_products","higgs_products",30,0,30);
TH1F *qjet_dR_leading_subleading = new TH1F("qjet_dR_leading_subleading","qjet_dR_leading_subleading",50,0,5);
TH1F *gjet_dR_leading_subleading = new TH1F("gjet_dR_leading_subleading","gjet_dR_leading_subleading",50,0,5);
bool HiggsTagger;

int getSeed(int seed){                                                                                                                                               
  if (seed > -1) return seed;                                                                                                                                      \
  int timeSeed = time(NULL);                                                                                                                                       \
  return abs(((timeSeed*181)*((getpid()-83)*359))%104729);                                                                                                         \
}

int main(int argc, char* argv[]){
    // argument parsing  ------------------------
    cout << "Called as: ";
    for(int ii=0; ii<argc; ++ii){
        cout << argv[ii] << " ";
    }
    cout << endl;

    // arguments 
    int nEvents = 0;
    int fDebug  = 0;
    double radius = 0.4;
    double minpt_jet = 50;
    string outName = "test.root";
    string process = "dijets";
    string Hmass = "200";
    string ptmin = "45";
    string ptmax = "200";

    po::options_description desc("Allowed options");
    desc.add_options() //100000
      ("help", "produce help message")
      ("NEvents", po::value<int>(&nEvents)->default_value(10000) ,    "Number of Events ")
      ("Debug",   po::value<int>(&fDebug) ->default_value(0) ,     "Debug flag")
      ("radius",  po::value<double>(&radius)->default_value(0.4), "Jet radius")
      ("process", po::value<string>(&process)->default_value("dijets"), "Physics process")
      ("Hmass",   po::value<string>(&Hmass)->default_value("200"), "Higgs Mass")
      ("ptmin",   po::value<string>(&ptmin)->default_value("45"), "ptHatMin")
      ("ptmax",   po::value<string>(&ptmax)->default_value("200"), "ptHatMax")
      ("minjet",  po::value<double>(&minpt_jet)->default_value(50), "min jet pT")
      ("OutFile", po::value<string>(&outName)->default_value("test.root"), "output file name")
      ;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")>0){
        cout << desc << "\n";
        return 1;
    }
    //------

   Pythia8::Pythia* pythia8b = new Pythia8::Pythia();
   string Hmass_str = "25:m0 = "+Hmass;

   cout << "Set jet radius to be " << radius << endl;
   cout << "higgs string: " << Hmass_str << endl;
   cout << "Minimum jet pT is " << minpt_jet << endl;

   int    seed      =-1;
   seed = getSeed(seed);

   // Configure and initialize pythia                                                                                                                                
   pythia8b->readString("Random:setSeed = on");
   std::stringstream ss; ss << "Random:seed = " << seed;
   cout << ss.str() << endl;
   pythia8b->readString(ss.str());

   FCNCAnalysis * analysis1 = new FCNCAnalysis(radius, minpt_jet);

   cout << "ptHatMin = " << ptmin << endl; cout << "ptHatMax = " << ptmax << endl;

   pythia8b->readString("PhaseSpace:pTHatMin  = "+ptmin);
   pythia8b->readString("PhaseSpace:pTHatMax  = "+ptmax);
   pythia8b->readString("Beams:idA = 2212");
   pythia8b->readString("Beams:idB = 2212");
   pythia8b->readString("Beams:eCM = 13000");
   
   //Turning UE off, comment out if undesired
   //pythia8b->readString("PartonLevel:ISR = off");
   //pythia8b->readString("PartonLevel:MPI = off");
   
   HiggsTagger = false;
   
   //Dijet Settings
   if (process == "dijets") {
     cout << "making dijets" << endl;
     pythia8b->readString("HardQCD:all = on");
   }

   //Z+jets settings
   else if (process == "zplusjets") {
     cout << "making z+jets" << endl;
     pythia8b->readString("WeakBosonAndParton:qqbar2gmZg = on");
     pythia8b->readString("WeakBosonAndParton:qg2gmZq = on");
     pythia8b->readString("WeakBosonAndParton:ffbar2gmZgm = on");
     pythia8b->readString("WeakBosonAndParton:fgm2gmZf = on");
     pythia8b->readString("23:m0 = 200");
     pythia8b->readString("23:onMode = off");
     pythia8b->readString("23:mMin = 2.0");
     pythia8b->readString("23:onIfMatch = 12 12");
     pythia8b->readString("23:onIfMatch = 14 14");
     pythia8b->readString("23:onIfMatch = 16 16");
   }

   //qqbar->Zg settings
   else if (process == "qqbar2Zg") {
     cout << "making qqbar2Zg" << endl;
     pythia8b->readString("WeakBosonAndParton:qqbar2gmZg = on");
     pythia8b->readString("23:m0 = 200");
     pythia8b->readString("23:onMode = off");
     //pythia8b->readString("23:onIfAny = 12");
     pythia8b->readString("23:mMin = 2.0");
     pythia8b->readString("23:onIfMatch = 12 12");
     pythia8b->readString("23:onIfMatch = 14 14");
     pythia8b->readString("23:onIfMatch = 16 16");
   }

   //gg->Hg settings
   else if (process == "gg2Hg") {
     cout << "making gg2Hg" << endl;
     pythia8b->readString("HiggsSM:gg2Hg(l:t) = on");
     pythia8b->readString("25:m0 = 200");
     pythia8b->readString("25:onMode = off");
     pythia8b->readString("25:onIfMatch = 23 23");
     pythia8b->readString("23:onMode = off");
     pythia8b->readString("23:mMin = 2.0");
     pythia8b->readString("23:onIfMatch = 12 12");
     pythia8b->readString("23:onIfMatch = 14 14");
     pythia8b->readString("23:onIfMatch = 16 16");
   }

   else if (process == "H2gg") {
     cout << "making H --> gg" << endl;
     HiggsTagger = true;
     pythia8b->readString("25:mWidth = 0.1");
     pythia8b->readString("25:isResonance = true");
     pythia8b->readString("25:doForceWidth = true");
     pythia8b->readString(Hmass_str);
     pythia8b->readString("HiggsSM:gg2Hg(l:t) = on");
     pythia8b->readString("HiggsSM:qg2Hq(l:t) = on");
     pythia8b->readString("25:onMode = off");
     pythia8b->readString("25:onIfMatch = 21 21");
   }
   else if (process == "H2gg_ee") {
     HiggsTagger = true;
     pythia8b->readString("Beams:idA = 11");
     pythia8b->readString("Beams:idB = -11");
     pythia8b->readString("Beams:eCM = 100");
     pythia8b->readString("25:m0 = 100");
     pythia8b->readString("HiggsSM:ffbar2H = on");
     pythia8b->readString("HiggsSM:gmgm2H = on");
     pythia8b->readString("25:onMode = off");
     pythia8b->readString("25:onIfMatch = 21 21");
   }
   else if (process == "H2qqbar") {
     HiggsTagger = true;
     pythia8b->readString("25:mWidth = 0.1");
     pythia8b->readString("25:isResonance = true");
     pythia8b->readString("25:doForceWidth = true");
     pythia8b->readString(Hmass_str);
     pythia8b->readString("HiggsSM:gg2Hg(l:t) = on");
     pythia8b->readString("HiggsSM:qg2Hq(l:t) = on");
     pythia8b->readString("25:onMode = off");
     pythia8b->readString("25:onIfMatch = 1 1");
     pythia8b->readString("25:onIfMatch = 2 2");
     pythia8b->readString("25:onIfMatch = 3 3");
     pythia8b->readString("25:onIfMatch = 4 4");
   }
   else if (process == "H2qqbar_ee") {
     HiggsTagger = true;
     pythia8b->readString("Beams:idA = 11");
     pythia8b->readString("Beams:idB = -11");
     pythia8b->readString("Beams:eCM = 100");
     pythia8b->readString("25:m0 = 100");
     pythia8b->readString("HiggsSM:ffbar2H = on");
     pythia8b->readString("HiggsSM:gmgm2H = on");
     pythia8b->readString("25:onMode = off");
     pythia8b->readString("25:onIfMatch = 1 1");
     pythia8b->readString("25:onIfMatch = 2 2");
     pythia8b->readString("25:onIfMatch = 3 3");
     pythia8b->readString("25:onIfMatch = 4 4");
   }
   else if (process == "W2qqbar") {
     cout << "making W2qqbar" << endl;
     pythia8b->readString("WeakSingleBoson:ffbar2W = on");
     pythia8b->readString("24:onMode = off");
     pythia8b->readString("24:onIfAny = 1 2 3 4 5");
   }
   else if (process == "Z2qqbar_ee") {
     pythia8b->readString("Beams:idA = 11");
     pythia8b->readString("Beams:idB = -11");
     pythia8b->readString("WeakSingleBoson:ffbar2ffbar(s:gmZ) = on");
   }
   else {
     cout << "process not recognized, making dijets" << endl;
     pythia8b->readString("HardQCD:all = on");
   }
   pythia8b->init();

   analysis1->SetOutName(outName);
   analysis1->Begin();
   cout << "running on " << nEvents << " events " << endl;
   int fraction = nEvents/8;
   double num, num2;
   bool pp_higgs_lowpThat = (process == "H2gg" || process == "H2qqbar") && minpt_jet == 50;
   for (Int_t iev = 0; iev < nEvents; iev++) {
     if (iev%100==0) cout << iev << " " << nEvents << endl;
     num2 = (double)iev+1;
     num = (double)num2/fraction;
     if (process == "H2qqbar_ee" || process == "H2gg_ee") {
       if (num == 1) { cout << "switch 1" << endl; pythia8b->readString("Beams:eCM = 200"); pythia8b->readString("25:m0 = 200"); pythia8b->init();}
       if (num == 2) { cout << "switch 2" << endl; pythia8b->readString("Beams:eCM = 250"); pythia8b->readString("25:m0 = 250"); pythia8b->init();}
       if (num == 3) { cout << "switch 3" << endl; pythia8b->readString("Beams:eCM = 300"); pythia8b->readString("25:m0 = 300"); pythia8b->init();}
       if (num == 4) { cout << "switch 4" << endl; pythia8b->readString("Beams:eCM = 350"); pythia8b->readString("25:m0 = 350"); pythia8b->init();}
       if (num == 5) { cout << "switch 5" << endl; pythia8b->readString("Beams:eCM = 400"); pythia8b->readString("25:m0 = 400"); pythia8b->init();}
       if (num == 6) { cout << "switch 5" << endl; pythia8b->readString("Beams:eCM = 450"); pythia8b->readString("25:m0 = 450"); pythia8b->init();}
       if (num == 7) { cout << "switch 5" << endl; pythia8b->readString("Beams:eCM = 500"); pythia8b->readString("25:m0 = 500"); pythia8b->init();}
     }
     if (pp_higgs_lowpThat) {
       if (num == 1) { cout << "switch 1" << endl; pythia8b->readString("25:m0 = 200"); pythia8b->init();}
       if (num == 2) { cout << "switch 2" << endl; pythia8b->readString("25:m0 = 250"); pythia8b->init();}
       if (num == 3) { cout << "switch 3" << endl; pythia8b->readString("25:m0 = 300"); pythia8b->init();}
       if (num == 4) { cout << "switch 4" << endl; pythia8b->readString("25:m0 = 350"); pythia8b->init();}
       if (num == 5) { cout << "switch 5" << endl; pythia8b->readString("25:m0 = 400"); pythia8b->init();}
       if (num == 6) { cout << "switch 5" << endl; pythia8b->readString("25:m0 = 450"); pythia8b->init();}
       if (num == 7) { cout << "switch 5" << endl; pythia8b->readString("25:m0 = 500"); pythia8b->init();}
     }
     analysis1->AnalyzeEvent(iev, pythia8b);
   }
   analysis1->End();
   pythia8b->stat(); 

   //TCanvas *c = new TCanvas();
   //higgs_products->Draw();
   //c->SaveAs("higgs_products.png");

   
   TCanvas *c1 = new TCanvas();
   qjet_dR_leading_subleading->Draw("hist");
   c1->SaveAs("qjet_dR_leading_subleading.png");
   
   TCanvas *c2 = new TCanvas();
   gjet_dR_leading_subleading->Draw("hist");
   c2->SaveAs("gjet_dR_leading_subleading.png");
   

   delete analysis1;
   
   delete pythia8b;
   return 0;
}
