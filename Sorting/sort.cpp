//Joseph Madden, Nathaniel Kell
#include "mysort.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <cstdio>
#include <ctime>
using namespace std;

default_random_engine e;  // used by a distribution object to generate random numbers
uniform_real_distribution<double> u(0, 1); // a distribution object that generates random doubles in the range: [0,1]

// Helper routines
void randfill(vector<double> &a, int size){
	a.resize(0);
	for (int i = 0; i < size; i++)
		a.push_back(u(e));
}

void nearfill(vector<double> &a, int size) {
	a.resize(0);
	for (int i = 0; i < size; i++)
		a.push_back(u(e) * 20.0 - 10.0 + (double)i);
}


int main(){     
	clock_t start, finish;
	double  duration;
	vector<double> a;

	// Draw Chart Heading
	cout << setw(12) << " | ";
	cout << setw(16) << "InsertionSort";
	cout << setw(16) << "ShellSort";
	cout << setw(16) << "MergeSort";
	cout << setw(16) << "QuickSort" << endl;
	cout << setw(9) << " Size" << " | ";
	for (int i = 1; i <= 4; i++)
		cout << setw(8) << "  rand" << setw(8) << "  nstd";
	cout << endl;
	for (int i = 1; i <= 79; i++)
		cout << '-';
	cout << endl;

	int sizes[] = { 25000, 100000, 500000, 1000000, 2000000, 8000000, 24000000 };

	for (int k = 0; k < 7; ++k) {
		int size = sizes[k];
		cout << setw(9) << size;
		cout << " | ";

		if (k < 3){
			randfill(a, size);
			start = clock();
			insertionsort(a);
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("%8.3f", duration);
		} else {
			printf("%8.3f", 0.0);
		}

		nearfill(a, size);
		start = clock();
		insertionsort(a);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);
		
		randfill(a, size);
		start = clock();
		hibbardsort(a);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);

		nearfill(a, size);
		start = clock();
		hibbardsort(a);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);

		randfill(a, size);
		start = clock();
		mergesort(a);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);
					
		nearfill(a, size);
		start = clock();
		mergesort(a);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);
		
		randfill(a, size);
		start = clock();
		sort(a.begin(), a.end());
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);
	
		nearfill(a, size);
		start = clock();
		sort(a.begin(), a.end());
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%8.3f", duration);

		cout << endl;
	}

	cin.get();  // wait for Enter key
	return EXIT_SUCCESS;
}

