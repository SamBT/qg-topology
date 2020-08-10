#!/bin/bash

root -b -q "samejet_diffsample_by_eta.C(\"qjet\",\"LHA\",\"LHA\",2)"
mv *qjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/quark_jet_comparison/LHA
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/quark_jet_comparison/LHA/*
root -b -q "samejet_diffsample_by_eta.C(\"qjet\",\"ptD\",\"p_{T}^{D}\",2)"
mv *qjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/quark_jet_comparison/ptD
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/quark_jet_comparison/ptD/*
root -b -q "samejet_diffsample_by_eta.C(\"qjet\",\"mass\",\"Mass\",2)"
mv *qjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/quark_jet_comparison/Mass
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/quark_jet_comparison/Mass/*
root -b -q "samejet_diffsample_by_eta.C(\"qjet\",\"multiplicity\",\"Multiplicity\",1)"
mv *qjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/quark_jet_comparison/Multiplicity
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/quark_jet_comparison/Multiplicity/*
root -b -q "samejet_diffsample_by_eta.C(\"qjet\",\"width\",\"Width\",2)"
mv *qjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/quark_jet_comparison/Width
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/quark_jet_comparison/Width/*

root -b -q "samejet_diffsample_by_eta.C(\"gjet\",\"LHA\",\"LHA\",2)"
mv *gjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/gluon_jet_comparison/LHA
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/gluon_jet_comparison/LHA/*
root -b -q "samejet_diffsample_by_eta.C(\"gjet\",\"ptD\",\"p_{T}^{D}\",2)"
mv *gjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/gluon_jet_comparison/ptD
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/gluon_jet_comparison/ptD/*
root -b -q "samejet_diffsample_by_eta.C(\"gjet\",\"mass\",\"Mass\",2)"
mv *gjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/gluon_jet_comparison/Mass
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/gluon_jet_comparison/Mass/*
root -b -q "samejet_diffsample_by_eta.C(\"gjet\",\"multiplicity\",\"Multiplicity\",1)"
mv *gjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/gluon_jet_comparison/Multiplicity
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/gluon_jet_comparison/Multiplicity/*
root -b -q "samejet_diffsample_by_eta.C(\"gjet\",\"width\",\"Width\",2)"
mv *gjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/gluon_jet_comparison/Width
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_eta/gluon_jet_comparison/Width/*
