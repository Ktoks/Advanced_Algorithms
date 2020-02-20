#include "binary_heap.h"
#include <algorithm>


priority_queue::priority_queue(std::vector<int> heap, int size):
    mSize(size)
{
    mHeap.resize(mSize * 2);
    for(int i = 0; i < mSize; i++) {
        mHeap[i] = heap[i]; 
    }
}

priority_queue::~priority_queue(){

}

// as book implements it
void priority_queue::insert(int x){
    // pass heap, new value, and space at end of heap
    mSize++;
    bubbleup(x,mSize);
}

void priority_queue::decreasekey(int x){
    // pass heap, val to be changed, and location 
    bubbleup(x,mHeap[x]);
}

int priority_queue::deletemin(){
    if (mSize == 0) {
        return -1;
    }
    int x = mHeap[0];
    siftdown(0);
    mSize--;
    return x;
}

int priority_queue::makeheap(std::vector<int> s){
    mSize = s.size();
    std::vector<int> mHeap;
    mHeap.resize(mSize * 2);
    for(int i = 0; i < mSize; i++) {
        mHeap[i] = s[i];
    }
    for (int j = mSize - 1; j > 0; j--){
        siftdown(j);
    }
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

void priority_queue::siftdown(int i){
    int c = minchild(i);
    // so long as c is not negative and 
    while (c > 0 and mHeap[c] < mHeap[i]) {
        // int temp;
        mHeap[i] = mHeap[c];
        i = c;
        c = minchild(i);
    }
    // mHeap[i] = mHeap[c];
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

