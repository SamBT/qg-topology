#!/bin/bash

for i in `seq 2 3`;
do
    root -b -q "quark_vs_gluon_angularity_by_dR.C(\"dijets\",\"LHA\",\"LHA\",2,$i)"
    mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/dijets/${i}jet/LHA
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/dijets/${i}jet/LHA/*
    root -b -q "quark_vs_gluon_angularity_by_dR.C(\"dijets\",\"ptD\",\"p_{T}^{D}\",2,$i)"
    mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/dijets/${i}jet/ptD
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/dijets/${i}jet/ptD/*
    root -b -q "quark_vs_gluon_angularity_by_dR.C(\"dijets\",\"mass\",\"Mass\",2,$i)"
    mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/dijets/${i}jet/Mass
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/dijets/${i}jet/Mass/*
    root -b -q "quark_vs_gluon_angularity_by_dR.C(\"dijets\",\"multiplicity\",\"Multiplicity\",1,$i)"
    mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/dijets/${i}jet/Multiplicity
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/dijets/${i}jet/Multiplicity/*
    root -b -q "quark_vs_gluon_angularity_by_dR.C(\"dijets\",\"width\",\"Width\",2,$i)"
    mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/dijets/${i}jet/Width
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/dijets/${i}jet/Width/*
    
    root -b -q "quark_vs_gluon_angularity_by_dR.C(\"zplusjets\",\"LHA\",\"LHA\",2,$i)"
    mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/zplusjets/${i}jet/LHA
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/zplusjets/${i}jet/LHA/*
    root -b -q "quark_vs_gluon_angularity_by_dR.C(\"zplusjets\",\"ptD\",\"p_{T}^{D}\",2,$i)"
    mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/zplusjets/${i}jet/ptD
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/zplusjets/${i}jet/ptD/*
    root -b -q "quark_vs_gluon_angularity_by_dR.C(\"zplusjets\",\"mass\",\"Mass\",2,$i)"
    mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/zplusjets/${i}jet/Mass
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/zplusjets/${i}jet/Mass/*
    root -b -q "quark_vs_gluon_angularity_by_dR.C(\"zplusjets\",\"multiplicity\",\"Multiplicity\",1,$i)"
    mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/zplusjets/${i}jet/Multiplicity
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/zplusjets/${i}jet/Multiplicity/*
    root -b -q "quark_vs_gluon_angularity_by_dR.C(\"zplusjets\",\"width\",\"Width\",2,$i)"
    mv qjet_vs_gjet_* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/zplusjets/${i}jet/Width
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_separation_by_dR_nearest_jet/zplusjets/${i}jet/Width/*
done