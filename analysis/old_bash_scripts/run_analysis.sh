#!/bin/bash

path=/project/projectdirs/atlas/sambt/Pythia_output

make analysis
make analysis_rewt

./bin/analysis ${path}/Zplusjets_100k_R0p4/Zplusjets_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_zplusjets.root
./bin/analysis ${path}/Zplusjets_100k_R0p5/Zplusjets_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_zplusjets.root
./bin/analysis ${path}/Zplusjets_100k_R0p6/Zplusjets_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_zplusjets.root
./bin/analysis ${path}/Zplusjets_100k_R0p7/Zplusjets_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_zplusjets.root
./bin/analysis ${path}/Zplusjets_100k_R0p8/Zplusjets_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_zplusjets.root
./bin/analysis ${path}/Zplusjets_100k_R0p9/Zplusjets_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_zplusjets.root
./bin/analysis ${path}/Zplusjets_100k_R1p0/Zplusjets_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_zplusjets.root

./bin/analysis ${path}/Dijets_100k_R0p4/Dijets_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_dijets.root
./bin/analysis ${path}/Dijets_100k_R0p5/Dijets_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_dijets.root
./bin/analysis ${path}/Dijets_100k_R0p6/Dijets_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_dijets.root
./bin/analysis ${path}/Dijets_100k_R0p7/Dijets_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_dijets.root
./bin/analysis ${path}/Dijets_100k_R0p8/Dijets_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_dijets.root
./bin/analysis ${path}/Dijets_100k_R0p9/Dijets_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_dijets.root
./bin/analysis ${path}/Dijets_100k_R1p0/Dijets_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_dijets.root

./bin/analysis ${path}/qqbar2Zg_100k_R0p4/qqbar2Zg_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_qqbar2Zg.root
./bin/analysis ${path}/qqbar2Zg_100k_R0p5/qqbar2Zg_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_qqbar2Zg.root
./bin/analysis ${path}/qqbar2Zg_100k_R0p6/qqbar2Zg_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_qqbar2Zg.root
./bin/analysis ${path}/qqbar2Zg_100k_R0p7/qqbar2Zg_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_qqbar2Zg.root
./bin/analysis ${path}/qqbar2Zg_100k_R0p8/qqbar2Zg_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_qqbar2Zg.root
./bin/analysis ${path}/qqbar2Zg_100k_R0p9/qqbar2Zg_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_qqbar2Zg.root
./bin/analysis ${path}/qqbar2Zg_100k_R1p0/qqbar2Zg_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_qqbar2Zg.root

./bin/analysis ${path}/gg2Hg_100k_R0p4/gg2Hg_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_gg2Hg.root
./bin/analysis ${path}/gg2Hg_100k_R0p5/gg2Hg_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_gg2Hg.root
./bin/analysis ${path}/gg2Hg_100k_R0p6/gg2Hg_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_gg2Hg.root
./bin/analysis ${path}/gg2Hg_100k_R0p7/gg2Hg_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_gg2Hg.root
./bin/analysis ${path}/gg2Hg_100k_R0p8/gg2Hg_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_gg2Hg.root
./bin/analysis ${path}/gg2Hg_100k_R0p9/gg2Hg_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_gg2Hg.root
./bin/analysis ${path}/gg2Hg_100k_R1p0/gg2Hg_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_gg2Hg.root

./bin/analysis ${path}/H2gg_100k_R0p4/H2gg_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_H2gg.root
./bin/analysis ${path}/H2gg_100k_R0p5/H2gg_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_H2gg.root
./bin/analysis ${path}/H2gg_100k_R0p6/H2gg_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_H2gg.root
./bin/analysis ${path}/H2gg_100k_R0p7/H2gg_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_H2gg.root
./bin/analysis ${path}/H2gg_100k_R0p8/H2gg_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_H2gg.root
./bin/analysis ${path}/H2gg_100k_R0p9/H2gg_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_H2gg.root
./bin/analysis ${path}/H2gg_100k_R1p0/H2gg_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_H2gg.root

