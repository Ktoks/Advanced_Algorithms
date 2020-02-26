#ifndef graph_h_
#define graph_h_
#include <cstdlib>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>

// struct pair {
//     int v;
//     int weight;
// };

class graph
{
public:
	graph(std::map<int, std::vector< std::pair<int,int> >> in_graph);
	~graph();
	std::vector< std::pair<int,int> > getCousins(int num);
	void explore(int num);
	void dfs();
	void setStart(int num);
	void print_my_graph();
	void print_to_file(std::string out);
	void print_cousins(int num);
	int size();
	std::map<int, std::vector< std::pair<int,int> >>::iterator begin();
	std::map<int, std::vector< std::pair<int,int> >>::iterator end();
	int getVert(std::map<int, std::vector< std::pair<int,int> >>::iterator it);
	int getDist(std::map<int, std::vector< std::pair<int,int> >>::iterator it, int index);
	int getNextVert(std::map<int, std::vector< std::pair<int,int> >>::iterator it, int index);

private:
	// u: {[v, w],[v,w]}
	std::map<int, std::vector< std::pair<int,int> >> mGraph;
	// index: [pre, post, cc]
	std::map<int, int[3]> mVisited;
	int mNum;
	int mcc;
};


#endif