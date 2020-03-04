CXXFLAGS := -std=c++11 -Ofast

main: main.o binary_heap.o
	g++ $(CXXFLAGS) -o main main.o binary_heap.o

main.o: main.cpp binary_heap.h
	g++ $(CXXFLAGS) -c main.cpp

binary_heap.o: binary_heap.cpp binary_heap.h
	g++ $(CXXFLAGS) -c binary_heap.cpp

clean:
	-rm -f main
	-rm -f *.o
