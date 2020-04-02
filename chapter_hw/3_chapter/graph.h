#ifndef graph_h_
#define graph_h_
#include <cstdlib>
#include <map>
#include <vector>
#include <fstream>
#include <iterator>


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
	std::vector<std::pair<int, int>> getEdges(int v);
	int size();
	std::pair<int, int> operator [](int i);
	std::map<int, std::vector <std::pair <int, int> > >::iterator start();


private:
	// u: {[v, w],[v,w]}
	std::map<int, std::vector< std::pair<int, int> >> mGraph;
	// index: [pre, post, cc]
	std::map<int, int[3]> mVisited;
	int mNum;
	int mcc;
};


#endif