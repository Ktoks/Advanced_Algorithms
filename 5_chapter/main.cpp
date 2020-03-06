#include "binary_heap.h"
#include "graph.h"

int INFIN = 2000000;

main()
{	
	// graph main
	std::ifstream fin;
    fin.open("graph-1000-4.txt");
	std::string out = "shortestPaths.txt";

    // if (!fin.good()) {
    //     std::cout << "Unable to read file" << std::endl;
	// 	exit(1);
    // }

    std::map<int, std::vector<std::pair<int, int>>> the_map;
    
    int num_verts, g_u, g_v, g_w, i;

    fin >> num_verts;
    while (!fin.eof()) {
        fin >> g_u >> g_v >> g_w ;
        the_map[g_u].push_back( {g_v,g_w} );
        the_map[g_v].push_back( {g_u,g_w} );
    }
    graph mygraph(the_map);
	// graph main end

	std::vector<int> cost;
	std::vector<int> prev;

	int size = std::pow(2, 20);

	prev.resize(size);
	cost.resize(size);

	for (int i = 0; i < size; i++)
	{
		prev[i] = 0;
		cost[i] = INFIN;
	}

	prev[0] = 0;
	cost[0] = 0;
	binaryHeap heap(prev, cost, size);

	while (!heap.empty()) {
		int u = heap.deletemin();
		for (int i = 0; i < mygraph.start()->second.size(); i++) {
			if(i < 20){
				std::cout << "I made it here, mygraph.start()->second[i].second is " << mygraph.start()->second[i].second << std::endl;
				std::cout << "heap.getWeight is " << heap.getWeight(i) << std::endl;
			}
			if (heap.getWeight(i) > mygraph.start()->second[i].second) {
				heap.decreasekey(i, mygraph.start()->second[i].second);
				prev[i] = u;
			}
		}
		mygraph.remove(u);	// maintaining the graph
	}
	std::ofstream outfile;
	outfile.open(out);

	for (int j = 0; j < prev.size(); j++) {
		outfile << prev[j] << std::endl;
	}
}