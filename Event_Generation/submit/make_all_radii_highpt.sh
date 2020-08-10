jobname=$1
process=$2
nevents=$3
hmass=${4:-1000}
ptmin=${5:-160}
ptmax=${6:-400}
minpt=${7:-200}

echo higgs mass is ${hmass}
echo ptmin = $ptmin
echo ptmax = $ptmax
echo min jet pt = $minpt

./submit_jobs_highpt.sh ${jobname}_R0p4 ${jobname}_R0p4 ${nevents} ${process} 0.4 ${hmass} ${ptmin} ${ptmax} ${minpt}
./submit_jobs_highpt.sh ${jobname}_R0p5 ${jobname}_R0p5 ${nevents} ${process} 0.5 ${hmass} ${ptmin} ${ptmax} ${minpt}
./submit_jobs_highpt.sh ${jobname}_R0p6 ${jobname}_R0p6 ${nevents} ${process} 0.6 ${hmass} ${ptmin} ${ptmax} ${minpt}
./submit_jobs_highpt.sh ${jobname}_R0p7 ${jobname}_R0p7 ${nevents} ${process} 0.7 ${hmass} ${ptmin} ${ptmax} ${minpt}
./submit_jobs_highpt.sh ${jobname}_R0p8 ${jobname}_R0p8 ${nevents} ${process} 0.8 ${hmass} ${ptmin} ${ptmax} ${minpt}
./submit_jobs_highpt.sh ${jobname}_R0p9 ${jobname}_R0p9 ${nevents} ${process} 0.9 ${hmass} ${ptmin} ${ptmax} ${minpt}
./submit_jobs_highpt.sh ${jobname}_R1p0 ${jobname}_R1p0 ${nevents} ${process} 1.0 ${hmass} ${ptmin} ${ptmax} ${minpt}
./submit_jobs_highpt.sh ${jobname}_R1p1 ${jobname}_R1p1 ${nevents} ${process} 1.1 ${hmass} ${ptmin} ${ptmax} ${minpt}
./submit_jobs_highpt.sh ${jobname}_R1p2 ${jobname}_R1p2 ${nevents} ${process} 1.2 ${hmass} ${ptmin} ${ptmax} ${minpt}
./submit_jobs_highpt.sh ${jobname}_R1p3 ${jobname}_R1p3 ${nevents} ${process} 1.3 ${hmass} ${ptmin} ${ptmax} ${minpt}
./submit_jobs_highpt.sh ${jobname}_R1p4 ${jobname}_R1p4 ${nevents} ${process} 1.4 ${hmass} ${ptmin} ${ptmax} ${minpt}
./submit_jobs_highpt.sh ${jobname}_R1p5 ${jobname}_R1p5 ${nevents} ${process} 1.5 ${hmass} ${ptmin} ${ptmax} ${minpt}
