#pragma once

#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>
#include <ctime>
#include <map>
#include <cmath>


extern int INFINITY;


class priority_queue {
    
public:
    priority_queue(std::vector<int> verts, std::vector<int> dists, int size);
    ~priority_queue();
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
    void setWeight(int index, int value);
    void setPrev(int index, int value);
    

private:
    std::vector<int> mVerts;
    std::vector<int> mDists;
    std::vector<int> mPrevs;
    int mSize;
    double mTimes[4];
    // 0 = makeheap()
    // 1 = deletemin()
    // 2 = insert()
    // 3 = decreasekey()
};