./bin/analysis ${path}/H2qqbar_100k_R0p4/H2qqbar_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_H2qqbar.root
./bin/analysis ${path}/H2qqbar_100k_R0p5/H2qqbar_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_H2qqbar.root
./bin/analysis ${path}/H2qqbar_100k_R0p6/H2qqbar_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_H2qqbar.root
./bin/analysis ${path}/H2qqbar_100k_R0p7/H2qqbar_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_H2qqbar.root
./bin/analysis ${path}/H2qqbar_100k_R0p8/H2qqbar_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_H2qqbar.root
./bin/analysis ${path}/H2qqbar_100k_R0p9/H2qqbar_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_H2qqbar.root
./bin/analysis ${path}/H2qqbar_100k_R1p0/H2qqbar_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_H2qqbar.root

./bin/analysis ${path}/H2gg_ee_R0p4/H2gg_ee_R0p4.root
mv output.root analysis_output/Radius_04/output_H2gg_ee.root
./bin/analysis ${path}/H2gg_ee_R0p5/H2gg_ee_R0p5.root
mv output.root analysis_output/Radius_05/output_H2gg_ee.root
./bin/analysis ${path}/H2gg_ee_R0p6/H2gg_ee_R0p6.root
mv output.root analysis_output/Radius_06/output_H2gg_ee.root
./bin/analysis ${path}/H2gg_ee_R0p7/H2gg_ee_R0p7.root
mv output.root analysis_output/Radius_07/output_H2gg_ee.root
./bin/analysis ${path}/H2gg_ee_R0p8/H2gg_ee_R0p8.root
mv output.root analysis_output/Radius_08/output_H2gg_ee.root
./bin/analysis ${path}/H2gg_ee_R0p9/H2gg_ee_R0p9.root
mv output.root analysis_output/Radius_09/output_H2gg_ee.root
./bin/analysis ${path}/H2gg_ee_R1p0/H2gg_ee_R1p0.root
mv output.root analysis_output/Radius_1/output_H2gg_ee.root

./bin/analysis ${path}/H2qqbar_ee_R0p4/H2qqbar_ee_R0p4.root
mv output.root analysis_output/Radius_04/output_H2qqbar_ee.root
./bin/analysis ${path}/H2qqbar_ee_R0p5/H2qqbar_ee_R0p5.root
mv output.root analysis_output/Radius_05/output_H2qqbar_ee.root
./bin/analysis ${path}/H2qqbar_ee_R0p6/H2qqbar_ee_R0p6.root
mv output.root analysis_output/Radius_06/output_H2qqbar_ee.root
./bin/analysis ${path}/H2qqbar_ee_R0p7/H2qqbar_ee_R0p7.root
mv output.root analysis_output/Radius_07/output_H2qqbar_ee.root
./bin/analysis ${path}/H2qqbar_ee_R0p8/H2qqbar_ee_R0p8.root
mv output.root analysis_output/Radius_08/output_H2qqbar_ee.root
./bin/analysis ${path}/H2qqbar_ee_R0p9/H2qqbar_ee_R0p9.root
mv output.root analysis_output/Radius_09/output_H2qqbar_ee.root
./bin/analysis ${path}/H2qqbar_ee_R1p0/H2qqbar_ee_R1p0.root
mv output.root analysis_output/Radius_1/output_H2qqbar_ee.root

./bin/analysis_rewt analysis_output/Radius_04/output_zplusjets.root analysis_output/Radius_04/output_zplusjets.root ${path}/Zplusjets_100k_R0p4/Zplusjets_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_zplusjets_rewt.root
./bin/analysis_rewt analysis_output/Radius_05/output_zplusjets.root analysis_output/Radius_05/output_zplusjets.root ${path}/Zplusjets_100k_R0p5/Zplusjets_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_zplusjets_rewt.root
./bin/analysis_rewt analysis_output/Radius_06/output_zplusjets.root analysis_output/Radius_06/output_zplusjets.root ${path}/Zplusjets_100k_R0p6/Zplusjets_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_zplusjets_rewt.root
./bin/analysis_rewt analysis_output/Radius_07/output_zplusjets.root analysis_output/Radius_07/output_zplusjets.root ${path}/Zplusjets_100k_R0p7/Zplusjets_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_zplusjets_rewt.root
./bin/analysis_rewt analysis_output/Radius_08/output_zplusjets.root analysis_output/Radius_08/output_zplusjets.root ${path}/Zplusjets_100k_R0p8/Zplusjets_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_zplusjets_rewt.root
./bin/analysis_rewt analysis_output/Radius_09/output_zplusjets.root analysis_output/Radius_09/output_zplusjets.root ${path}/Zplusjets_100k_R0p9/Zplusjets_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_zplusjets_rewt.root
./bin/analysis_rewt analysis_output/Radius_1/output_zplusjets.root analysis_output/Radius_1/output_zplusjets.root ${path}/Zplusjets_100k_R1p0/Zplusjets_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_zplusjets_rewt.root

