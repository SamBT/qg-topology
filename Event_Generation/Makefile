# --------------------------------------------- #
# Makefile for FCNC code                        #
# Pascal Nef, March 6th 2014                    #
#                                               #
# Note: source setup.sh before make             #
# --------------------------------------------- #

CXXFLAGS =   -O2 -Wall 

.PHONY: clean debug all

all: FCNC

FCNC:  FCNC.so FCNCTools.so FCNCAnalysis.so 
	$(CXX) FCNC.so FCNCTools.so FCNCAnalysis.so -o $@.exe \
	$(CXXFLAGS) -Wno-shadow  \
	`root-config --glibs`  \
	-L$(FASTJETLOCATION)/lib `$(FASTJETLOCATION)/bin/fastjet-config --libs --plugins ` -lRecursiveTools -lQCDAwarePlugin \
	-L$(PYTHIA8LOCATION)/lib -lpythia8 -ldl \
	-L$(BOOSTLIBLOCATION) -lboost_program_options 

FCNC.so: FCNC.C    FCNCTools.so FCNCAnalysis.so   
	$(CXX) -o $@ -c $<  \
	$(CXXFLAGS) -Wno-shadow -fPIC -shared \
	`$(FASTJETLOCATION)/bin/fastjet-config --cxxflags --plugins` \
	-I$(PYTHIA8LOCATION)/include \
	-I $(BOOSTINCDIR) \
	`root-config --cflags` 

FCNCTools.so : FCNCTools.cc FCNCTools.h
	$(CXX) -o $@ -c $<  \
	$(CXXFLAGS) -Wno-shadow -fPIC -shared \
	`$(FASTJETLOCATION)/bin/fastjet-config --cxxflags --plugins` \
	-I$(PYTHIA8LOCATION)/include \
	`root-config --cflags`

FCNCAnalysis.so : FCNCAnalysis.cc FCNCAnalysis.h
	$(CXX) -o $@ -c $<  \
	$(CXXFLAGS) -Wno-shadow -fPIC -shared \
	`$(FASTJETLOCATION)/bin/fastjet-config --cxxflags --plugins`  \
	-I$(PYTHIA8LOCATION)/include \
	`root-config --cflags`   

clean:
	rm -rf *.exe
	rm -rf *.o
	rm -rf *.so
	rm -f *~
