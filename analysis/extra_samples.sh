#!/bin/bash

path=/project/projectdirs/atlas/sambt/Pythia_output_final/lowpT
radii=(0p2 0p3 0p4 0p5 0p6 0p7 0p8 0p9 1p0 1p1 1p2 1p3 1p4 1p5);
radii2=(02 03 04 05 06 07 08 09 1 11 12 13 14 15)

make analysis
make analysis_rewt

mkdir extra_analysis
cd extra_analysis

counter=0;
for r in ${radii[@]};
do

rad=${radii2[$counter]};
path2=../extra_analysis_output/Radius_${rad};

../bin/analysis ${path}/Zplusjets_100k_R${r}/Zplusjets_100k_R${r}.root
mv output.root ${path2}/output_zplusjets.root

../bin/analysis ${path}/Dijets_100k_R${r}/Dijets_100k_R${r}.root
mv output.root ${path2}/output_dijets.root

../bin/analysis ${path}/H2gg_100k_R${r}/H2gg_100k_R${r}.root
mv output.root ${path2}/output_H2gg.root

../bin/analysis ${path}/H2qqbar_100k_R${r}/H2qqbar_100k_R${r}.root
mv output.root ${path2}/output_H2qqbar.root

##### Re-weighting #####

../bin/analysis_rewt ${path2}/output_zplusjets.root ${path2}/output_zplusjets.root ${path}/Zplusjets_100k_R${r}/Zplusjets_100k_R${r}.root
mv output.root ${path2}/output_zplusjets_rewt.root

../bin/analysis_rewt ${path2}/output_dijets.root ${path2}/output_zplusjets.root ${path}/Dijets_100k_R${r}/Dijets_100k_R${r}.root
mv output.root ${path2}/output_dijets_rewt.root

../bin/analysis_rewt ${path2}/output_H2gg.root ${path2}/output_zplusjets.root ${path}/H2gg_100k_R${r}/H2gg_100k_R${r}.root
mv output.root ${path2}/output_H2gg_rewt.root

../bin/analysis_rewt ${path2}/output_H2qqbar.root ${path2}/output_zplusjets.root ${path}/H2qqbar_100k_R${r}/H2qqbar_100k_R${r}.root
mv output.root ${path2}/output_H2qqbar_rewt.root

counter=$((counter+1));
done

cd ..
rm -rf extra_analysis