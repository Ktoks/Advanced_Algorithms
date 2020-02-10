#include <iostream>
#include "graph.h"


int main() {
    std::ifstream fin;
    fin.open("graph-10000-1.txt");

    if (!fin.good()) {
        std::cout << "Unable to read file" << std::endl;
    }

    std::map<int, std::vector<pair>> the_map;
    
    int num_verts, g_u, g_v, g_w, g_ws;

    fin >> num_verts;
    while (!fin.eof()) {
        fin >> g_u >> g_v >> g_w >> g_ws;
        // std::cout << "u: " << g_u << ". v: " << g_v << ". weight:" << g_w << std::endl;
        the_map[g_u].push_back({g_v,g_w});
        // u: {[v, w],[v,w]}


    }

    graph mygraph(the_map);

    mygraph.setStart(1);

    mygraph.dfs();

    // mygraph.print_my_graph();
    mygraph.print_to_file("graph_out.csv");

    return 0;
}
// the_map[1] = { {2,1},{3,1},{4,1},{5,2},{6,1},{7,1},{9,1},{10,1},{11,1},{12,1} };
// the_map[2] = { {1,1},{3,1} };
// the_map[3] = { {1,1},{2,1},{4,1} };
// the_map[4] = { {1,1},{3,1},{5,1} };
// the_map[5] = { {1,1},{4,1},{6,1} };
// the_map[6] = { {1,1},{5,1},{7,1},{8,1} };
// the_map[7] = { {1,1},{6,1},{8,1},{9,1},{13,1} };
// the_map[8] = { {6,1},{7,1} };
// the_map[9] = { {1,1},{7,1},{10,1},{11,1},{13,1} };
// the_map[10] = { {1,1},{9,1},{11,1} };
// the_map[11] = { {1,1},{9,1},{10,1},{12,1},{13,1} };
// the_map[12] = { {1,1},{11,1} };
// the_map[13] = { {7,1},{9,1},{11,1} };