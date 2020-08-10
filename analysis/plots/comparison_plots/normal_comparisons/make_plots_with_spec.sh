#!/bin/bash

#general_comparison(TString sample1, TString sample2, TString type1, TString type2, TString var, TString xlabel, TString radius, int rebin)

radius=$1

jetloc=/project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study

root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"qjet\",\"qjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"qjet\",\"qjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"qjet\",\"qjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"qjet\",\"qjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"qjet\",\"qjet\",\"multiplicity\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"qjet\",\"qjet\",\"pt\",0,\"${radius}\",2)"
mv plot_* $jetloc/comparison_plots/dijets_vs_zplusjets/Radius_${radius}/compare_qjets

root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"qjet\",\"qjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"qjet\",\"qjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"qjet\",\"qjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"qjet\",\"qjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"qjet\",\"qjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/comparison_plots/dijets_vs_zplusjets/Radius_${radius}/compare_qjets

root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"multiplicity\",0,\"${radius}\",1)"
mv plot_* $jetloc/comparison_plots/gg2Hg_vs_qqbar2Zg/Radius_${radius}/compare_qjets

root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/comparison_plots/gg2Hg_vs_qqbar2Zg/Radius_${radius}/compare_qjets

##########################################

root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"gjet\",\"gjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"gjet\",\"gjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"gjet\",\"gjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"gjet\",\"gjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"gjet\",\"gjet\",\"multiplicity\",0,\"${radius}\",1)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"gjet\",\"gjet\",\"pt\",0,\"${radius}\",2)"
mv plot_* $jetloc/comparison_plots/dijets_vs_zplusjets/Radius_${radius}/compare_gjets

root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"gjet\",\"gjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"gjet\",\"gjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"gjet\",\"gjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"gjet\",\"gjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"zplusjets_rewt\",\"gjet\",\"gjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/comparison_plots/dijets_vs_zplusjets/Radius_${radius}/compare_gjets

root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"multiplicity\",0,\"${radius}\",1)"
mv plot_* $jetloc/comparison_plots/gg2Hg_vs_qqbar2Zg/Radius_${radius}/compare_gjets

root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/comparison_plots/gg2Hg_vs_qqbar2Zg/Radius_${radius}/compare_gjets

########################################

root -b -q "general_comparison.C(\"dijets_rewt\",\"dijets_rewt\",\"qjet\",\"gjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"dijets_rewt\",\"qjet\",\"gjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"dijets_rewt\",\"qjet\",\"gjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"dijets_rewt\",\"qjet\",\"gjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"dijets_rewt\",\"qjet\",\"gjet\",\"multiplicity\",0,\"${radius}\",1)"
mv plot_* $jetloc/dijets/Radius_${radius}/qjet_v_gjet

root -b -q "general_comparison.C(\"dijets_rewt\",\"dijets_rewt\",\"qjet\",\"gjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"dijets_rewt\",\"qjet\",\"gjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"dijets_rewt\",\"qjet\",\"gjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"dijets_rewt\",\"qjet\",\"gjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"dijets_rewt\",\"dijets_rewt\",\"qjet\",\"gjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/dijets/Radius_${radius}/qjet_v_gjet

root -b -q "general_comparison.C(\"zplusjets_rewt\",\"zplusjets_rewt\",\"qjet\",\"gjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"zplusjets_rewt\",\"qjet\",\"gjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"zplusjets_rewt\",\"qjet\",\"gjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"zplusjets_rewt\",\"qjet\",\"gjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"zplusjets_rewt\",\"qjet\",\"gjet\",\"multiplicity\",0,\"${radius}\",1)"
mv plot_* $jetloc/zplusjets/Radius_${radius}/qjet_v_gjet

root -b -q "general_comparison.C(\"zplusjets_rewt\",\"zplusjets_rewt\",\"qjet\",\"gjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"zplusjets_rewt\",\"qjet\",\"gjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"zplusjets_rewt\",\"qjet\",\"gjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"zplusjets_rewt\",\"qjet\",\"gjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"zplusjets_rewt\",\"zplusjets_rewt\",\"qjet\",\"gjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/zplusjets/Radius_${radius}/qjet_v_gjet

: '
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"gg2Hg_rewt\",\"qjet\",\"gjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"gg2Hg_rewt\",\"qjet\",\"gjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"gg2Hg_rewt\",\"qjet\",\"gjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"gg2Hg_rewt\",\"qjet\",\"gjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"gg2Hg_rewt\",\"qjet\",\"gjet\",\"multiplicity\",0,\"${radius}\",1)"
mv plot_* $jetloc/gg2Hg/Radius_${radius}/qjet_v_gjet

root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"gg2Hg_rewt\",\"qjet\",\"gjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"gg2Hg_rewt\",\"qjet\",\"gjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"gg2Hg_rewt\",\"qjet\",\"gjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"gg2Hg_rewt\",\"qjet\",\"gjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"gg2Hg_rewt\",\"gg2Hg_rewt\",\"qjet\",\"gjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/gg2Hg/Radius_${radius}/qjet_v_gjet

root -b -q "general_comparison.C(\"qqbar2Zg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"gjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"qqbar2Zg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"gjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"qqbar2Zg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"gjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"qqbar2Zg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"gjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"qqbar2Zg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"gjet\",\"multiplicity\",0,\"${radius}\",1)"
mv plot_* $jetloc/qqbar2Zg/Radius_${radius}/qjet_v_gjet

root -b -q "general_comparison.C(\"qqbar2Zg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"gjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"qqbar2Zg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"gjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"qqbar2Zg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"gjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"qqbar2Zg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"gjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"qqbar2Zg_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"gjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/qqbar2Zg/Radius_${radius}/qjet_v_gjet

root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_rewt\",\"qjet\",\"gjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_rewt\",\"qjet\",\"gjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_rewt\",\"qjet\",\"gjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_rewt\",\"qjet\",\"gjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_rewt\",\"qjet\",\"gjet\",\"multiplicity\",0,\"${radius}\",1)"
mv plot_* $jetloc/H2gg/Radius_${radius}/qjet_v_gjet

root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_rewt\",\"qjet\",\"gjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_rewt\",\"qjet\",\"gjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_rewt\",\"qjet\",\"gjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_rewt\",\"qjet\",\"gjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"H2gg_rewt\",\"qjet\",\"gjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/H2gg/Radius_${radius}/qjet_v_gjet

root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_rewt\",\"qjet\",\"gjet\",\"ptD\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_rewt\",\"qjet\",\"gjet\",\"LHA\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_rewt\",\"qjet\",\"gjet\",\"width\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_rewt\",\"qjet\",\"gjet\",\"mass\",0,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_rewt\",\"qjet\",\"gjet\",\"multiplicity\",0,\"${radius}\",1)"
mv plot_* $jetloc/H2qqbar/Radius_${radius}/qjet_v_gjet

root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_rewt\",\"qjet\",\"gjet\",\"ptD\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_rewt\",\"qjet\",\"gjet\",\"LHA\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_rewt\",\"qjet\",\"gjet\",\"width\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_rewt\",\"qjet\",\"gjet\",\"mass\",1,\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2qqbar_rewt\",\"H2qqbar_rewt\",\"qjet\",\"gjet\",\"multiplicity\",1,\"${radius}\",1)"
mv plot_* $jetloc/H2qqbar/Radius_${radius}/qjet_v_gjet
'
########################################

chmod -R 777 $jetloc/*