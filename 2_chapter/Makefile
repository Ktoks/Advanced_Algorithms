CXXFLAGS := -std=c++11

all: alg_2.16

alg_2.16-graph.csv: collect_data.bash alg_2.16
	./collect_data.bash > alg_2.16-graph.csv

test-run: alg_2.16
	./alg_2.16 100 3

alg_2.16: alg_2.16.cpp
	g++ $(CXXFLAGS) -o $@ $^

clean:
	-rm -f alg_2.16
