CXX = gcc
CXXFLAGS = -ansi -Wall -pedantic -gstabs
CXXLDFLAGS =

OBJECTS = \
	utilities.o\
	opencl.o\
	

fdupe_osx: fdupe.o deps
	$(CXX) fdupe.o $(OBJECTS) -framework OpenCL  -o fdupe

fdupe: fdupe.o deps
	$(CXX) fdupe.o $(OBJECTS) -o fdupe

fdupe.o: main.c
	$(CXX) $(CXXFLAGS) -c main.c -o fdupe.o

deps: $(OBJECTS)

utilities.o: utilities.c
	$(CXX) $(CXXFLAGS) -c utilities.c

opencl.o: opencl.c
	$(CXX) $(CXXFLAGS) -c opencl.c

clean:
	rm *.o rm fdupe
