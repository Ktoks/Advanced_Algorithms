#include "binary_heap.h"

main(int argc, char **argv){
    int size = 10;
    std::vector<int> heap;
    heap.resize(size);
    clock_t time_req;
    for (int i = 0; i < size; i++) {
        heap[i] = i + 1;
    }
    time_req = clock();
    priority_queue queue(heap, size);
    while (!queue.empty()) {
        std::cout << "Min: " << queue.deletemin() << std::endl;
    }
    time_req = clock() - time_req;
    std::cout << "Time to run Djikstra's: " << (float)time_req/CLOCKS_PER_SEC << std::endl;
}