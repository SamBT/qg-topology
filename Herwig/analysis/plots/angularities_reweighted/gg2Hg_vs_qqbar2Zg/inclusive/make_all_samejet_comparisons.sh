#!/bin/bash

root -b -q "samejet_diffsample.C(\"qjet\",\"pt\",\"p_{T} [GeV]\",2,1)"
root -b -q "samejet_diffsample.C(\"qjet\",\"eta\",\"#eta\",1,0)"
root -b -q "samejet_diffsample.C(\"qjet\",\"LHA\",\"LHA\",2,0)"
root -b -q "samejet_diffsample.C(\"qjet\",\"ptD\",\"p_{T}^{D}\",2,0)"
root -b -q "samejet_diffsample.C(\"qjet\",\"mass\",\"Mass\",2,0)"
root -b -q "samejet_diffsample.C(\"qjet\",\"multiplicity\",\"Multiplicity\",1,0)"
root -b -q "samejet_diffsample.C(\"qjet\",\"width\",\"Width\",2,0)"
#root -b -q "samejet_diffsample.C(\"qjet\",\"njets\",\"Number of Quark Jets\",1,0)"
root -b -q "samejet_diffsample.C(\"qjet\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",10,0)"
mv compare_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/angularity_comparisons/quark_jet_comparisons
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/angularity_comparisons/quark_jet_comparisons/*


root -b -q "samejet_diffsample.C(\"gjet\",\"pt\",\"p_{T} [GeV]\",2,1)"
root -b -q "samejet_diffsample.C(\"gjet\",\"eta\",\"#eta\",1,0)"
root -b -q "samejet_diffsample.C(\"gjet\",\"LHA\",\"LHA\",2,0)"
root -b -q "samejet_diffsample.C(\"gjet\",\"ptD\",\"p_{T}^{D}\",2,0)"
root -b -q "samejet_diffsample.C(\"gjet\",\"mass\",\"Mass\",2,0)"
root -b -q "samejet_diffsample.C(\"gjet\",\"multiplicity\",\"Multiplicity\",1,0)"
root -b -q "samejet_diffsample.C(\"gjet\",\"width\",\"Width\",2,0)"
#root -b -q "samejet_diffsample.C(\"gjet\",\"njets\",\"Number of Gluon Jets\",1,0)"
root -b -q "samejet_diffsample.C(\"gjet\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",10,0)"
mv compare_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/angularity_comparisons/gluon_jet_comparisons
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/angularity_comparisons/gluon_jet_comparisons/*