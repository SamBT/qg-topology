#!/bin/bash

for i in `seq 2 3`;
do
    root -b -q "samejet_diffsample.C(\"qjet\",\"pt\",\"p_{T} [GeV]\",2,1,$i)"
    root -b -q "samejet_diffsample.C(\"qjet\",\"eta\",\"#eta\",1,0,$i)"
    root -b -q "samejet_diffsample.C(\"qjet\",\"LHA\",\"LHA\",2,0,$i)"
    root -b -q "samejet_diffsample.C(\"qjet\",\"ptD\",\"p_{T}^{D}\",2,0,$i)"
    root -b -q "samejet_diffsample.C(\"qjet\",\"mass\",\"Mass\",2,0,$i)"
    root -b -q "samejet_diffsample.C(\"qjet\",\"multiplicity\",\"Multiplicity\",1,0,$i)"
    root -b -q "samejet_diffsample.C(\"qjet\",\"width\",\"Width\",2,0,$i)"
    root -b -q "samejet_diffsample.C(\"qjet\",\"njets\",\"Number of Quark Jets\",1,0,$i)"
    root -b -q "samejet_diffsample.C(\"qjet\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",10,0,$i)"
    mv compare_qjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_jet_comparisons/${i}jet/
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_jet_comparisons/${i}jet/*
    
    root -b -q "samejet_diffsample.C(\"gjet\",\"pt\",\"p_{T} [GeV]\",2,1,$i)"
    root -b -q "samejet_diffsample.C(\"gjet\",\"eta\",\"#eta\",1,0,$i)"
    root -b -q "samejet_diffsample.C(\"gjet\",\"LHA\",\"LHA\",2,0,$i)"
    root -b -q "samejet_diffsample.C(\"gjet\",\"ptD\",\"p_{T}^{D}\",2,0,$i)"
    root -b -q "samejet_diffsample.C(\"gjet\",\"mass\",\"Mass\",2,0,$i)"
    root -b -q "samejet_diffsample.C(\"gjet\",\"multiplicity\",\"Multiplicity\",1,0,$i)"
    root -b -q "samejet_diffsample.C(\"gjet\",\"width\",\"Width\",2,0,$i)"
    root -b -q "samejet_diffsample.C(\"gjet\",\"njets\",\"Number of Gluon Jets\",1,0,$i)"
    root -b -q "samejet_diffsample.C(\"gjet\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",10,0,$i)"
    mv compare_gjet* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/gluon_jet_comparisons/${i}jet/
    chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/gluon_jet_comparisons/${i}jet/*
done