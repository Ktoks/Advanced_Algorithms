#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <chrono>
#include <iostream>
#include <ctime>
#include <cstdlib>

int fib1(int N) {
    if (N == 0)
      return 0;
    if (N == 1)
      return 1;
    return fib1(N-1) + fib1(N-2);
}

int fib2(int N) {
  if (N == 0) {
    return 0;
  }
  int n_array [N + 1];
  n_array[0] = 0;
  n_array[1] = 1;
  for (int i = 2; i <= N; i++) {
    n_array[i] = n_array[i - 1] + n_array[i - 2];
  }
  return n_array[N];
}

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

  // create random numbers
  // before beginning the timer
  unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> distribution(-100*N, 100*N);
  
  std::vector< std::vector<int> > nums(reps);
  int i,j;
  for( j = 0; j < reps; j++ ) {
    for(i = 0; i < N; i++)
      {
        int r = distribution(generator);
        nums[j].push_back(r);
      }
  }

  
  // sort numbers
  clock_t t1 = clock();
  for(i = 0; i < reps; i++) {
    // std::sort(nums[i].begin(), nums[i].end());
    fib1(N);
  }
  clock_t t2 = clock();
  clock_t dt = t2 - t1;
  double clocks_per_rep = ((double)dt)/reps;
  double seconds = clocks_per_rep/CLOCKS_PER_SEC;

  //std::cout << "time: " << dt << " " << seconds << std::endl;
  std::cout << N << "," << seconds << std::endl;


  // // show we're done
  // for(i = 0; i < N; i++)
  //   {
  //     std::cout << i << " " << nums[i] << std::endl;
  //   }

  return 0;
}
