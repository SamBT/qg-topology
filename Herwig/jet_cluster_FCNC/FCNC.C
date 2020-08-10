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
//#include "analysis.hh"

#include "fastjet/PseudoJet.hh"  
#include "fastjet/ClusterSequence.hh"
#include "fastjet/Selector.hh"
#include "HepMC/GenEvent.h"
#include "HepMC/ReaderAsciiHepMC2.h"
#include "HepMC/WriterRootTree.h"
#include "HepMC/Print.h"
#include "HepMC/Units.h"
#include "HepMC/Data/GenEventData.h"
#include "HepMC/FourVector.h"
#include "HepMC/Data/GenParticleData.h"
#include "HepMC/Data/GenVertexData.h"
#include "HepMC/Data/GenRunInfoData.h"

#include "Pythia8/Pythia.h"

#include "FCNCTools.h"
#include "FCNCAnalysis.h"
#include "hepmc3_tree.hh"

#include "boost/program_options.hpp"

using std::cout;
using std::endl;
using std::string;
using std::map;
using namespace std;
namespace po = boost::program_options;

TH1F *higgs_products = new TH1F("higgs_products","higgs_products",30,0,30);
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
    string outName = "test.root";
    string infile = "in.root";

    po::options_description desc("Allowed options");
    desc.add_options() //100000
      ("help", "produce help message")
      ("infile", po::value<string>(&infile)->default_value("in.root"), "input file name")
      ("Debug",   po::value<int>(&fDebug) ->default_value(0) ,     "Debug flag")
      ("radius",  po::value<double>(&radius)->default_value(0.4), "Jet radius")
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

    HiggsTagger = false; //Turn off for now (until I can figure out how to do this in Herwig)

    TChain *chain = new TChain("hepmc3_tree");
    const char* entry = infile.c_str();
    chain->Add(entry);
    nEvents = chain->GetEntries();
    FCNCAnalysis * analysis1 = new FCNCAnalysis(radius);
    analysis1->SetOutName(outName);
    analysis1->Begin();
    for (Int_t iev = 0; iev < nEvents; iev++) {
      if ((iev+1)%100==0) cout << iev << " " << nEvents << endl;
      analysis1->AnalyzeEvent(iev, chain);
    }
    analysis1->End();
    
    delete analysis1;
    
    return 0;
}
