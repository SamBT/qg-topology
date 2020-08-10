#!/bin/bash
jobname=$1
filename=$2
nevents=$3
process=$4
radius=$5
hmass=$6
ptmin=$7
ptmax=$8
minpt=$9

j=$(($nevents / 10000))

for i in `seq 1 $j`;
do
    #qsub -l cvmfs=1 -l h_vmem=8G run_job.sh ${jobname} ${filename} ${i}
    sbatch run_job.sh ${jobname} ${filename} ${i} ${process} ${radius} ${hmass} ${ptmin} ${ptmax} ${minpt}
done
