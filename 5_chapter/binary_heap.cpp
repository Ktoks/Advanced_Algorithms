#include "binary_heap.h"
#include <algorithm>

binaryHeap::binaryHeap(std::vector<int> dists, std::vector<int> verts, int size) : mSize(size)
{
	mTimes[0] = 0;
	mTimes[1] = 0;
	mTimes[2] = 0;
	mTimes[3] = 0;
	makeheap(dists, verts);
}

binaryHeap::~binaryHeap()
{
}

// as book implements it
void binaryHeap::insert(int x)
{
	double time_req;
	time_req = clock();
	// pass heap, new value, and space at end of heap
	mSize++;
	bubbleup(x, mSize);
	mTimes[2] += clock() - time_req;
}

void binaryHeap::decreasekey(int index, int x)
{
	double time_req;
	time_req = clock();
	// pass heap, val to be changed, and location
	mDists[index] = x; 
	bubbleup(x, index);
	mTimes[3] += clock() - time_req;
}

std::pair<int, int> binaryHeap::deletemin()
{
	double time_req;
	time_req = clock();

	if (mSize == 0)
	{
		mTimes[1] += clock() - time_req;
		return {0, 0};
	}

	std::pair<int, int> x;
	x.first = mVerts[0];
	x.second = mDists[0];
	// int x = mDists[0];
	
	mSize--;
	siftdown({mVerts[mSize], mDists[mSize]}, 0);

	mVerts[mSize] = 0;
	mDists[mSize] = 0;

	mTimes[1] += clock() - time_req;
	return x;
}

int binaryHeap::makeheap(std::vector<int> verts, std::vector<int> dists)
{
	double time_req;
	time_req = clock();

	mSize = 0;
	int size = verts.size();
	mVerts.resize(size * 2 + 2);
	mDists.resize(size * 2 + 2);

	for (int i = 0; i < size; i++)
	{
		mVerts[i] = verts[i];
		mDists[i] = dists[i];
		mSize++;
	}
	for (int j = mSize-1; j >= 0; j--)
	{
		siftdown({mVerts[j], mDists[j]}, j);
	}
	mTimes[0] += clock() - time_req;
}

void binaryHeap::bubbleup(int x, int i)
{
	int p = i / 2 + (i % 2 != 0);
	// while we haven't reached the beginning, and targeted i > current i
	while (i != 1 and mDists[p] > mDists[x])
	{
		int temp_vert = mVerts[i];
		int temp_dist = mDists[i];
		mVerts[i] = mVerts[p];
		mDists[i] = mDists[p];
		i = p;
		p = i / 2 + (i % 2 != 0);
	}
	mVerts[i] = x;
}

void binaryHeap::siftdown(std::pair<int, int> x, int i)
{
	int c = minchild(i);
	if (i == 0)
	{
		mVerts[i] = x.first;
		mDists[i] = x.second;
	}

	while (c != 0 and mDists[c] < x.second)
	{
		int temp_verts = mVerts[i];
		int temp_dists = mDists[i];
		mVerts[i] = mVerts[c];
		mDists[i] = mDists[c];
		mVerts[c] = temp_verts;
		mDists[c] = temp_dists;
		i = c;
		c = minchild(i);
	}
	// mHeap[i] = x;
}

// I think this is correct
int binaryHeap::minchild(int i)
{
	int leftChild = 2 * i + 1;
	if (leftChild > mSize)
	{
		return 0;
	}
	int rightChild = 2 * i + 2;
	if (rightChild < leftChild)
	{
		return rightChild;
	}
	return leftChild;
}

int binaryHeap::getSize()
{
	return mSize;
}

bool binaryHeap::empty()
{
	return mSize == 0;
}

double *binaryHeap::getTimes()
{
	return mTimes;
}

int binaryHeap::getWeight(int index){
	return mDists[index];
}

