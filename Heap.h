#pragma once
#include <vector>
#include <algorithm>
class Heap
{
public:
	Heap();
	~Heap();
	int getMin();
	void heapify(int index);
	int extractMin();
	void decreaseKey(int index, int value);
	void insert(int key);
	void remove(int index);
private:
	int getLeft(int index);
	int getRight(int index);
	int getParent(int index);
	std::vector<int> heap;
};

