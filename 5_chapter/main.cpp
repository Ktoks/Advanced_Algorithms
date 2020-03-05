#include "binary_heap.h"
#include "graph.h"

main()
{
	std::vector<int> verts;
	std::vector<int> weights;

	int size = std::pow(2, 20);

	verts.resize(size);
	weights.resize(size);
	for (int i = 0; i < size; i++)
	{
		verts[i] = i;
		weights[i] = size - i;
	}
	verts[0] = 0;
	weights[0] = 0;
	binaryHeap heap(verts, weights, size);

	while (!heap.empty()) {
		u = heap.deletemin();
		for (int v = 0; v < EDGES; v++) {
			if (heap.getWeight(v) > distance_of(u,v)) {
				heap.setWeight(v, distance_of(u, v));heap   // prim, not heap
				heap.decreasekey(v, heap.getWeight(v));
				setPrev(v, u.first);                        // prim or graph
			}
		}
	}

}