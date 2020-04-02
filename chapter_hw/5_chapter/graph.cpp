
#include "graph.h"
#include "iostream"

graph::graph(std::map<int, std::vector< std::pair<int, int> >> in_graph) :
	mGraph(in_graph), mNum(0), mcc(0)
{
	std::map<int, std::vector< std::pair<int, int> >> mVisited;
}

graph::~graph()
{
}

const std::vector< std::pair<int, int> > graph::getCousins(int num) {
	return mGraph[num];
}

void graph::setStart(int num) {
	mNum = num;
	current_weight = 0;
}

void graph::explore(int num){
	// if not visited at all or if mVisited[num][3] > current_weight:
	if (mVisited.count(num) == 0){
		mVisited[num][0] = mNum;
		mVisited[num][2] = mcc;
		mVisited[num][3] = current_weight;
		mNum++;

		for (size_t i = 0; i < mGraph[num].size(); i++) {

			if (mVisited.count(mGraph[num][i].first) == 0 || mVisited[i][3] > (current_weight + mGraph[num][i].second) ) {
				current_weight += mGraph[num][i].second;		// add new edgeweight as we go down tree
				mVisited[i][4] = num;							// set i's new prev
				explore(mGraph[num][i].first);					// re-explore to update mst
				current_weight -= mGraph[num][i].second;		// recalculate as we go back up the tree
			}
		}
		mVisited[num][1] = mNum;
		mNum++;
	}
}

void graph::dfs(){
	// for (size_t i = 1; i < mGraph.size(); i++) {
	for (size_t i = 0; i < mGraph.size(); i++) {
		if (mVisited.count(i) == 0){
			explore(i);
			mcc++;
		}
	}
}

void graph::print_my_graph() {
	for (std::map<int, int[5]>::iterator it = mVisited.begin(); it != mVisited.end(); it++) {
		// std::cout << "vertice " << it->first << ": pre: " << mVisited[it->first][0] << " post: " << mVisited[it->first][1] << std::endl;
		for(int i = 0; i < mGraph[it->first].size(); i++) {
			std::cout << it->first << "'s weight to " << mGraph[it->first][i].first << ": " << mGraph[it->first][i].second << std::endl;
		}
	}
}

void graph::print_to_file(std::string out) {
	std::ofstream outfile;
	outfile.open(out);
	for (std::map<int, int[5]>::iterator it = mVisited.begin(); it != mVisited.end(); it++) {
		outfile << it->first << " " << mVisited[it->first][0] << " " << mVisited[it->first][1] << " " << mVisited[it->first][2] << std::endl;
	}
}

void graph::print_cousins(int num) {
    std::vector< std::pair<int, int> > g_1 = getCousins(num);
    std::cout << num << "'s cousins: " << std::endl;
    for ( int cuz = 0; cuz < g_1.size(); cuz++ ) {
        std::cout << g_1[cuz].first <<  " and their weight: " << g_1[cuz].second << std::endl;
    }
    std::cout << std::endl;
}

int graph::size(){
	return mGraph.size();
}

std::map<int, std::vector <std::pair<int, int> > >::iterator graph::start(){
	std::map<int, std::vector <std::pair<int, int> > >::iterator it = mGraph.begin();
	return it;
}

std::map<int, std::vector <std::pair<int, int> > >::iterator graph::finish() {
	std::map<int, std::vector <std::pair<int, int> > >::iterator it = mGraph.end();
	return it;
}

// void graph::remove(int index){
// 	mGraph.erase(index);
// }

std::vector< std::pair<int, int> > graph::at(int index){
	return mGraph.at(index);
}

int graph::getWeightFromVert(int index) {
	return mVisited[index][3];
}

int graph::getPrevFromVert(int index) {
	return mVisited[index][4];
}

int graph::mVisitedSize(){
	return mVisited.size();
}

std::vector<std::pair<int, int>> graph::operator[](int index) {
	return mGraph[index];
}

int graph::pairsize(int index) {
	return mGraph[index].size();
}

std::map<int, std::vector< std::pair<int, int> >> graph::gime() {
	return mGraph;
}