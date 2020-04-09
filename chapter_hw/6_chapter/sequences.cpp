#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

double timereq;

int min(int one, int two, int three) {
	return std::min(std::min(one, two), three);
}



int edit_distance(std::string first, std::string second) {
	int first_size = first.size();
	int second_size = second.size();
	int distance[first_size + 1][second_size + 1];
	
	for (int i = 0; i <= first_size; i++) {
		for (int j = 0; j <= second_size; j++) {
			if (i == 0) {
				distance[i][j] = j;
			}
			else if (j == 0) {
				distance[i][j] = i;
			}
			else if (first[i - 1] == second[i - 1]) {
				distance[i][j] = distance[i - 1][j - 1];
			}
			else {
				distance[i][j] = 1 + min(distance[i][j - 1],		// insert
										distance[i - 1][j],			// remove
										distance[i - 1][j - 1]);	// replace
			}
		}
	}
	return distance[first_size][second_size];
}

int main(int argc, char **argv) {
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " IN_FILENAME OUT/COUNT_FILENAME [-FLAGS]" << std::endl;
		return 1;
	}

	std::ifstream fin;
	std::ofstream fout;
	fin.open(argv[1]);
	fout.open(argv[2]);

	std::string line, first, second;
	if (fin.is_open()) {
		if (!fout){
			std::cerr << "ERROR WRITING TO A FILE! " << argv[2]  << " or " << std::endl;
			return 1;
		}
		while (!fin.eof()) {
			getline ( fin, line);
            // std::cout << line << std::endl;
			std::istringstream iss(line);
			iss >> first;
			iss >> second;
			// std::cout << "First:" << first << ",Second:" << second << ";" << std::endl;
			
			double temptime;
			int isfout;
			temptime = clock();
			isfout = edit_distance(first, second);

			timereq += clock() - temptime;
			if (std::string(argv[3]) != "-c") {
				fout << isfout << std::endl;
			}
		}
		if (std::string(argv[3]) == "-c") {
			fout << timereq / CLOCKS_PER_SEC << std::endl;
		}
		// 	while (fin >> line) {
		// 	// getline ( fin, line, ' ');
        //     std::cout << line << std::endl;
		// }
    } else {
		std::cerr << "COULD NOT OPEN FILE " << argv[1] << std::endl;
		return 1;
	}
	fin.close();
	fout.close();
	return 0;
}
/*
Create a program to read pairs of words from a file. 
The filename will be given on the command line. 
Each line will contain a pair of space separated words. 
Feed each pair of words to the edit distance function. 
Display the edit distance, with one number per line.
*/