#pragma once

#include <cstdlib>
#include <fstream>
#include <vector>


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
    void siftdown(int i);
    int minchild(int i);

private:
    std::vector<int> mHeap;
    int mSize;

};