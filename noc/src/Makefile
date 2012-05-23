CXX		= g++
OPT		= -g -std=c++0x
WARN	= -Wall
CXXFLAGS= $(OPT) $(WARN)
OBJECTS	= STprint.o STgen.o

all: STgen

STgen: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o STgen $(OBJECTS)
	
clean:
	@rm -f *.o core
	
realclean: clean
	@rm -f STgen

#File dependencies
STprint.o: STprint.cpp
STgen.o: STprint.cpp STgen.cpp

