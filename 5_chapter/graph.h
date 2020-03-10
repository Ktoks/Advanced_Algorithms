#ifndef graph_h_
#define graph_h_
#include <cstdlib>
#include <map>
#include <vector>
#include <fstream>

class graph
{
public:
	graph(std::map<int, std::vector< std::pair<int, int> >> in_graph);
	~graph();
	const std::vector< std::pair<int, int> > getCousins(int num);
	void explore(int num);
	void dfs();
	void setStart(int num);
	void print_my_graph();
	void print_to_file(std::string out);
	void print_cousins(int num);
	// std::vector<std::std::pair<int, int><int, int>> getEdges(int v);
	int size();
	std::map<int, std::vector <std::pair <int, int> > >::iterator start();
	std::map<int, std::vector <std::pair <int, int> > >::iterator finish();
	// void remove(int index);
	std::vector< std::pair<int, int> > at(int index);
	int getWeightFromVert(int index);
	int getPrevFromVert(int index);
	int mVisitedSize();
	std::vector<std::pair<int, int>> operator[](int);
	int pairsize(int);




private:
	// u: {[v, w],[v,w]}
	std::map<int, std::vector< std::pair<int, int> >> mGraph;
	// index: [pre, post, cc, weight from first node, prev]
	std::map<int, int[5]> mVisited;
	int mNum;
	int mcc;
	int current_weight;
};


#endif