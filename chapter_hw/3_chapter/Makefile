CXXFLAGS := -std=c++11

main: main.o graph.o
	g++ $(CXXFLAGS) -o main main.o graph.o

main.o: main.cpp graph.h
	g++ $(CXXFLAGS) -c main.cpp

graph.o: graph.cpp graph.h
	g++ $(CXXFLAGS) -c graph.cpp

clean:
	-rm -f main
	-rm -f *.o
