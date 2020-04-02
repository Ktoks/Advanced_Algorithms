#include "binary_heap.h"
#include "graph.h"

int INFIN = 2000000;

main()
{	
	// graph main
	std::ifstream fin;
    fin.open("graphs-4.txt");
	std::string out = "shortestPaths.txt";

    // if (!fin.good()) {
    //     std::cout << "Unable to read file" << std::endl;
	// 	exit(1);
    // }
	int num_verts;
	int numarray[3];
	std::vector<int> vertname;
	std::vector<int> previous;
	std::vector<int> weights;
	// name, previous, weight
	// testing!!!!!!!!!!!!!!!!!!!!!!!

	vertname.push_back(1);
	vertname.push_back(2);
	vertname.push_back(3);
	vertname.push_back(4);
	previous.push_back(2);
	previous.push_back(3);
	previous.push_back(4);
	previous.push_back(1);
	weights.push_back(4);
	weights.push_back(2);
	weights.push_back(1);
	weights.push_back(3);

	// testing!!!!!!!!!!!!!!!!!!!!!!!

    // fin >> num_verts;
    // while (!fin.eof()) {
    //     fin >> numarray[0] >> numarray[1] >> numarray[2];

	// 	for (int j = 0; j < vertname.size(); j++) {
	// 		if(vertname[j] == numarray[0] and previous[j] == numarray[1]) {
	// 			continue;
	// 		}
	// 	}
	// 	vertname.push_back(numarray[0]);
	// 	previous.push_back(numarray[1]);
	// 	weights.push_back(numarray[2]);
    // }
	// graph is set up

	// start prim's algorithm
	std::vector<int> cost;
	std::vector<int> prev;
	int size = vertname.size();
	prev.resize(size);
	cost.resize(size);

	for (int i = 0; i < size; i++)
	{
		prev[i] = 0;
		cost[i] = INFIN;
	}

	weights[0] = 0;
	binaryHeap heap(vertname, weights, size);
	heap.printHeap();
	while (!heap.empty()) {
		std::pair<int, int> you = heap.deletemin();
		for (int i = 0; i < vertname.size(); i++) {
			// std::cout << you.first << ": " << you.second << std::endl;
			if (you.first == i) {
				if (cost[i] > you.second) {
					cost[i] = you.second;
					heap.decreasekey(i, you.second);
					prev[i] = you.first;
				}
			}
		}
	}
	std::ofstream outfile;
	outfile.open(out);

	for (int j = 0; j < prev.size(); j++) {
		outfile << cost[j] << std::endl;
	}
}