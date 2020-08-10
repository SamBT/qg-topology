#!/bin/bash

path=/project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/Herwig/summary_plots/individual_by_radius
angs=(LHA ptD multiplicity mass width);

q1=(dijets dijets zplusjets H2qqbar);
q2=(zplusjets H2qqbar H2qqbar H2qqbar_ee);
g1=(dijets dijets zplusjets qqbar2Zg H2gg);
g2=(zplusjets H2gg H2gg gg2Hg H2gg_ee);

for r in ${angs[@]};
do
    
    for i in `seq 0 3`; do
	root -b -q "individual_samejet_sep_by_R.C(\"${q1[$i]}\",\"${q2[$i]}\",\"${r}\",\"qjet\",1,0,0)"
	root -b -q "individual_samejet_sep_by_R.C(\"${q1[$i]}\",\"${q2[$i]}\",\"${r}\",\"qjet\",1,1,0)"
	root -b -q "individual_samejet_sep_by_R.C(\"${q1[$i]}\",\"${q2[$i]}\",\"${r}\",\"qjet\",1,0,1)"
	root -b -q "individual_samejet_sep_by_R.C(\"${q1[$i]}\",\"${q2[$i]}\",\"${r}\",\"qjet\",1,1,1)"
	mv *graph* ${path}/quark_vs_quark/${q1[$i]}_vs_${q2[$i]}/${r}
	chmod 777 ${path}/quark_vs_quark/${q1[$i]}_vs_${q2[$i]}/${r}/*
    done
    
    for j in `seq 0 4`; do
	root -b -q "individual_samejet_sep_by_R.C(\"${g1[$j]}\",\"${g2[$j]}\",\"${r}\",\"gjet\",1,0,0)"
	root -b -q "individual_samejet_sep_by_R.C(\"${g1[$j]}\",\"${g2[$j]}\",\"${r}\",\"gjet\",1,1,0)"
	root -b -q "individual_samejet_sep_by_R.C(\"${g1[$j]}\",\"${g2[$j]}\",\"${r}\",\"gjet\",1,0,1)"
	root -b -q "individual_samejet_sep_by_R.C(\"${g1[$j]}\",\"${g2[$j]}\",\"${r}\",\"gjet\",1,1,1)"
	mv *graph* ${path}/gluon_vs_gluon/${g1[$j]}_vs_${g2[$j]}/${r}
	chmod 777 ${path}/gluon_vs_gluon/${g1[$j]}_vs_${g2[$j]}/${r}/*
    done

done