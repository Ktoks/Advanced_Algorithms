#include "binary_heap.h"

main()
{
    std::vector<int> test_verts;
    std::vector<int> test_weights;

    int size = std::pow(2, 20);

    test_verts.resize(size);
    test_weights.resize(size);
    for (int i = 0; i < size; i++)
    {
        test_verts[i] = i;
        test_weights[i] = size - i;
    }
    priority_queue queue(test_verts, test_weights, size);

    for (int v = 0; v < test_verts.size(); v++) {
        queue.setWeight(v, INFINITY);
        queue.setPrev(v, 0);
    }
    std::pair<int, int> u = {0,0};
    // queue.setWeight(0, 0);
    queue.siftdown(u, 0);
    while (!queue.empty()) {
        u = queue.deletemin();
        // for ()
    }

}