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

double Angularity(double kappa, double beta, double rad, fastjet::PseudoJet jet) {
  double z_i, theta_i;
  double angularity = 0;
  double sum_pt = 0;
  vector<fastjet::PseudoJet> pieces = jet.constituents();
  for(unsigned int r = 0; r <pieces.size(); r++) {
    sum_pt += pieces[r].pt();
  }
  for (unsigned int l = 0; l < pieces.size(); l++) {
    z_i = (pieces[l].pt())/sum_pt;
    theta_i = (pieces[l].delta_R(jet))/rad;
    angularity += pow(z_i,kappa)*pow(theta_i,beta);
  }
  return angularity;
}
