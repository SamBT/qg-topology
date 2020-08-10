#!/bin/bash

root -b -q "quark_vs_gluon_angularity_by_eta.C(\"dijets\",\"LHA\",\"LHA\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/dijets/LHA
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/dijets/LHA/*
root -b -q "quark_vs_gluon_angularity_by_eta.C(\"dijets\",\"ptD\",\"p_{T}^{D}\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/dijets/ptD
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/dijets/ptD/*
root -b -q "quark_vs_gluon_angularity_by_eta.C(\"dijets\",\"mass\",\"Mass\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/dijets/Mass
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/dijets/Mass/*
root -b -q "quark_vs_gluon_angularity_by_eta.C(\"dijets\",\"multiplicity\",\"Multiplicity\",1)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/dijets/Multiplicity
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/dijets/Multiplicity/*
root -b -q "quark_vs_gluon_angularity_by_eta.C(\"dijets\",\"width\",\"Width\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/dijets/Width
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/dijets/Width/*

root -b -q "quark_vs_gluon_angularity_by_eta.C(\"zplusjets\",\"LHA\",\"LHA\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/zplusjets/LHA
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/zplusjets/LHA/*
root -b -q "quark_vs_gluon_angularity_by_eta.C(\"zplusjets\",\"ptD\",\"p_{T}^{D}\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/zplusjets/ptD
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/zplusjets/ptD/*
root -b -q "quark_vs_gluon_angularity_by_eta.C(\"zplusjets\",\"mass\",\"Mass\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/zplusjets/Mass
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/zplusjets/Mass/*
root -b -q "quark_vs_gluon_angularity_by_eta.C(\"zplusjets\",\"multiplicity\",\"Multiplicity\",1)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/zplusjets/Multiplicity
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/zplusjets/Multiplicity/*
root -b -q "quark_vs_gluon_angularity_by_eta.C(\"zplusjets\",\"width\",\"Width\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/zplusjets/Width
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/binned_by_eta/quark_vs_gluon_jets/zplusjets/Width/*
