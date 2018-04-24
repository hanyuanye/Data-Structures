#include "SortingAlgorithms.h"


SortingAlgorithms::SortingAlgorithms(std::vector<int> data)
{
	this->data = data;
}

SortingAlgorithms::~SortingAlgorithms()
{
}

void SortingAlgorithms::print()
{
	std::cout << "Printing Data" << std::endl;
	for (int i = 0; i < data.size(); i++) {
		std::cout << data[i] << std::endl;
	}
}

void SortingAlgorithms::update(std::vector<int> data)
{
	this->data = data;
}

void SortingAlgorithms::quickSort()
{
	quickSortHelper(0, data.size() - 1);
}

void SortingAlgorithms::quickSortHelper(int low, int high)
{
	if (low < high) {
		int partitionIndex = quickSortPartition(low, high);
		quickSortHelper(low, partitionIndex - 1);
		quickSortHelper(partitionIndex + 1, high);
	}
}

int SortingAlgorithms::quickSortPartition(int low, int high)
{
	int pivot = data[high];
	int partitionCounter = low - 1;
	for (int i = 0; i < high; i++) {
		if (data[i] <= pivot) {
			partitionCounter++;
			swap(partitionCounter, i);
		}
	}
	swap(partitionCounter + 1, high);
	return partitionCounter + 1;
}

void SortingAlgorithms::swap(int index1, int index2)
{
	int temp = data[index1];
	data[index1] = data[index2];
	data[index2] = temp;
}

