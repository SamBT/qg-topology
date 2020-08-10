#!/bin/bash

root -b -q "qjet_vs_gjet_samesample.C(\"gg2Hg\",\"pt\",\"p_{T} [GeV]\",2,1)"
root -b -q "qjet_vs_gjet_samesample.C(\"gg2Hg\",\"eta\",\"#eta\",1,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"gg2Hg\",\"LHA\",\"LHA\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"gg2Hg\",\"ptD\",\"p_{T}^{D}\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"gg2Hg\",\"mass\",\"Mass\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"gg2Hg\",\"multiplicity\",\"Multiplicity\",1,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"gg2Hg\",\"width\",\"Width\",2,0)"
#root -b -q "qjet_vs_gjet_samesample.C(\"gg2Hg\",\"njets\",\"Number of Jets\",1,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"gg2Hg\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",10,0)"
mv qjet_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/R0p7/quark_vs_gluon/gg2Hg
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/R0p7/quark_vs_gluon/gg2Hg/*


root -b -q "qjet_vs_gjet_samesample.C(\"qqbar2Zg\",\"pt\",\"p_{T} [GeV]\",2,1)"
root -b -q "qjet_vs_gjet_samesample.C(\"qqbar2Zg\",\"eta\",\"#eta\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"qqbar2Zg\",\"LHA\",\"LHA\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"qqbar2Zg\",\"ptD\",\"p_{T}^{D}\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"qqbar2Zg\",\"mass\",\"Mass\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"qqbar2Zg\",\"multiplicity\",\"Multiplicity\",1,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"qqbar2Zg\",\"width\",\"Width\",2,0)"
#root -b -q "qjet_vs_gjet_samesample.C(\"qqbar2Zg\",\"njets\",\"Number of Jets\",1,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"qqbar2Zg\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",10,0)"
mv qjet_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/R0p7/quark_vs_gluon/qqbar2Zg
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/R0p7/quark_vs_gluon/qqbar2Zg/*