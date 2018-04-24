#include "SortingAlgorithms.h"
#include <iostream>

int main() {
	std::vector<int> data;
	data.push_back(100);
	data.push_back(10);
	data.push_back(1);
	data.push_back(-100);
	data.push_back(17);
	SortingAlgorithms sort(data);
	sort.print();
	sort.quickSort();
	sort.print();

	std::cin.get();
}