./bin/analysis_rewt analysis_output/Radius_04/output_dijets.root analysis_output/Radius_04/output_zplusjets.root ${path}/Dijets_100k_R0p4/Dijets_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_dijets_rewt.root
./bin/analysis_rewt analysis_output/Radius_05/output_dijets.root analysis_output/Radius_05/output_zplusjets.root ${path}/Dijets_100k_R0p5/Dijets_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_dijets_rewt.root
./bin/analysis_rewt analysis_output/Radius_06/output_dijets.root analysis_output/Radius_06/output_zplusjets.root ${path}/Dijets_100k_R0p6/Dijets_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_dijets_rewt.root
./bin/analysis_rewt analysis_output/Radius_07/output_dijets.root analysis_output/Radius_07/output_zplusjets.root ${path}/Dijets_100k_R0p7/Dijets_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_dijets_rewt.root
./bin/analysis_rewt analysis_output/Radius_08/output_dijets.root analysis_output/Radius_08/output_zplusjets.root ${path}/Dijets_100k_R0p8/Dijets_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_dijets_rewt.root
./bin/analysis_rewt analysis_output/Radius_09/output_dijets.root analysis_output/Radius_09/output_zplusjets.root ${path}/Dijets_100k_R0p9/Dijets_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_dijets_rewt.root
./bin/analysis_rewt analysis_output/Radius_1/output_dijets.root analysis_output/Radius_1/output_zplusjets.root ${path}/Dijets_100k_R1p0/Dijets_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_dijets_rewt.root

./bin/analysis_rewt analysis_output/Radius_04/output_qqbar2Zg.root analysis_output/Radius_04/output_zplusjets.root ${path}/qqbar2Zg_100k_R0p4/qqbar2Zg_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_qqbar2Zg_rewt.root
./bin/analysis_rewt analysis_output/Radius_05/output_qqbar2Zg.root analysis_output/Radius_05/output_zplusjets.root ${path}/qqbar2Zg_100k_R0p5/qqbar2Zg_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_qqbar2Zg_rewt.root
./bin/analysis_rewt analysis_output/Radius_06/output_qqbar2Zg.root analysis_output/Radius_06/output_zplusjets.root ${path}/qqbar2Zg_100k_R0p6/qqbar2Zg_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_qqbar2Zg_rewt.root
./bin/analysis_rewt analysis_output/Radius_07/output_qqbar2Zg.root analysis_output/Radius_07/output_zplusjets.root ${path}/qqbar2Zg_100k_R0p7/qqbar2Zg_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_qqbar2Zg_rewt.root
./bin/analysis_rewt analysis_output/Radius_08/output_qqbar2Zg.root analysis_output/Radius_08/output_zplusjets.root ${path}/qqbar2Zg_100k_R0p8/qqbar2Zg_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_qqbar2Zg_rewt.root
./bin/analysis_rewt analysis_output/Radius_09/output_qqbar2Zg.root analysis_output/Radius_09/output_zplusjets.root ${path}/qqbar2Zg_100k_R0p9/qqbar2Zg_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_qqbar2Zg_rewt.root
./bin/analysis_rewt analysis_output/Radius_1/output_qqbar2Zg.root analysis_output/Radius_1/output_zplusjets.root ${path}/qqbar2Zg_100k_R1p0/qqbar2Zg_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_qqbar2Zg_rewt.root

