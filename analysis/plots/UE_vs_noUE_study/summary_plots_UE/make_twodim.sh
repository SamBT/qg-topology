#!/bin/bash

root -b -q "twodim_radius_grid.C(\"dijets\",\"zplusjets\",\"qjet\",1,0,0)"
#root -b -q "twodim_radius_grid.C(\"dijets\",\"zplusjets\",\"qjet\",1,1,0)"
root -b -q "twodim_radius_grid.C(\"dijets\",\"zplusjets\",\"qjet\",1,0,1)"
#root -b -q "twodim_radius_grid.C(\"dijets\",\"zplusjets\",\"qjet\",1,1,1)"
mv *allrads_allangs* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/quark_jets/dijets_vs_zplusjets
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/quark_jets/dijets_vs_zplusjets/*

root -b -q "twodim_radius_grid.C(\"dijets\",\"H2qqbar\",\"qjet\",1,0,0)"
#root -b -q "twodim_radius_grid.C(\"dijets\",\"H2qqbar\",\"qjet\",1,1,0)"
root -b -q "twodim_radius_grid.C(\"dijets\",\"H2qqbar\",\"qjet\",1,0,1)"
#root -b -q "twodim_radius_grid.C(\"dijets\",\"H2qqbar\",\"qjet\",1,1,1)"
mv *allrads_allangs* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/quark_jets/dijets_vs_H2qqbar
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/quark_jets/dijets_vs_H2qqbar/*

root -b -q "twodim_radius_grid.C(\"zplusjets\",\"H2qqbar\",\"qjet\",1,0,0)"
#root -b -q "twodim_radius_grid.C(\"zplusjets\",\"H2qqbar\",\"qjet\",1,1,0)"
root -b -q "twodim_radius_grid.C(\"zplusjets\",\"H2qqbar\",\"qjet\",1,0,1)"
#root -b -q "twodim_radius_grid.C(\"zplusjets\",\"H2qqbar\",\"qjet\",1,1,1)"
mv *allrads_allangs* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/quark_jets/zplusjets_vs_H2qqbar
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/quark_jets/zplusjets_vs_H2qqbar/*

root -b -q "twodim_radius_grid.C(\"H2qqbar\",\"H2qqbar_ee\",\"qjet\",1,0,0)"
#root -b -q "twodim_radius_grid.C(\"H2qqbar\",\"H2qqbar_ee\",\"qjet\",1,1,0)"
root -b -q "twodim_radius_grid.C(\"H2qqbar\",\"H2qqbar_ee\",\"qjet\",1,0,1)"
#root -b -q "twodim_radius_grid.C(\"H2qqbar\",\"H2qqbar_ee\",\"qjet\",1,1,1)"
mv *allrads_allangs* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/quark_jets/H2qqbar_pp_vs_ee
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/quark_jets/H2qqbar_pp_vs_ee/*

#################################################

root -b -q "twodim_radius_grid.C(\"dijets\",\"zplusjets\",\"gjet\",1,0,0)"
#root -b -q "twodim_radius_grid.C(\"dijets\",\"zplusjets\",\"gjet\",1,1,0)"
root -b -q "twodim_radius_grid.C(\"dijets\",\"zplusjets\",\"gjet\",1,0,1)"
#root -b -q "twodim_radius_grid.C(\"dijets\",\"zplusjets\",\"gjet\",1,1,1)"
mv *allrads_allangs* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/gluon_jets/dijets_vs_zplusjets
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/gluon_jets/dijets_vs_zplusjets/*

root -b -q "twodim_radius_grid.C(\"dijets\",\"H2gg\",\"gjet\",1,0,0)"
#root -b -q "twodim_radius_grid.C(\"dijets\",\"H2gg\",\"gjet\",1,1,0)"
root -b -q "twodim_radius_grid.C(\"dijets\",\"H2gg\",\"gjet\",1,0,1)"
#root -b -q "twodim_radius_grid.C(\"dijets\",\"H2gg\",\"gjet\",1,1,1)"
mv *allrads_allangs* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/gluon_jets/dijets_vs_H2gg
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/gluon_jets/dijets_vs_H2gg/*

root -b -q "twodim_radius_grid.C(\"zplusjets\",\"H2gg\",\"gjet\",1,0,0)"
#root -b -q "twodim_radius_grid.C(\"zplusjets\",\"H2gg\",\"gjet\",1,1,0)"
root -b -q "twodim_radius_grid.C(\"zplusjets\",\"H2gg\",\"gjet\",1,0,1)"
#root -b -q "twodim_radius_grid.C(\"zplusjets\",\"H2gg\",\"gjet\",1,1,1)"
mv *allrads_allangs* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/gluon_jets/zplusjets_vs_H2gg
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/gluon_jets/zplusjets_vs_H2gg/*

root -b -q "twodim_radius_grid.C(\"H2gg\",\"H2gg_ee\",\"gjet\",1,0,0)"
#root -b -q "twodim_radius_grid.C(\"H2gg\",\"H2gg_ee\",\"gjet\",1,1,0)"
root -b -q "twodim_radius_grid.C(\"H2gg\",\"H2gg_ee\",\"gjet\",1,0,1)"
#root -b -q "twodim_radius_grid.C(\"H2gg\",\"H2gg_ee\",\"gjet\",1,1,1)"
mv *allrads_allangs* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/gluon_jets/H2gg_pp_vs_ee
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/gluon_jets/H2gg_pp_vs_ee/*

root -b -q "twodim_radius_grid.C(\"gg2Hg\",\"qqbar2Zg\",\"gjet\",1,0,0)"
#root -b -q "twodim_radius_grid.C(\"gg2Hg\",\"qqbar2Zg\",\"gjet\",1,1,0)"
root -b -q "twodim_radius_grid.C(\"gg2Hg\",\"qqbar2Zg\",\"gjet\",1,0,1)"
#root -b -q "twodim_radius_grid.C(\"gg2Hg\",\"qqbar2Zg\",\"gjet\",1,1,1)"
mv *allrads_allangs* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/gluon_jets/gg2Hg_vs_qqbar2Zg
chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/two_dimensional/gluon_jets/gg2Hg_vs_qqbar2Zg/*
