
#include "graph.h"
#include "iostream"

graph::graph(std::map<int, std::vector< std::pair<int,int> >> in_graph) :
	mGraph(in_graph), mNum(0), mcc(0)
{
	std::map<int, std::vector< std::pair<int,int> >> mVisited;
}

graph::~graph()
{
}

const std::vector< std::pair<int,int> > graph::getCousins(int num) {
	return mGraph[num];
}

void graph::setStart(int num) {
	mNum = num;
}

void graph::explore(int num){
	if (mVisited.count(num) == 0){
		mVisited[num][0] = mNum;
		mVisited[num][2] = mcc;
		mNum++;

		for (size_t i = 0; i < mGraph[num].size(); i++) {

			if (mVisited.count(mGraph[num][i].first) == 0) {
				explore(mGraph[num][i].first);
			}
		}
		mVisited[num][1] = mNum;
		mNum++;
	}
}

void graph::print_my_graph() {
	for (std::map<int, int[3]>::iterator it = mVisited.begin(); it != mVisited.end(); it++) {
		std::cout << "vertice " << it->first << ": pre: " << mVisited[it->first][0] << " post: " << mVisited[it->first][1] << std::endl;
		for(int i = 0; i < mGraph[it->first].size(); i++) {
			std::cout << it->first << "'s weight to " << mGraph[it->first][i].first << ": " << mGraph[it->first][i].second << std::endl;
		}
	}
}

void graph::print_to_file(std::string out) {
	std::ofstream outfile;
	outfile.open(out);
	for (std::map<int, int[3]>::iterator it = mVisited.begin(); it != mVisited.end(); it++) {
		outfile << it->first << " " << mVisited[it->first][0] << " " << mVisited[it->first][1] << " " << mVisited[it->first][2] << std::endl;
	}
}

void graph::print_cousins(int num) {
    std::vector< std::pair<int,int> > g_1 = getCousins(num);
    std::cout << num << "'s cousins: " << std::endl;
    for ( int cuz = 0; cuz < g_1.size(); cuz++ ) {
        std::cout << g_1[cuz].first <<  ", ";
    }
    std::cout << std::endl;
}

void graph::dfs(){
	for (size_t i = 1; i < mGraph.size(); i++) {
		if (mVisited.count(i) == 0){
			explore(i);
			mcc++;
		}
	}
}

std::vector<std::pair<int,int>> graph::getEdges(int v) {
	return mGraph[v];
}

int graph::size(){
	return mGraph.size();
}


std::map<int, std::vector <std::pair <int, int> > >::iterator graph::start(){
	std::map<int, std::vector <std::pair <int, int> > >::iterator it = mGraph.begin();
	return it;
}