./bin/analysis_rewt analysis_output/Radius_04/output_gg2Hg.root analysis_output/Radius_04/output_zplusjets.root ${path}/gg2Hg_100k_R0p4/gg2Hg_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_gg2Hg_rewt.root
./bin/analysis_rewt analysis_output/Radius_05/output_gg2Hg.root analysis_output/Radius_05/output_zplusjets.root ${path}/gg2Hg_100k_R0p5/gg2Hg_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_gg2Hg_rewt.root
./bin/analysis_rewt analysis_output/Radius_06/output_gg2Hg.root analysis_output/Radius_06/output_zplusjets.root ${path}/gg2Hg_100k_R0p6/gg2Hg_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_gg2Hg_rewt.root
./bin/analysis_rewt analysis_output/Radius_07/output_gg2Hg.root analysis_output/Radius_07/output_zplusjets.root ${path}/gg2Hg_100k_R0p7/gg2Hg_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_gg2Hg_rewt.root
./bin/analysis_rewt analysis_output/Radius_08/output_gg2Hg.root analysis_output/Radius_08/output_zplusjets.root ${path}/gg2Hg_100k_R0p8/gg2Hg_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_gg2Hg_rewt.root
./bin/analysis_rewt analysis_output/Radius_09/output_gg2Hg.root analysis_output/Radius_09/output_zplusjets.root ${path}/gg2Hg_100k_R0p9/gg2Hg_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_gg2Hg_rewt.root
./bin/analysis_rewt analysis_output/Radius_1/output_gg2Hg.root analysis_output/Radius_1/output_zplusjets.root ${path}/gg2Hg_100k_R1p0/gg2Hg_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_gg2Hg_rewt.root

./bin/analysis_rewt analysis_output/Radius_04/output_H2gg.root analysis_output/Radius_04/output_zplusjets.root ${path}/H2gg_100k_R0p4/H2gg_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_H2gg_rewt.root
./bin/analysis_rewt analysis_output/Radius_05/output_H2gg.root analysis_output/Radius_05/output_zplusjets.root ${path}/H2gg_100k_R0p5/H2gg_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_H2gg_rewt.root
./bin/analysis_rewt analysis_output/Radius_06/output_H2gg.root analysis_output/Radius_06/output_zplusjets.root ${path}/H2gg_100k_R0p6/H2gg_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_H2gg_rewt.root
./bin/analysis_rewt analysis_output/Radius_07/output_H2gg.root analysis_output/Radius_07/output_zplusjets.root ${path}/H2gg_100k_R0p7/H2gg_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_H2gg_rewt.root
./bin/analysis_rewt analysis_output/Radius_08/output_H2gg.root analysis_output/Radius_08/output_zplusjets.root ${path}/H2gg_100k_R0p8/H2gg_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_H2gg_rewt.root
./bin/analysis_rewt analysis_output/Radius_09/output_H2gg.root analysis_output/Radius_09/output_zplusjets.root ${path}/H2gg_100k_R0p9/H2gg_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_H2gg_rewt.root
./bin/analysis_rewt analysis_output/Radius_1/output_H2gg.root analysis_output/Radius_1/output_zplusjets.root ${path}/H2gg_100k_R1p0/H2gg_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_H2gg_rewt.root

./bin/analysis_rewt analysis_output/Radius_04/output_H2qqbar.root analysis_output/Radius_04/output_zplusjets.root ${path}/H2qqbar_100k_R0p4/H2qqbar_100k_R0p4.root
mv output.root analysis_output/Radius_04/output_H2qqbar_rewt.root
./bin/analysis_rewt analysis_output/Radius_05/output_H2qqbar.root analysis_output/Radius_05/output_zplusjets.root ${path}/H2qqbar_100k_R0p5/H2qqbar_100k_R0p5.root
mv output.root analysis_output/Radius_05/output_H2qqbar_rewt.root
./bin/analysis_rewt analysis_output/Radius_06/output_H2qqbar.root analysis_output/Radius_06/output_zplusjets.root ${path}/H2qqbar_100k_R0p6/H2qqbar_100k_R0p6.root
mv output.root analysis_output/Radius_06/output_H2qqbar_rewt.root
./bin/analysis_rewt analysis_output/Radius_07/output_H2qqbar.root analysis_output/Radius_07/output_zplusjets.root ${path}/H2qqbar_100k_R0p7/H2qqbar_100k_R0p7.root
mv output.root analysis_output/Radius_07/output_H2qqbar_rewt.root
./bin/analysis_rewt analysis_output/Radius_08/output_H2qqbar.root analysis_output/Radius_08/output_zplusjets.root ${path}/H2qqbar_100k_R0p8/H2qqbar_100k_R0p8.root
mv output.root analysis_output/Radius_08/output_H2qqbar_rewt.root
./bin/analysis_rewt analysis_output/Radius_09/output_H2qqbar.root analysis_output/Radius_09/output_zplusjets.root ${path}/H2qqbar_100k_R0p9/H2qqbar_100k_R0p9.root
mv output.root analysis_output/Radius_09/output_H2qqbar_rewt.root
./bin/analysis_rewt analysis_output/Radius_1/output_H2qqbar.root analysis_output/Radius_1/output_zplusjets.root ${path}/H2qqbar_100k_R1p0/H2qqbar_100k_R1p0.root
mv output.root analysis_output/Radius_1/output_H2qqbar_rewt.root

