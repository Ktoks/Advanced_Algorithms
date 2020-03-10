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
	mygraph.dfs();
	// graph main end
	std::vector<int> weights;
	std::vector<int> previous;
	int size = mygraph.mVisitedSize();
	weights.resize(size);
	previous.resize(size);


	for(int i = 0; i < mygraph.mVisitedSize(); i++) {
		weights[i] = mygraph.getWeightFromVert(i);
		previous[i] = mygraph.getPrevFromVert(i);
	}


	std::vector<int> cost;
	std::vector<int> prev;


	prev.resize(size);
	cost.resize(size);

	for (int i = 0; i < size; i++)
	{
		prev[i] = 0;
		cost[i] = INFIN;
	}

	// prev[0] = 0;
	cost[0] = 0;
	binaryHeap heap(previous, weights, size);
	std::cout << "1: vector size is " << size << "\nheap size is " << heap.getSize() << std::endl;

	while (!heap.empty()) {
		std::pair<int, int> you = heap.deletemin();
		std::cout << "u's weight is " << you.second << std::endl;
		// std::cout << "mygraph[you].size() is " << mygraph.pairsize(you.first) << std::endl;
		for (int i = 0; i < mygraph.start()->second.size(); i++) {
			// if(i < 20){
				std::cout << "3: mygraph.start()->second[i].second is " << mygraph.start()->second[i].second << std::endl;
				std::cout << "4: heap.getWeight is " << heap.getWeight(i) << std::endl;
			// }
			if (heap.getWeight(i) > mygraph.start()->second[i].second) {
				heap.decreasekey(i, mygraph.start()->second[i].second);
				cost[i] = you.second;
				// prev[i] = you.first;
			}
		}
		// mygraph.remove(u);	// maintaining the graph
	}
	std::ofstream outfile;
	outfile.open(out);

	for (int j = 0; j < prev.size(); j++) {
		outfile << cost[j] << std::endl;
	}
}