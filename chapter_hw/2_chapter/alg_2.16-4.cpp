#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <chrono>
#include <iostream>
#include <ctime>
#include <cstdlib>

// Compare x with the middle element.
// If x matches with middle element, we return the mid index.
// Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. So we recur for right half.
// Else (x is smaller) recur for the left half.
unsigned int binary_search_r(const std::vector<int> &data, int left, int right, int value)
{
	// check to make sure data exists
	if (right >= left)
	{
		// find the middle
		int mid = (left + right) / 2;
		// std::cout << "mid: " << mid << std::endl;
		// if value is in the middle
		if (data[mid] == value)
			return mid;
		// if value is smaller than mid
		if (value < data[mid])
			return binary_search_r(data, left, mid - 1, value);
		// otherwise, it's in the right side
		return binary_search_r(data, mid + 1, right, value);
	}
	// not in the list
	return -1;
}

unsigned int binary_search(const std::vector<int> &data, int value)
{
	return binary_search_r(data, 0, data.size() - 1, value);
}

// First, we compare the key with the element at mid1. If found equal, we return mid1.
// If not, then we compare the key with the element at mid2. If found equal, we return mid2.
// If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
// If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
// If not, then we recur to the second (middle) part.
unsigned int ternary_search_r(const std::vector<int> &data, int left, int right, int value)
{
	// check to make sure data exists
	if (right >= left)
	{
		// find the middle
		int onethird =left + (right - left) / 3;
		int twothird = right - (right - left) / 3;
		// std::cout << "mid: " << mid << std::endl;
		// if value is at 1/3
		if (data[onethird] == value)
			return onethird;
		// if value is at 2/3
		if (data[twothird] == value)
			return twothird;
		// if value is smaller than 1/3
		if (value < data[onethird])
			return ternary_search_r(data, left, onethird - 1, value);
		// if value is larger than 2/3
		else if (value > data[twothird])
			return ternary_search_r(data, twothird + 1, right, value);
		// otherwise, it's in the middle
		else
			return ternary_search_r(data, twothird + 1, onethird - 1, value);
	}
	// not in the list
	return -1;
}

unsigned int ternary_search(const std::vector<int> &data, int value)
{
	return ternary_search_r(data, 0, data.size() - 1, value);
}

// int main() {
//     std::vector<int> num_lst;
// 	int value = 8;
// 	num_lst = {0,1,2,3,4,5,6,7,8,9,10};
// 	int right = num_lst.size();
// 	int result = ternary_search(num_lst, value);
// 	std::string mstring = std::to_string(result);
// 	std::cout << mstring << std::endl;
//     return 0;
// }

int main(int argc, char **argv)
{
	// expects two command-line arguments, the data size (an integer) and the number of repetitions (an integer)
	std::string arg(argv[1]);
	std::stringstream ss(arg);
	int N;
	ss >> N;

	int reps;
	arg = argv[2];
	ss.clear();
	ss.str(arg);
	ss >> reps;
	// srand(NULL);

	// create random numbers
	// before beginning the timer
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(-100 * N, 100 * N);

	std::vector<std::vector<int>> nums(reps);
	int i, j, m, k, randint;
	for (j = 0; j < reps; j++)
	{
		for (i = 0; i < N; i++)
		{
			int r = distribution(generator);
			nums[j].push_back(r);
		}
	}

	std::vector<int> myvect;

	myvect.resize(pow(2,N));
	
	for (m = 0; m <= pow(2, N); m++)
	{
		myvect[m] = m;
	}
	clock_t t1 = clock();
	for (k = 0; k < reps; k++)
	{
		randint = std::rand() % myvect.size();
		// std::sort(nums[i].begin(), nums[i].end());
		binary_search(myvect, randint);
	}
	clock_t t2 = clock();
	clock_t dt = t2 - t1;
	double clocks_per_rep = ((double)dt) / reps;
	double seconds = clocks_per_rep / CLOCKS_PER_SEC;

	//std::cout << "time: " << dt << " " << seconds << std::endl;
	std::cout << N << "," << seconds << std::endl;

	// sort numbers

	// // show we're done
	// for(i = 0; i < N; i++)
	//   {
	//     std::cout << i << " " << nums[i] << std::endl;
	//   }

	return 0;
}