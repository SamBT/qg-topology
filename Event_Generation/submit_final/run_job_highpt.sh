#!/bin/bash
jobname=$1
filename=$2
j=$3
process=$4
radius=$5
hmass=$6
ptmin=$7
ptmax=$8
minpt=$9

date
mkdir /project/projectdirs/atlas/sambt/analysis/Pythia_runs_pthat_nomax
rm -rf /project/projectdirs/atlas/sambt/analysis/Pythia_runs_pthat_nomax/${jobname}_${j}
mkdir /project/projectdirs/atlas/sambt/analysis/Pythia_runs_pthat_nomax/${jobname}_${j} 
cd /project/projectdirs/atlas/sambt/analysis/Pythia_runs_pthat_nomax/${jobname}_${j}

shopt -s expand_aliases
source /common/atlas/scripts/setupATLAS.sh
setupATLAS -q
localSetupROOT -q 
source /global/homes/s/sambt/environment_scripts/jets_setup.sh

cp /global/homes/s/sambt/Jets/qg_tagging_topology_project/Event_Generation/FCNC.exe .

./FCNC.exe --NEvents 10000 --OutFile ${filename}.root --process ${process} --radius ${radius} --Hmass ${hmass} --ptmin ${ptmin} --ptmax ${ptmax} --minjet ${minpt}

mkdir /project/projectdirs/atlas/sambt/Pythia_output_final/highpT/${jobname}

mv ${filename}.root /project/projectdirs/atlas/sambt/Pythia_output_final/highpT/${jobname}/${filename}_${j}.root

cd ;
rm -rf /project/projectdirs/atlas/sambt/analysis/Pythia_runs_pthat_nomax/${jobname}_${j}
date