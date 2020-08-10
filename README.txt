# QG-Jet-Discrimination
Code used to generate/analyze events with Pythia for a quark/gluon jet study

Directory : EventGeneration

-FCNC.C contains the loop to generate events, FCNCAnalysis.cc contains event analysis (jet clustering, quark/gluon jet tagging, calculation of angularities, etc.)

-To generate events (if using code on pdsf; otherwise you will need to set up environment to use Pythia/FastJet): 
1) source paths.sh   
2) ./FCNC.exe --NEvents number_events_to_be_generated --OutFile out_file_name.root

-Events, along with relevant quantities such as number of jets, jet pT, angularities, etc.,  are saved in a TTree structure in the output .root file

Directory : analysis

-Contains code (inside the "src" subdirectory) to loop through Pythia output events and save histograms to an output .root file.

-Sub-directory "plots" will contain code to generate plots from the histograms output by the analysis code
