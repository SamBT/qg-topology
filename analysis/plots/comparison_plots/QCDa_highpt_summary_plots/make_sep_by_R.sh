#!/bin/bash

path=/project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/QCDAware_tagging/highpt_summary_plots/by_radius_justpp
angs=(LHA ptD multiplicity mass width);

for r in ${angs[@]};
do

root -b -q "qg_sep_by_R.C(\"${r}\",1,0,0)"
#root -b -q "qg_sep_by_R.C(\"${r}\",1,1,0)"
root -b -q "qg_sep_by_R.C(\"${r}\",1,0,1)"
#root -b -q "qg_sep_by_R.C(\"${r}\",1,1,1)"
mv *graph* ${path}/quark_vs_gluon/${r}
chmod 777 ${path}/quark_vs_gluon/${r}/*

root -b -q "samejet_sep_by_R.C(\"${r}\",\"qjet\",1,0,0)"
#root -b -q "samejet_sep_by_R.C(\"${r}\",\"qjet\",1,1,0)"
root -b -q "samejet_sep_by_R.C(\"${r}\",\"qjet\",1,0,1)"
#root -b -q "samejet_sep_by_R.C(\"${r}\",\"qjet\",1,1,1)"
mv *graph* ${path}/quark_vs_quark/${r}
chmod 777 ${path}/quark_vs_quark/${r}/*

root -b -q "samejet_sep_by_R.C(\"${r}\",\"gjet\",1,0,0)"
#root -b -q "samejet_sep_by_R.C(\"${r}\",\"gjet\",1,1,0)"
root -b -q "samejet_sep_by_R.C(\"${r}\",\"gjet\",1,0,1)"
#root -b -q "samejet_sep_by_R.C(\"${r}\",\"gjet\",1,1,1)"
mv *graph* ${path}/gluon_vs_gluon/${r}
chmod 777 ${path}/gluon_vs_gluon/${r}/*

done