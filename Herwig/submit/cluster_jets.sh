#!/bin/bash

dirname=$1
radius=$2
radstr=$3
i=$4

mkdir /project/projectdirs/atlas/sambt/Herwig_output/${dirname}_${radstr}

cd /project/projectdirs/atlas/sambt/Herwig_unclustered/${dirname}/
shopt -s expand_aliases
source /common/atlas/scripts/setupATLAS.sh
setupATLAS -q
localSetupROOT -q
mkdir ${radstr}_${i}
cd ${radstr}_${i}
cp /global/homes/s/sambt/Jets/qg_tagging_topology_project/Herwig/jet_cluster_FCNC/FCNC.exe .
source /global/homes/s/sambt/environment_scripts/hepmc.sh
source /global/homes/s/sambt/environment_scripts/jets_setup.sh
./FCNC.exe --infile ../${dirname}_${i}.root --OutFile ${dirname}_${radstr}_${i}.root --radius ${radius}
mv ${dirname}_${radstr}_${i}.root /project/projectdirs/atlas/sambt/Herwig_output/${dirname}_${radstr}/
cd ..
rm -rf ${radstr}_${i}/

cd ;
date
