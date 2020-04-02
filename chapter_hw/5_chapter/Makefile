CXXFLAGS := -std=c++11

main: main.o binary_heap.o graph.o
	g++ $(CXXFLAGS) -o main main.o binary_heap.o graph.o

main.o: main.cpp binary_heap.h graph.h
	g++ $(CXXFLAGS) -c main.cpp

binary_heap.o: binary_heap.cpp binary_heap.h
	g++ $(CXXFLAGS) -c binary_heap.cpp

graph.o: graph.cpp graph.h
	g++ $(CXXFLAGS) -c graph.cpp

clean:
	-rm -f main
	-rm -f *.o
