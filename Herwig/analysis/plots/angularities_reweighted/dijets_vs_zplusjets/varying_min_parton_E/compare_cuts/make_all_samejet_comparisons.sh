#!/bin/bash

root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"LHA\",\"dijets\",\"LHA\",2)"
root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"ptD\",\"dijets\",\"p_{T}^{D}\",2)"
root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"mass\",\"dijets\",\"Mass\",2)"
root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"multiplicity\",\"dijets\",\"Multiplicity\",1)"
root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"width\",\"dijets\",\"Width\",2)"
root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"nearestjetdR\",\"dijets\",\"#DeltaR to Nearest Jet\",10)"

mv compare_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/varied_parton_Ecut/compare_all/quark_jets/dijets
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/varied_parton_Ecut/compare_all/quark_jets/dijets/*

root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"LHA\",\"dijets\",\"LHA\",2)"
root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"ptD\",\"dijets\",\"p_{T}^{D}\",2)"
root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"mass\",\"dijets\",\"Mass\",2)"
root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"multiplicity\",\"dijets\",\"Multiplicity\",1)"
root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"width\",\"dijets\",\"Width\",2)"
root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"nearestjetdR\",\"dijets\",\"#DeltaR to Nearest Jet\",10)"

mv compare_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/varied_parton_Ecut/compare_all/gluon_jets/dijets
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/varied_parton_Ecut/compare_all/gluon_jets/dijets/*

root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"LHA\",\"zplusjets\",\"LHA\",2)"
root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"ptD\",\"zplusjets\",\"p_{T}^{D}\",2)"
root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"mass\",\"zplusjets\",\"Mass\",2)"
root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"multiplicity\",\"zplusjets\",\"Multiplicity\",1)"
root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"width\",\"zplusjets\",\"Width\",2)"
root -b -q "samejet_varying_min_partonE.C(\"qjet\",\"nearestjetdR\",\"zplusjets\",\"#DeltaR to Nearest Jet\",10)"

mv compare_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/varied_parton_Ecut/compare_all/quark_jets/zplusjets
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/varied_parton_Ecut/compare_all/quark_jets/zplusjets/*

root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"LHA\",\"zplusjets\",\"LHA\",2)"
root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"ptD\",\"zplusjets\",\"p_{T}^{D}\",2)"
root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"mass\",\"zplusjets\",\"Mass\",2)"
root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"multiplicity\",\"zplusjets\",\"Multiplicity\",1)"
root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"width\",\"zplusjets\",\"Width\",2)"
root -b -q "samejet_varying_min_partonE.C(\"gjet\",\"nearestjetdR\",\"zplusjets\",\"#DeltaR to Nearest Jet\",10)"

mv compare_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/varied_parton_Ecut/compare_all/gluon_jets/zplusjets
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/varied_parton_Ecut/compare_all/gluon_jets/zplusjets/*