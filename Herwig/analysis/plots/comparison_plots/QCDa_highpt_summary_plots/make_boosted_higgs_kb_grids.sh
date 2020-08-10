#!/bin/bash

path=/project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/QCDAware_tagging/highpt_summary_plots/grids_compare_H_boosted_unboosted
rads=(04 05 06 07 08 09 1 11 12 13 14 15);

for r in ${rads[@]};
do

root -b -q "boosted_higgs_kb_grid.C(\"${r}\",\"qjet\",1,0,0)"
root -b -q "boosted_higgs_kb_grid.C(\"${r}\",\"qjet\",1,1,0)"
root -b -q "boosted_higgs_kb_grid.C(\"${r}\",\"qjet\",1,0,1)"
root -b -q "boosted_higgs_kb_grid.C(\"${r}\",\"qjet\",1,1,1)"
mv *angularity_grid* ${path}/Radius_${r}/quark_vs_quark
chmod 777 ${path}/Radius_${r}/quark_vs_quark/*

root -b -q "boosted_higgs_kb_grid.C(\"${r}\",\"gjet\",1,0,0)"
root -b -q "boosted_higgs_kb_grid.C(\"${r}\",\"gjet\",1,1,0)"
root -b -q "boosted_higgs_kb_grid.C(\"${r}\",\"gjet\",1,0,1)"
root -b -q "boosted_higgs_kb_grid.C(\"${r}\",\"gjet\",1,1,1)"
mv *angularity_grid* ${path}/Radius_${r}/gluon_vs_gluon
chmod 777 ${path}/Radius_${r}/gluon_vs_gluon/*

done