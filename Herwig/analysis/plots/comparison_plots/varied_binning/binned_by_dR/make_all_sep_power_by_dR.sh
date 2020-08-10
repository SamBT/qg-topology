#!/bin/bash

root -b -q "quark_vs_gluon_angularity_by_dR.C(\"dijets\",\"LHA\",\"LHA\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/dijets/LHA
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/dijets/LHA/*
root -b -q "quark_vs_gluon_angularity_by_dR.C(\"dijets\",\"ptD\",\"p_{T}^{D}\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/dijets/ptD
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/dijets/ptD/*
root -b -q "quark_vs_gluon_angularity_by_dR.C(\"dijets\",\"mass\",\"Mass\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/dijets/Mass
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/dijets/Mass/*
root -b -q "quark_vs_gluon_angularity_by_dR.C(\"dijets\",\"multiplicity\",\"Multiplicity\",1)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/dijets/Multiplicity
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/dijets/Multiplicity/*
root -b -q "quark_vs_gluon_angularity_by_dR.C(\"dijets\",\"width\",\"Width\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/dijets/Width
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/dijets/Width/*

root -b -q "quark_vs_gluon_angularity_by_dR.C(\"zplusjets\",\"LHA\",\"LHA\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/zplusjets/LHA
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/zplusjets/LHA/*
root -b -q "quark_vs_gluon_angularity_by_dR.C(\"zplusjets\",\"ptD\",\"p_{T}^{D}\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/zplusjets/ptD
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/zplusjets/ptD/*
root -b -q "quark_vs_gluon_angularity_by_dR.C(\"zplusjets\",\"mass\",\"Mass\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/zplusjets/Mass
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/zplusjets/Mass/*
root -b -q "quark_vs_gluon_angularity_by_dR.C(\"zplusjets\",\"multiplicity\",\"Multiplicity\",1)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/zplusjets/Multiplicity
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/zplusjets/Multiplicity/*
root -b -q "quark_vs_gluon_angularity_by_dR.C(\"zplusjets\",\"width\",\"Width\",2)"
mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/zplusjets/Width
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/angularity_binned_by_dR/zplusjets/Width/*
