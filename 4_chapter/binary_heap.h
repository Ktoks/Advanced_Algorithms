#pragma once

#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>
#include <ctime>


struct pair {
    int v;
    int w;
};


class priority_queue {
    
public:
    priority_queue(std::vector<int> heap, int size);
    ~priority_queue();
    void insert(int x);
    void decreasekey(int x);

    int deletemin();
    int makeheap(std::vector<int> s);

    void bubbleup(int x, int i);
    void siftdown(int x, int i);
    int minchild(int i);

    int getSize();
    bool empty();
    double* getTimes();


private:
    std::vector<int> mHeap;
    int mSize;
    double mTimes[4];
    // 0 = makeheap()
    // 1 = deletemin()
    // 2 = insert()
    // 3 = decreasekey()
};