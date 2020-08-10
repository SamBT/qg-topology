#!/bin/bash

#general_comparison(TString sample1, TString sample2, TString type1, TString type2, TString var, TString xlabel, TString radius, int rebin)

radius=$1

jetloc=/project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/comparison_plots/pure_vs_impure_comparison

root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"zplusjets\",\"qjet\",\"qjet\",\"ptD\",\"p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"zplusjets\",\"qjet\",\"qjet\",\"LHA\",\"LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"zplusjets\",\"qjet\",\"qjet\",\"width\",\"Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"zplusjets\",\"qjet\",\"qjet\",\"mass\",\"Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"zplusjets\",\"qjet\",\"qjet\",\"multiplicity\",\"Multiplicity\",\"${radius}\",1)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"zplusjets\",\"qjet\",\"qjet\",\"leading_ptD\",\"Leading Jet p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"zplusjets\",\"qjet\",\"qjet\",\"leading_LHA\",\"Leading Jet LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"zplusjets\",\"qjet\",\"qjet\",\"leading_width\",\"Leading Jet Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"zplusjets\",\"qjet\",\"qjet\",\"leading_mass\",\"Leading Jet Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"zplusjets\",\"qjet\",\"qjet\",\"leading_multiplicity\",\"Leading Jet Multiplicity\",\"${radius}\",1)"
mv plot_* $jetloc/qjets/W2qqbar_vs_zplusjets/Radius_${radius}/

root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"dijets_rewt\",\"qjet\",\"qjet\",\"ptD\",\"p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"dijets_rewt\",\"qjet\",\"qjet\",\"LHA\",\"LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"dijets_rewt\",\"qjet\",\"qjet\",\"width\",\"Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"dijets_rewt\",\"qjet\",\"qjet\",\"mass\",\"Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"dijets_rewt\",\"qjet\",\"qjet\",\"multiplicity\",\"Multiplicity\",\"${radius}\",1)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"dijets_rewt\",\"qjet\",\"qjet\",\"leading_ptD\",\"Leading Jet p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"dijets_rewt\",\"qjet\",\"qjet\",\"leading_LHA\",\"Leading Jet LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"dijets_rewt\",\"qjet\",\"qjet\",\"leading_width\",\"Leading Jet Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"dijets_rewt\",\"qjet\",\"qjet\",\"leading_mass\",\"Leading Jet Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"dijets_rewt\",\"qjet\",\"qjet\",\"leading_multiplicity\",\"Leading Jet Multiplicity\",\"${radius}\",1)"
mv plot_* $jetloc/qjets/W2qqbar_vs_dijets/Radius_${radius}/

root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"gg2Hg_rewt\",\"qjet\",\"qjet\",\"ptD\",\"p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"gg2Hg_rewt\",\"qjet\",\"qjet\",\"LHA\",\"LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"gg2Hg_rewt\",\"qjet\",\"qjet\",\"width\",\"Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"gg2Hg_rewt\",\"qjet\",\"qjet\",\"mass\",\"Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"gg2Hg_rewt\",\"qjet\",\"qjet\",\"multiplicity\",\"Multiplicity\",\"${radius}\",1)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"gg2Hg_rewt\",\"qjet\",\"qjet\",\"leading_ptD\",\"Leading Jet p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"gg2Hg_rewt\",\"qjet\",\"qjet\",\"leading_LHA\",\"Leading Jet LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"gg2Hg_rewt\",\"qjet\",\"qjet\",\"leading_width\",\"Leading Jet Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"gg2Hg_rewt\",\"qjet\",\"qjet\",\"leading_mass\",\"Leading Jet Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"gg2Hg_rewt\",\"qjet\",\"qjet\",\"leading_multiplicity\",\"Leading Jet Multiplicity\",\"${radius}\",1)"
mv plot_* $jetloc/qjets/W2qqbar_vs_gg2Hg/Radius_${radius}/

root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"ptD\",\"p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"LHA\",\"LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"width\",\"Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"mass\",\"Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"multiplicity\",\"Multiplicity\",\"${radius}\",1)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"leading_ptD\",\"Leading Jet p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"leading_LHA\",\"Leading Jet LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"leading_width\",\"Leading Jet Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"leading_mass\",\"Leading Jet Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"W2qqbar_rewt\",\"qqbar2Zg_rewt\",\"qjet\",\"qjet\",\"leading_multiplicity\",\"Leading Jet Multiplicity\",\"${radius}\",1)"
mv plot_* $jetloc/qjets/W2qqbar_vs_qqbar2Zg/Radius_${radius}/

############################################

