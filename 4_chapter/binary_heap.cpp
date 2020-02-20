#include "binary_heap.h"
#include <algorithm>


priority_queue::priority_queue(std::vector<int> heap, int size):
    mSize(size)
{
    // mHeap.resize(mSize * 2);
    makeheap(heap);
}

priority_queue::~priority_queue(){

}

// as book implements it
void priority_queue::insert(int x){
    double time_req;
    time_req = clock();
    // pass heap, new value, and space at end of heap
    mSize++;
    bubbleup(x,mSize);
    mTimes[2] += clock() - time_req;

}

void priority_queue::decreasekey(int x){
    double time_req;
    time_req = clock();
    // pass heap, val to be changed, and location 

    bubbleup(x,mHeap[x]);
    mTimes[3] += clock() - time_req;

}

int priority_queue::deletemin(){
    double time_req;
    time_req = clock();

    if (mSize == 0) {
        mTimes[1] += clock() - time_req;
        return -1;
    }
    int x = mHeap[0];
    siftdown(mSize, 0);
    mSize--;
    mHeap[mSize] = -1;

    mTimes[1] += clock() - time_req;
    return x;
}

int priority_queue::makeheap(std::vector<int> s){
    // mSize = s.size();
    double time_req;
    time_req = clock();
    mSize = 0;
    int size = s.size();
    mHeap.resize(size * 2 + 2);

    for(int i = 0; i < size; i++) {
        mHeap[size + i] = s[i];
        mSize ++;
    }
    // std::cout << "In makeheap" << std::endl;
    for (int j = mSize - 1; j > 0; j--){
        siftdown(mHeap[size + j], j);
    }
    // std::cout << "Past siftdown loop" << std::endl;
    mTimes[0] += clock() - time_req;
}

void priority_queue::bubbleup(int x, int i){
    int p = i/2 + (i % 2 != 0);
    // while we haven't reached the beginning, and targeted i > current i
    while (i != 1 and mHeap[p] > x) {
        mHeap[i] = mHeap[p];
        i = p;
        p = i/2 + (i % 2 != 0);
    }
    mHeap[i] = x;
}

void priority_queue::siftdown(int x, int i){
    int c = minchild(i);
    mHeap[i] = x;

    // so long as c is not negative and 
    while (c > 0 and mHeap[c] < mHeap[i]) {
        int temp = mHeap[i];
        mHeap[i] = mHeap[c];
        mHeap[c] = temp;        // swap
        i = c;
        c = minchild(i);
    }
    // mHeap[i] = x;
}

// I think this is correct
int priority_queue::minchild(int i){
    int leftChild = 2 * i + 1;
    if (leftChild > mSize) {
        return -1;
    }
    int rightChild = 2 * i + 2;
    if (rightChild < mSize) {
        if ( (mHeap[leftChild]) < mHeap[rightChild]) {
            return leftChild;
        }
        return rightChild;
    }
    return leftChild;
}

int priority_queue::getSize() {
    return mSize;
}

bool priority_queue::empty() {
    return mSize == 0;
}

double* priority_queue::getTimes() {
    return mTimes;
}
