#ifndef SORTING_H
#define SORTING_H

#define UNIT_TIME std::chrono::microseconds

#include <iostream>
#include <vector>
#include <chrono>	// for std::chrono::high_resolution_clock::now(), std::chrono::duration_cast()
					// std::chrono::hours, minutes, seconds, miliseconds, microseconds, nanoseconds

void insertionSort(std::vector<int>& data);
void mergeSort(std::vector<int>& data);
void heapSort(std::vector<int>& data);
void shellSort(std::vector<int>& data);
void quickSort(std::vector<int>& data);

#endif