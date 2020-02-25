#include "binary_heap.h"

int INFINITY = 2000000000;

main(int argc, char **argv){
    int size = 10;
    std::vector<int> verts;
    std::vector<int> dists;
    verts.resize(size);
    dists.resize(size);
    clock_t time_req;
    for (int i = 0; i < size; i++) {
        verts[i] = i;
        dists[i] = i;
    }
    time_req = clock();
    priority_queue queue(verts, dists, size);
    while (!queue.empty()) {
        std::pair<int, int> popped = queue.deletemin();

        std::cout << "MinVect: " << popped.first << " MinDist: " << popped.second << std::endl;
    }
    time_req = clock() - time_req;
    std::cout << "Time to run Djikstra's: " << (float)time_req/CLOCKS_PER_SEC << std::endl;
}