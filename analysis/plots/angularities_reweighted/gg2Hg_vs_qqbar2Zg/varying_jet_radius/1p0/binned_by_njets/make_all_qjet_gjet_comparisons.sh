#!/bin/bash

for i in `seq 2 3`; 
do
    root -b -q "quark_vs_gluon_samesample.C(\"dijets\",\"pt\",\"p_{T} [GeV]\",2,1,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"dijets\",\"eta\",\"#eta\",1,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"dijets\",\"LHA\",\"LHA\",2,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"dijets\",\"ptD\",\"p_{T}^{D}\",2,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"dijets\",\"mass\",\"Mass\",2,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"dijets\",\"multiplicity\",\"Multiplicity\",1,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"dijets\",\"width\",\"Width\",2,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"dijets\",\"njets\",\"Number of Jets\",1,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"dijets\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",10,0,$i)"
    rm /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_jets/dijets/${i}jet/*
    mv qjet_vs_gjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_jets/dijets/${i}jet/
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_jets/dijets/${i}jet/*
    
    root -b -q "quark_vs_gluon_samesample.C(\"zplusjets\",\"pt\",\"p_{T} [GeV]\",2,1,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"zplusjets\",\"eta\",\"#eta\",2,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"zplusjets\",\"LHA\",\"LHA\",2,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"zplusjets\",\"ptD\",\"p_{T}^{D}\",2,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"zplusjets\",\"mass\",\"Mass\",2,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"zplusjets\",\"multiplicity\",\"Multiplicity\",1,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"zplusjets\",\"width\",\"Width\",2,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"zplusjets\",\"njets\",\"Number of Jets\",1,0,$i)"
    root -b -q "quark_vs_gluon_samesample.C(\"zplusjets\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",10,0,$i)"
    rm /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_jets/zplusjets/${i}jet/*
    mv qjet_vs_gjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_jets/zplusjets/${i}jet/
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_vs_gluon_jets/zplusjets/${i}jet/*
done