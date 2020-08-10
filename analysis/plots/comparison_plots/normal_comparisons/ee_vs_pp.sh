#!/bin/bash

#general_comparison(TString sample1, TString sample2, TString type1, TString type2, TString var, TString xlabel, TString radius, int rebin)

radius=$1

jetloc=/project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/comparison_plots/ee_vs_pp

root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_ee_rewt\",\"qjet\",\"qjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_ee_rewt\",\"qjet\",\"qjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_ee_rewt\",\"qjet\",\"qjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_ee_rewt\",\"qjet\",\"qjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_ee_rewt\",\"qjet\",\"qjet\",\"multiplicity\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_ee_rewt\",\"qjet\",\"qjet\",\"pt\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_ee_rewt\",\"qjet\",\"qjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_ee_rewt\",\"qjet\",\"qjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_ee_rewt\",\"qjet\",\"qjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_ee_rewt\",\"qjet\",\"qjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_ee_rewt\",\"qjet\",\"qjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/qjets/H2qqbar_ee_vs_pp/Radius_${radius}/

root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_ee_rewt\",\"gjet\",\"gjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_ee_rewt\",\"gjet\",\"gjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_ee_rewt\",\"gjet\",\"gjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_ee_rewt\",\"gjet\",\"gjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_ee_rewt\",\"gjet\",\"gjet\",\"multiplicity\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_ee_rewt\",\"gjet\",\"gjet\",\"pt\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_ee_rewt\",\"gjet\",\"gjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_ee_rewt\",\"gjet\",\"gjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_ee_rewt\",\"gjet\",\"gjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_ee_rewt\",\"gjet\",\"gjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_ee_rewt\",\"gjet\",\"gjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/gjets/H2gg_ee_vs_pp/Radius_${radius}/

chmod -R 777 $jetloc/*