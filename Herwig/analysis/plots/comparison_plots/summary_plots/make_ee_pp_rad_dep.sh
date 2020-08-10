#!/bin/bash

path=/project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/Herwig/summary_plots/by_radius_ee_vs_pp
angs=(LHA ptD multiplicity mass width);

for r in ${angs[@]};
do

root -b -q "ee_vs_pp_samejet_by_R.C(\"${r}\",1,0,0)"
root -b -q "ee_vs_pp_samejet_by_R.C(\"${r}\",1,1,0)"
root -b -q "ee_vs_pp_samejet_by_R.C(\"${r}\",1,0,1)"
root -b -q "ee_vs_pp_samejet_by_R.C(\"${r}\",1,1,1)"
mv *by_radius_ee_vs_pp* ${path}/quark_vs_quark/${r}
chmod 777 ${path}/quark_vs_quark/${r}/*

root -b -q "ee_vs_pp_samejet_by_R.C(\"${r}\",1,0,0)"
root -b -q "ee_vs_pp_samejet_by_R.C(\"${r}\",1,1,0)"
root -b -q "ee_vs_pp_samejet_by_R.C(\"${r}\",1,0,1)"
root -b -q "ee_vs_pp_samejet_by_R.C(\"${r}\",1,1,1)"
mv *by_radius_ee_vs_pp* ${path}/gluon_vs_gluon/${r}
chmod 777 ${path}/gluon_vs_gluon/${r}/*

done