####
./bin/analysis_rewt analysis_output/Radius_04/output_H2gg_ee.root analysis_output/Radius_04/output_zplusjets.root ${path}/H2gg_ee_R0p4/H2gg_ee_R0p4.root
mv output.root analysis_output/Radius_04/output_H2gg_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_05/output_H2gg_ee.root analysis_output/Radius_05/output_zplusjets.root ${path}/H2gg_ee_R0p5/H2gg_ee_R0p5.root
mv output.root analysis_output/Radius_05/output_H2gg_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_06/output_H2gg_ee.root analysis_output/Radius_06/output_zplusjets.root ${path}/H2gg_ee_R0p6/H2gg_ee_R0p6.root
mv output.root analysis_output/Radius_06/output_H2gg_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_07/output_H2gg_ee.root analysis_output/Radius_07/output_zplusjets.root ${path}/H2gg_ee_R0p7/H2gg_ee_R0p7.root
mv output.root analysis_output/Radius_07/output_H2gg_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_08/output_H2gg_ee.root analysis_output/Radius_08/output_zplusjets.root ${path}/H2gg_ee_R0p8/H2gg_ee_R0p8.root
mv output.root analysis_output/Radius_08/output_H2gg_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_09/output_H2gg_ee.root analysis_output/Radius_09/output_zplusjets.root ${path}/H2gg_ee_R0p9/H2gg_ee_R0p9.root
mv output.root analysis_output/Radius_09/output_H2gg_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_1/output_H2gg_ee.root analysis_output/Radius_1/output_zplusjets.root ${path}/H2gg_ee_R1p0/H2gg_ee_R1p0.root
mv output.root analysis_output/Radius_1/output_H2gg_ee_rewt.root

./bin/analysis_rewt analysis_output/Radius_04/output_H2qqbar_ee.root analysis_output/Radius_04/output_zplusjets.root ${path}/H2qqbar_ee_R0p4/H2qqbar_ee_R0p4.root
mv output.root analysis_output/Radius_04/output_H2qqbar_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_05/output_H2qqbar_ee.root analysis_output/Radius_05/output_zplusjets.root ${path}/H2qqbar_ee_R0p5/H2qqbar_ee_R0p5.root
mv output.root analysis_output/Radius_05/output_H2qqbar_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_06/output_H2qqbar_ee.root analysis_output/Radius_06/output_zplusjets.root ${path}/H2qqbar_ee_R0p6/H2qqbar_ee_R0p6.root
mv output.root analysis_output/Radius_06/output_H2qqbar_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_07/output_H2qqbar_ee.root analysis_output/Radius_07/output_zplusjets.root ${path}/H2qqbar_ee_R0p7/H2qqbar_ee_R0p7.root
mv output.root analysis_output/Radius_07/output_H2qqbar_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_08/output_H2qqbar_ee.root analysis_output/Radius_08/output_zplusjets.root ${path}/H2qqbar_ee_R0p8/H2qqbar_ee_R0p8.root
mv output.root analysis_output/Radius_08/output_H2qqbar_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_09/output_H2qqbar_ee.root analysis_output/Radius_09/output_zplusjets.root ${path}/H2qqbar_ee_R0p9/H2qqbar_ee_R0p9.root
mv output.root analysis_output/Radius_09/output_H2qqbar_ee_rewt.root
./bin/analysis_rewt analysis_output/Radius_1/output_H2qqbar_ee.root analysis_output/Radius_1/output_zplusjets.root ${path}/H2qqbar_ee_R1p0/H2qqbar_ee_R1p0.root
mv output.root analysis_output/Radius_1/output_H2qqbar_ee_rewt.root