root -b -q "general_comparison.C(\"H2gg_rewt\",\"zplusjets\",\"gjet\",\"gjet\",\"ptD\",\"p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"zplusjets\",\"gjet\",\"gjet\",\"LHA\",\"LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"zplusjets\",\"gjet\",\"gjet\",\"width\",\"Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"zplusjets\",\"gjet\",\"gjet\",\"mass\",\"Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"zplusjets\",\"gjet\",\"gjet\",\"multiplicity\",\"Multiplicity\",\"${radius}\",1)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"zplusjets\",\"gjet\",\"gjet\",\"leading_ptD\",\"Leading Jet p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"zplusjets\",\"gjet\",\"gjet\",\"leading_LHA\",\"Leading Jet LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"zplusjets\",\"gjet\",\"gjet\",\"leading_width\",\"Leading Jet Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"zplusjets\",\"gjet\",\"gjet\",\"leading_mass\",\"Leading Jet Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"zplusjets\",\"gjet\",\"gjet\",\"leading_multiplicity\",\"Leading Jet Multiplicity\",\"${radius}\",1)"
mv plot_* $jetloc/gjets/H2gg_vs_zplusjets/Radius_${radius}/

root -b -q "general_comparison.C(\"H2gg_rewt\",\"dijets_rewt\",\"gjet\",\"gjet\",\"ptD\",\"p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"dijets_rewt\",\"gjet\",\"gjet\",\"LHA\",\"LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"dijets_rewt\",\"gjet\",\"gjet\",\"width\",\"Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"dijets_rewt\",\"gjet\",\"gjet\",\"mass\",\"Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"dijets_rewt\",\"gjet\",\"gjet\",\"multiplicity\",\"Multiplicity\",\"${radius}\",1)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"dijets_rewt\",\"gjet\",\"gjet\",\"leading_ptD\",\"Leading Jet p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"dijets_rewt\",\"gjet\",\"gjet\",\"leading_LHA\",\"Leading Jet LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"dijets_rewt\",\"gjet\",\"gjet\",\"leading_width\",\"Leading Jet Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"dijets_rewt\",\"gjet\",\"gjet\",\"leading_mass\",\"Leading Jet Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"dijets_rewt\",\"gjet\",\"gjet\",\"leading_multiplicity\",\"Leading Jet Multiplicity\",\"${radius}\",1)"
mv plot_* $jetloc/gjets/H2gg_vs_dijets/Radius_${radius}/

root -b -q "general_comparison.C(\"H2gg_rewt\",\"gg2Hg_rewt\",\"gjet\",\"gjet\",\"ptD\",\"p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"gg2Hg_rewt\",\"gjet\",\"gjet\",\"LHA\",\"LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"gg2Hg_rewt\",\"gjet\",\"gjet\",\"width\",\"Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"gg2Hg_rewt\",\"gjet\",\"gjet\",\"mass\",\"Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"gg2Hg_rewt\",\"gjet\",\"gjet\",\"multiplicity\",\"Multiplicity\",\"${radius}\",1)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"gg2Hg_rewt\",\"gjet\",\"gjet\",\"leading_ptD\",\"Leading Jet p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"gg2Hg_rewt\",\"gjet\",\"gjet\",\"leading_LHA\",\"Leading Jet LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"gg2Hg_rewt\",\"gjet\",\"gjet\",\"leading_width\",\"Leading Jet Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"gg2Hg_rewt\",\"gjet\",\"gjet\",\"leading_mass\",\"Leading Jet Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"gg2Hg_rewt\",\"gjet\",\"gjet\",\"leading_multiplicity\",\"Leading Jet Multiplicity\",\"${radius}\",1)"
mv plot_* $jetloc/gjets/H2gg_vs_gg2Hg/Radius_${radius}/

root -b -q "general_comparison.C(\"H2gg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"ptD\",\"p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"LHA\",\"LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"width\",\"Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"mass\",\"Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"multiplicity\",\"Multiplicity\",\"${radius}\",1)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"leading_ptD\",\"Leading Jet p_{T}^{D}\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"leading_LHA\",\"Leading Jet LHA\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"leading_width\",\"Leading Jet Width\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"leading_mass\",\"Leading Jet Mass\",\"${radius}\",2)"
root -b -q "general_comparison.C(\"H2gg_rewt\",\"qqbar2Zg_rewt\",\"gjet\",\"gjet\",\"leading_multiplicity\",\"Leading Jet Multiplicity\",\"${radius}\",1)"
mv plot_* $jetloc/gjets/H2gg_vs_qqbar2Zg/Radius_${radius}/

chmod -R 777 $jetloc/*