dirname=$1
k=`ls /project/projectdirs/atlas/sambt/Herwig_unclustered/${dirname} | wc -l`
echo k = $k
for i in `seq 1 $k`;
do
    sbatch --mem=10GB cluster_jets.sh ${dirname} 0.2 R0p2 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 0.3 R0p3 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 0.4 R0p4 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 0.5 R0p5 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 0.6 R0p6 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 0.7 R0p7 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 0.8 R0p8 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 0.9 R0p9 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 1.0 R1p0 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 1.1 R1p1 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 1.2 R1p2 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 1.3 R1p3 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 1.4 R1p4 ${i}
    sbatch --mem=10GB cluster_jets.sh ${dirname} 1.5 R1p5 ${i}
done