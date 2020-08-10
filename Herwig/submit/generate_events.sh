#!/bin/bash
jobname=$1
filename=$2
j=$3
process=$4

date
mkdir /project/projectdirs/atlas/sambt/analysis/Herwig_runs
rm -rf /project/projectdirs/atlas/sambt/analysis/Herwig_runs/${jobname}_${j}
mkdir /project/projectdirs/atlas/sambt/analysis/Herwig_runs/${jobname}_${j} 
mkdir /project/projectdirs/atlas/sambt/analysis/Herwig_runs/${jobname}_${j}/mg5_run
mkdir /project/projectdirs/atlas/sambt/Herwig_unclustered/${jobname}
cp /global/homes/s/sambt/Jets/qg_tagging_topology_project/Herwig/input_files/template_parton_shower_H7.in /project/projectdirs/atlas/sambt/analysis/Herwig_runs/${jobname}_${j}
cp /global/homes/s/sambt/Jets/qg_tagging_topology_project/Herwig/scripts/hepmc_to_root /project/projectdirs/atlas/sambt/analysis/Herwig_runs/${jobname}_${j}
cp -R /global/homes/s/sambt/Jets/qg_tagging_topology_project/Herwig/mg5_generation/${process}/* /project/projectdirs/atlas/sambt/analysis/Herwig_runs/${jobname}_${j}/mg5_run/

cd /project/projectdirs/atlas/sambt/analysis/Herwig_runs/${jobname}_${j}/mg5_run
./bin/generate_events ${jobname}_${j} -f --laststep=parton
cd Events/${jobname}_${j}/
gunzip unweighted_events.lhe.gz
mv unweighted_events.lhe /project/projectdirs/atlas/sambt/analysis/Herwig_runs/${jobname}_${j}/input.lhe
cd /project/projectdirs/atlas/sambt/analysis/Herwig_runs/${jobname}_${j}
rm -rf /project/projectdirs/atlas/sambt/analysis/Herwig_runs/${jobname}_${j}/mg5_run/

shopt -s expand_aliases
source /common/atlas/scripts/setupATLAS.sh
setupATLAS -q
localSetupROOT -q 

if [ $process = "H2qqbar" ]; then sed -i -e 's/5  1/1  1/' input.lhe; fi
source /projecta/projectdirs/atlas/sambt/code/Herwig7/bin/activate
Herwig read template_parton_shower_H7.in
deactivate

source /global/homes/s/sambt/environment_scripts/hepmc.sh
./hepmc_to_root output.hepmc ${filename}_${j}.root 
mv ${filename}_${j}.root /project/projectdirs/atlas/sambt/Herwig_unclustered/${jobname}/${filename}_${j}.root

cd ;
rm -rf /project/projectdirs/atlas/sambt/analysis/Herwig_runs/${jobname}_${j}
date