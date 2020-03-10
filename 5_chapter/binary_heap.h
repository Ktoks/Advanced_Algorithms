#pragma once

#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>
#include <ctime>
#include <map>
#include <cmath>


class binaryHeap {
	
public:
	binaryHeap(std::vector<int> verts, std::vector<int> dists, int size);
	~binaryHeap();
	void insert(int x);
	void decreasekey(int index, int x);

	std::pair<int, int> deletemin();
	int makeheap(std::vector<int> verts, std::vector<int> dists);

	void bubbleup(int x, int i);
	void siftdown(std::pair<int, int> x, int i);
	int minchild(int i);

	int getSize();
	bool empty();
	double* getTimes();
	int getWeight(int index);
	

private:
	std::vector<int> mVerts;
	std::vector<int> mDists;
	int mSize;
	double mTimes[4];
	// 0 = makeheap()
	// 1 = deletemin()
	// 2 = insert()
	// 3 = decreasekey()
};