#!/bin/bash

root -b -q "samejet_varying_radius.C(\"qjet\",\"LHA\",\"gg2Hg\",\"LHA\",2)"
root -b -q "samejet_varying_radius.C(\"qjet\",\"ptD\",\"gg2Hg\",\"p_{T}^{D}\",2)"
root -b -q "samejet_varying_radius.C(\"qjet\",\"mass\",\"gg2Hg\",\"Mass\",2)"
root -b -q "samejet_varying_radius.C(\"qjet\",\"multiplicity\",\"gg2Hg\",\"Multiplicity\",1)"
root -b -q "samejet_varying_radius.C(\"qjet\",\"width\",\"gg2Hg\",\"Width\",2)"
root -b -q "samejet_varying_radius.C(\"qjet\",\"nearestjetdR\",\"gg2Hg\",\"#DeltaR to Nearest Jet\",10)"

mv compare_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/comparison_of_all/quark_jets/gg2Hg
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/comparison_of_all/quark_jets/gg2Hg/*

root -b -q "samejet_varying_radius.C(\"gjet\",\"LHA\",\"gg2Hg\",\"LHA\",2)"
root -b -q "samejet_varying_radius.C(\"gjet\",\"ptD\",\"gg2Hg\",\"p_{T}^{D}\",2)"
root -b -q "samejet_varying_radius.C(\"gjet\",\"mass\",\"gg2Hg\",\"Mass\",2)"
root -b -q "samejet_varying_radius.C(\"gjet\",\"multiplicity\",\"gg2Hg\",\"Multiplicity\",1)"
root -b -q "samejet_varying_radius.C(\"gjet\",\"width\",\"gg2Hg\",\"Width\",2)"
root -b -q "samejet_varying_radius.C(\"gjet\",\"nearestjetdR\",\"gg2Hg\",\"#DeltaR to Nearest Jet\",10)"

mv compare_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/comparison_of_all/gluon_jets/gg2Hg
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/comparison_of_all/gluon_jets/gg2Hg/*

root -b -q "samejet_varying_radius.C(\"qjet\",\"LHA\",\"qqbar2Zg\",\"LHA\",2)"
root -b -q "samejet_varying_radius.C(\"qjet\",\"ptD\",\"qqbar2Zg\",\"p_{T}^{D}\",2)"
root -b -q "samejet_varying_radius.C(\"qjet\",\"mass\",\"qqbar2Zg\",\"Mass\",2)"
root -b -q "samejet_varying_radius.C(\"qjet\",\"multiplicity\",\"qqbar2Zg\",\"Multiplicity\",1)"
root -b -q "samejet_varying_radius.C(\"qjet\",\"width\",\"qqbar2Zg\",\"Width\",2)"
root -b -q "samejet_varying_radius.C(\"qjet\",\"nearestjetdR\",\"qqbar2Zg\",\"#DeltaR to Nearest Jet\",10)"

mv compare_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/comparison_of_all/quark_jets/qqbar2Zg
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/comparison_of_all/quark_jets/qqbar2Zg/*

root -b -q "samejet_varying_radius.C(\"gjet\",\"LHA\",\"qqbar2Zg\",\"LHA\",2)"
root -b -q "samejet_varying_radius.C(\"gjet\",\"ptD\",\"qqbar2Zg\",\"p_{T}^{D}\",2)"
root -b -q "samejet_varying_radius.C(\"gjet\",\"mass\",\"qqbar2Zg\",\"Mass\",2)"
root -b -q "samejet_varying_radius.C(\"gjet\",\"multiplicity\",\"qqbar2Zg\",\"Multiplicity\",1)"
root -b -q "samejet_varying_radius.C(\"gjet\",\"width\",\"qqbar2Zg\",\"Width\",2)"
root -b -q "samejet_varying_radius.C(\"gjet\",\"nearestjetdR\",\"qqbar2Zg\",\"#DeltaR to Nearest Jet\",10)"

mv compare_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/comparison_of_all/gluon_jets/qqbar2Zg
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/gg2Hg_vs_qqbar2Zg/varied_jet_radius/comparison_of_all/gluon_jets/qqbar2Zg/*