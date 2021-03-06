#!/bin/bash

path=/project/projectdirs/atlas/sambt/Herwig_output/pthat_min200_max400
radii=(0p4 0p5 0p6 0p7 0p8 0p9 1p0 1p1 1p2 1p3 1p4 1p5);
radii2=(04 05 06 07 08 09 1 11 12 13 14 15)

make highpt_analysis
make highpt_analysis_rewt

mkdir highpt_reg_analysis
cd highpt_reg_analysis

counter=0;
for r in ${radii[@]};
do

rad=${radii2[$counter]};
path2=../analysis_output_highpt/Radius_${rad};

../bin/highpt_analysis ${path}/Zplusjets_1M_R${r}/Zplusjets_1M_R${r}.root
mv output.root ${path2}/output_zplusjets.root

../bin/highpt_analysis ${path}/Dijets_1M_R${r}/Dijets_1M_R${r}.root
mv output.root ${path2}/output_dijets.root

../bin/highpt_analysis ${path}/qqbar2Zg_1M_R${r}/qqbar2Zg_1M_R${r}.root
mv output.root ${path2}/output_qqbar2Zg.root

../bin/highpt_analysis ${path}/gg2Hg_1M_R${r}/gg2Hg_1M_R${r}.root
mv output.root ${path2}/output_gg2Hg.root

../bin/highpt_analysis ${path}/H2gg_1M_R${r}/H2gg_1M_R${r}.root
mv output.root ${path2}/output_H2gg.root

../bin/highpt_analysis ${path}/H2qqbar_1M_R${r}/H2qqbar_1M_R${r}.root
mv output.root ${path2}/output_H2qqbar.root

../bin/highpt_analysis ${path}/H2gg_boosted_1M_R${r}/H2gg_boosted_1M_R${r}.root
mv output.root ${path2}/output_H2gg_boosted.root

../bin/highpt_analysis ${path}/H2qqbar_boosted_1M_R${r}/H2qqbar_boosted_1M_R${r}.root
mv output.root ${path2}/output_H2qqbar_boosted.root

#../bin/highpt_analysis ${path}/H2gg_ee_300k_R${r}/H2gg_ee_300k_R${r}.root
#mv output.root ${path2}/output_H2gg_ee.root

#../bin/highpt_analysis ${path}/H2qqbar_ee_300k_R${r}/H2qqbar_ee_300k_R${r}.root
#mv output.root ${path2}/output_H2qqbar_ee.root

../bin/highpt_analysis_rewt ${path2}/output_zplusjets.root ${path2}/output_zplusjets.root ${path}/Zplusjets_1M_R${r}/Zplusjets_1M_R${r}.root
mv output.root ${path2}/output_zplusjets_rewt.root

../bin/highpt_analysis_rewt ${path2}/output_dijets.root ${path2}/output_zplusjets.root ${path}/Dijets_1M_R${r}/Dijets_1M_R${r}.root
mv output.root ${path2}/output_dijets_rewt.root

../bin/highpt_analysis_rewt ${path2}/output_qqbar2Zg.root ${path2}/output_zplusjets.root ${path}/qqbar2Zg_1M_R${r}/qqbar2Zg_1M_R${r}.root
mv output.root ${path2}/output_qqbar2Zg_rewt.root

../bin/highpt_analysis_rewt ${path2}/output_gg2Hg.root ${path2}/output_zplusjets.root ${path}/gg2Hg_1M_R${r}/gg2Hg_1M_R${r}.root
mv output.root ${path2}/output_gg2Hg_rewt.root

../bin/highpt_analysis_rewt ${path2}/output_H2gg.root ${path2}/output_zplusjets.root ${path}/H2gg_1M_R${r}/H2gg_1M_R${r}.root
mv output.root ${path2}/output_H2gg_rewt.root

../bin/highpt_analysis_rewt ${path2}/output_H2qqbar.root ${path2}/output_zplusjets.root ${path}/H2qqbar_1M_R${r}/H2qqbar_1M_R${r}.root
mv output.root ${path2}/output_H2qqbar_rewt.root

../bin/highpt_analysis_rewt ${path2}/output_H2gg_boosted.root ${path2}/output_zplusjets.root ${path}/H2gg_boosted_1M_R${r}/H2gg_boosted_1M_R${r}.root
mv output.root ${path2}/output_H2gg_boosted_rewt.root

../bin/highpt_analysis_rewt ${path2}/output_H2qqbar_boosted.root ${path2}/output_zplusjets.root ${path}/H2qqbar_boosted_1M_R${r}/H2qqbar_boosted_1M_R${r}.root
mv output.root ${path2}/output_H2qqbar_boosted_rewt.root

#../bin/highpt_analysis_rewt ${path2}/output_H2gg_ee.root ${path2}/output_zplusjets.root ${path}/H2gg_ee_300k_R${r}/H2gg_ee_300k_R${r}.root
#mv output.root ${path2}/output_H2gg_ee_rewt.root

#../bin/highpt_analysis_rewt ${path2}/output_H2qqbar_ee.root ${path2}/output_zplusjets.root ${path}/H2qqbar_ee_300k_R${r}/H2qqbar_ee_300k_R${r}.root
#mv output.root ${path2}/output_H2qqbar_ee_rewt.root

counter=$((counter+1));
done

cd ..
rm -rf highpt_reg_analysis