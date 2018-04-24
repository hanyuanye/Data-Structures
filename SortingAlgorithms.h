#pragma once
#include <vector>
#include <iostream>
class SortingAlgorithms
{
public:
	SortingAlgorithms(std::vector<int> data);
	~SortingAlgorithms();
	void print();
	void update(std::vector<int> data);

	//Sorting Functions
	void quickSort();
private:
	std::vector<int> data;

	void quickSortHelper(int low, int high);
	int quickSortPartition(int low, int high);
	void swap(int index1, int index2);
};

