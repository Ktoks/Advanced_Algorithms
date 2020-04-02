#include "binary_heap.h"

main(int argc, char **argv)
{

    std::vector<std::vector<double>> times;
    times.resize(4);

    std::vector<int> test_verts;
    std::vector<int> test_weights;
    for (int k = 4; k <= 28; k++)
    {
        int size = std::pow(2, k);

        std::cout << "Step " << k - 3 << " Beginning." << std::endl;
        clock_t time_req;
        time_req = clock();

        test_verts.resize(size);
        test_weights.resize(size);
        for (int i = 0; i < size; i++)
        {
            test_verts[i] = i;
            test_weights[i] = size - i;
        }
        // std::cout << "Set verts and weights on step " << k - 3 << "." << std::endl;

        priority_queue queue(test_verts, test_weights, size);
        // std::cout << "Initialized queue on step " << k - 3 << "." << std::endl;

        while (!queue.empty())
        {
            std::pair<int, int> you = queue.deletemin();
        }
        // std::cout << "Queue is empty on step " << k - 3 << "." << std::endl;

        for (int j = 0; j < size; j++)
        {
            queue.insert(test_verts[j]);
            queue.decreasekey(j, test_verts[j]);
        }
        // std::cout << "Inserted on step " << k - 3 << "." << std::endl;

        time_req = clock() - time_req;
        double *tim = queue.getTimes();
        times[0].push_back(tim[0] / CLOCKS_PER_SEC);
        times[1].push_back(tim[1] / CLOCKS_PER_SEC);
        times[2].push_back(tim[2] / CLOCKS_PER_SEC);
        times[3].push_back(tim[3] / CLOCKS_PER_SEC);
        // std::cout << "Pushed back times on step " << k - 3 << "." << std::endl;
    }
    for (int n = 0; n < times[0].size(); n++)
    {
        std::cout << times[0][n] << std::endl;
    }
    std::cout << std::endl;
    for (int n = 0; n < times[1].size(); n++)
    {
        std::cout << times[1][n] << std::endl;
    }
    std::cout << std::endl;
    for (int n = 0; n < times[2].size(); n++)
    {
        std::cout << times[2][n] << std::endl;
    }
    std::cout << std::endl;
    for (int n = 0; n < times[3].size(); n++)
    {
        std::cout << times[3][n] << std::endl;
    }
}