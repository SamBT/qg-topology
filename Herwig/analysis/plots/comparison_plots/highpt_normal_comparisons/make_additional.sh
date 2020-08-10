#!/bin/bash

#general_comparison(TString sample1, TString sample2, TString type1, TString type2, TString var, TString xlabel, TString radius, int rebin)

radius=$1

jetloc=/project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/highpt_comparison_plots/

root -b -q "general_comparison.C(\"dijets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"ptD\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"LHA\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"width\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"mass\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"multiplicity\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"pt\",0,\"${radius}\",1)"
mv plot_* $jetloc/quark_jet_comparisons/dijets_vs_H2qqbar/Radius_${radius}

root -b -q "general_comparison.C(\"dijets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"ptD\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"LHA\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"width\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"mass\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/quark_jet_comparisons/dijets_vs_H2qqbar/Radius_${radius}

root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"ptD\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"LHA\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"width\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"mass\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"multiplicity\",0,\"${radius}\",1)"
mv plot_* $jetloc/quark_jet_comparisons/zplusjets_vs_H2qqbar/Radius_${radius}

root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"ptD\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"LHA\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"width\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"mass\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2qqbar_rewt\",\"qjet\",\"qjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/quark_jet_comparisons/zplusjets_vs_H2qqbar/Radius_${radius}

##########################################

root -b -q "general_comparison.C(\"dijets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"ptD\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"LHA\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"width\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"mass\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"multiplicity\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"pt\",0,\"${radius}\",1)"
mv plot_* $jetloc/gluon_jet_comparisons/dijets_vs_H2gg/Radius_${radius}

root -b -q "general_comparison.C(\"dijets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"ptD\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"LHA\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"width\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"mass\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/gluon_jet_comparisons/dijets_vs_H2gg/Radius_${radius}

root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"ptD\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"LHA\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"width\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"mass\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"multiplicity\",0,\"${radius}\",1)"
mv plot_* $jetloc/gluon_jet_comparisons/zplusjets_vs_H2gg/Radius_${radius}

root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"ptD\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"LHA\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"width\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"mass\",1,\"${radius}\",1)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"H2gg_rewt\",\"gjet\",\"gjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/gluon_jet_comparisons/zplusjets_vs_H2gg/Radius_${radius}

chmod -R 777 $jetloc/*