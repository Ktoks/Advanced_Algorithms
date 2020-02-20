#include <iostream>
#include "graph.h"


int main() {
    std::ifstream fin;
    fin.open("graph-1000-4.txt");

    if (!fin.good()) {
        std::cout << "Unable to read file" << std::endl;
    }

    std::map<int, std::vector<pair>> the_map;
    
    int num_verts, g_u, g_v, g_w;

    fin >> num_verts;
    while (!fin.eof()) {
        fin >> g_u >> g_v >> g_w ;
        the_map[g_u].push_back( {g_v,g_w} );
        the_map[g_v].push_back( {g_u,g_w} );
    }

    graph mygraph(the_map);

    mygraph.setStart(1);

    mygraph.dfs();

    // mygraph.print_my_graph();
    mygraph.print_to_file("graph_out4.csv");

    return 0;
}