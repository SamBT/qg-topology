#!/bin/bash

path=/project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/UE_vs_noUE_study/with_UE/angularity_grid_justpp;
rads=(04 05 06 07 08 09 1 11 12 13 14 15);

for r in ${rads[@]};
do

root -b -q "kappa_beta_qg_sep.C(\"${r}\",1,0,0)"
#root -b -q "kappa_beta_qg_sep.C(\"${r}\",1,1,0)"
#root -b -q "kappa_beta_qg_sep.C(\"${r}\",1,0,1)"
#root -b -q "kappa_beta_qg_sep.C(\"${r}\",1,1,1)"
mv *angularity_grid* ${path}/Radius_${r}/quark_vs_gluon
chmod 777 ${path}/Radius_${r}/quark_vs_gluon/*

root -b -q "kappa_beta_samejet_sep.C(\"${r}\",\"qjet\",1,0,0)"
#root -b -q "kappa_beta_samejet_sep.C(\"${r}\",\"qjet\",1,1,0)"
#root -b -q "kappa_beta_samejet_sep.C(\"${r}\",\"qjet\",1,0,1)"
#root -b -q "kappa_beta_samejet_sep.C(\"${r}\",\"qjet\",1,1,1)"
mv *angularity_grid* ${path}/Radius_${r}/quark_vs_quark
chmod 777 ${path}/Radius_${r}/quark_vs_quark/*

root -b -q "kappa_beta_samejet_sep.C(\"${r}\",\"gjet\",1,0,0)"
#root -b -q "kappa_beta_samejet_sep.C(\"${r}\",\"gjet\",1,1,0)"
#root -b -q "kappa_beta_samejet_sep.C(\"${r}\",\"gjet\",1,0,1)"
#root -b -q "kappa_beta_samejet_sep.C(\"${r}\",\"gjet\",1,1,1)"
mv *angularity_grid* ${path}/Radius_${r}/gluon_vs_gluon
chmod 777 ${path}/Radius_${r}/gluon_vs_gluon/*

done