#Makefile for various scripts I'm using here

CXXFLAGS = -O2 -Wall

hepmc_to_root : hepmc_to_root.cc
	$(CXX) $< -o $@  \
	$(CXXFLAGS) \
	`root-config --cflags --glibs` \
        -I${HEPMCLOCATION}/include \
        -L${HEPMCLIBLOCATION} -lHepMC -lHepMCrootIO