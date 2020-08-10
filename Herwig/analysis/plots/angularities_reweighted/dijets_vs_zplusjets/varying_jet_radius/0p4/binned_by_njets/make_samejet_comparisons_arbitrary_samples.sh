#!/bin/bash

for i in `seq 1 2`;
do
    for j in `seq $[$i+1] 3`
    do	
	root -b -q "samejet_two_samples.C(\"qjet\",\"LHA\",\"LHA\",\"zplusjets\",\"dijets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"qjet\",\"LHA\",\"LHA\",\"zplusjets\",\"zplusjets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"qjet\",\"ptD\",\"p_{T}^{D}\",\"zplusjets\",\"dijets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"qjet\",\"ptD\",\"p_{T}^{D}\",\"zplusjets\",\"zplusjets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"qjet\",\"mass\",\"Mass\",\"zplusjets\",\"dijets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"qjet\",\"mass\",\"Mass\",\"zplusjets\",\"zplusjets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"qjet\",\"multiplicity\",\"Multiplicity\",\"zplusjets\",\"dijets\",$i,$j,1,0)"
	root -b -q "samejet_two_samples.C(\"qjet\",\"multiplicity\",\"Multiplicity\",\"zplusjets\",\"zplusjets\",$i,$j,1,0)"
	root -b -q "samejet_two_samples.C(\"qjet\",\"width\",\"Width\",\"zplusjets\",\"dijets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"qjet\",\"width\",\"Width\",\"zplusjets\",\"zplusjets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"qjet\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",\"zplusjets\",\"dijets\",$i,$j,10,0)"
	root -b -q "samejet_two_samples.C(\"qjet\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",\"zplusjets\",\"zplusjets\",$i,$j,10,0)"
	mv compare_qjet_LHA* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_jet_comparisons/all_pairs_of_samples/LHA/
	mv compare_qjet_ptD* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_jet_comparisons/all_pairs_of_samples/ptD/
	mv compare_qjet_mass* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_jet_comparisons/all_pairs_of_samples/Mass/
	mv compare_qjet_multiplicity* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_jet_comparisons/all_pairs_of_samples/Multiplicity/
	mv compare_qjet_width* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_jet_comparisons/all_pairs_of_samples/Width/
	mv compare_qjet_nearestjetdR* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_jet_comparisons/all_pairs_of_samples/nearestjet_dR/
	chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/quark_jet_comparisons/all_pairs_of_samples/*/*
	
	root -b -q "samejet_two_samples.C(\"gjet\",\"LHA\",\"LHA\",\"zplusjets\",\"dijets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"gjet\",\"LHA\",\"LHA\",\"zplusjets\",\"zplusjets\",$i,$j,2,0)"
        root -b -q "samejet_two_samples.C(\"gjet\",\"ptD\",\"p_{T}^{D}\",\"zplusjets\",\"dijets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"gjet\",\"ptD\",\"p_{T}^{D}\",\"zplusjets\",\"zplusjets\",$i,$j,2,0)"
        root -b -q "samejet_two_samples.C(\"gjet\",\"mass\",\"Mass\",\"zplusjets\",\"dijets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"gjet\",\"mass\",\"Mass\",\"zplusjets\",\"zplusjets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"gjet\",\"multiplicity\",\"Multiplicity\",\"zplusjets\",\"dijets\",$i,$j,1,0)"
	root -b -q "samejet_two_samples.C(\"gjet\",\"multiplicity\",\"Multiplicity\",\"zplusjets\",\"zplusjets\",$i,$j,1,0)"
        root -b -q "samejet_two_samples.C(\"gjet\",\"width\",\"Width\",\"zplusjets\",\"dijets\",$i,$j,2,0)"
	root -b -q "samejet_two_samples.C(\"gjet\",\"width\",\"Width\",\"zplusjets\",\"zplusjets\",$i,$j,2,0)"
        root -b -q "samejet_two_samples.C(\"gjet\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",\"zplusjets\",\"dijets\",$i,$j,10,0)"
	root -b -q "samejet_two_samples.C(\"gjet\",\"nearestjetdR\",\"#DeltaR to Nearest Jet\",\"zplusjets\",\"zplusjets\",$i,$j,10,0)"
	mv compare_gjet_LHA* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/gluon_jet_comparisons/all_pairs_of_samples/LHA/
        mv compare_gjet_ptD* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/gluon_jet_comparisons/all_pairs_of_samples/ptD/
	mv compare_gjet_mass* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/gluon_jet_comparisons/all_pairs_of_samples/Mass/
	mv compare_gjet_multiplicity* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/gluon_jet_comparisons/all_pairs_of_samples/Multiplicity/
        mv compare_gjet_width* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/gluon_jet_comparisons/all_pairs_of_samples/Width/
	mv compare_gjet_nearestjetdR* /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/gluon_jet_comparisons/all_pairs_of_samples/nearestjet_dR/
        chmod 777 /project/projectdirs/atlas/www/sambt/QG_Jet_Discrimination_FinalState_Study/plots_by_njets/gluon_jet_comparisons/all_pairs_of_samples/*/*
    done
done
