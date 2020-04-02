CXXFLAGS := -std=c++11

all: sample

sample-graph.csv: collect_data.bash sample
	./collect_data.bash > sample-graph.csv

test-run: sample
	./sample 100 3

sample: sample.cpp
	g++ $(CXXFLAGS) -o $@ $^

clean:
	-rm -f sample
