CXX = gcc
CXXFLAGS = -ansi -Wall -pedantic -gstabs
CXXLDFLAGS =

OBJECTS = \
	utilities.o\
	

fdupe: fdupe.o deps
	$(CXX) fdupe.o $(OBJECTS)  -o fdupe

fdupe.o: main.c
	$(CXX) $(CXXFLAGS) -c main.c -o fdupe.o

deps: $(OBJECTS)

utilities.o: utilities.c
	$(CXX) $(CXXFLAGS) -c utilities.c


clean:
	rm *.o
