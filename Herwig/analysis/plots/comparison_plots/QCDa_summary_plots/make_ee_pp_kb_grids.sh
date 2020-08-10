#!/bin/bash

path=/project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/summary_plots/angularity_grid_ee_vs_pp;
rads=(04 05 06 07 08 09 1 11 12 13 14 15);

for r in ${rads[@]};
do

root -b -q "kappa_beta_ee_vs_pp.C(\"${r}\",1,0,0)"
root -b -q "kappa_beta_ee_vs_pp.C(\"${r}\",1,1,0)"
root -b -q "kappa_beta_ee_vs_pp.C(\"${r}\",1,0,1)"
root -b -q "kappa_beta_ee_vs_pp.C(\"${r}\",1,1,1)"
mv *angularity_grid* ${path}/Radius_${r}/
chmod 777 ${path}/Radius_${r}/*

done