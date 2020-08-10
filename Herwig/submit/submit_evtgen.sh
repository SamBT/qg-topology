#!/bin/bash
jobname=$1
filename=$2
process=$3
nevents=$4

j=$(($nevents / 10000))

for i in `seq 1 $j`;
do
    #qsub -l cvmfs=1 -l h_vmem=8G run_job.sh ${jobname} ${filename} ${i}
    sbatch generate_events.sh ${jobname} ${filename} ${i} ${process}
done
