CXXFLAGS := -std=c++11

sequences: sequences.o
	g++ $(CXXFLAGS) -o sequences sequences.o

sequences.o: sequences.cpp
	g++ $(CXXFLAGS) -c sequences.cpp


clean:
	-rm -f main
	-rm -f *.o
