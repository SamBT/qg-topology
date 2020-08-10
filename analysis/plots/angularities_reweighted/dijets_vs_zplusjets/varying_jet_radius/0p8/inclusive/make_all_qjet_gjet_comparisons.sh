#!/bin/bash

root -b -q "qjet_vs_gjet_samesample.C(\"dijets\",\"pt\",\"p_{T} [GeV]\",2,1)"
root -b -q "qjet_vs_gjet_samesample.C(\"dijets\",\"eta\",\"#eta\",1,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"dijets\",\"LHA\",\"LHA\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"dijets\",\"ptD\",\"p_{T}^{D}\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"dijets\",\"mass\",\"Mass\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"dijets\",\"multiplicity\",\"Multiplicity\",1,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"dijets\",\"width\",\"Width\",2,0)"
#root -b -q "qjet_vs_gjet_samesample.C(\"dijets\",\"njets\",\"Number of Jets\",1,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"dijets\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",10,0)"
mv qjet_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/dijets_vs_zplusjets/varied_jet_radius/R0p8/quark_vs_gluon/dijets
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/dijets_vs_zplusjets/varied_jet_radius/R0p8/quark_vs_gluon/dijets/*


root -b -q "qjet_vs_gjet_samesample.C(\"zplusjets\",\"pt\",\"p_{T} [GeV]\",2,1)"
root -b -q "qjet_vs_gjet_samesample.C(\"zplusjets\",\"eta\",\"#eta\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"zplusjets\",\"LHA\",\"LHA\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"zplusjets\",\"ptD\",\"p_{T}^{D}\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"zplusjets\",\"mass\",\"Mass\",2,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"zplusjets\",\"multiplicity\",\"Multiplicity\",1,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"zplusjets\",\"width\",\"Width\",2,0)"
#root -b -q "qjet_vs_gjet_samesample.C(\"zplusjets\",\"njets\",\"Number of Jets\",1,0)"
root -b -q "qjet_vs_gjet_samesample.C(\"zplusjets\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",10,0)"
mv qjet_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/dijets_vs_zplusjets/varied_jet_radius/R0p8/quark_vs_gluon/zplusjets
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/dijets_vs_zplusjets/varied_jet_radius/R0p8/quark_vs_gluon/zplusjets/*