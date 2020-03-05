#ifndef graph_h_
#define graph_h_
#include <cstdlib>
#include <map>
#include <vector>
#include <fstream>

struct pair {
    int v;
    int weight;
};

class graph
{
public:
	graph(std::map<int, std::vector< pair >> in_graph);
	~graph();
	const std::vector< pair > getCousins(int num);
	void explore(int num);
	void dfs();
	void setStart(int num);
	void print_my_graph();
	void print_to_file(std::string out);
	void print_cousins(int num);

private:
	// u: {[v, w],[v,w]}
	std::map<int, std::vector< pair >> mGraph;
	// index: [pre, post, cc]
	std::map<int, int[3]> mVisited;
	int mNum;
	int mcc;
};


#endif