#include "Heap.h"



Heap::Heap()
{
}


Heap::~Heap()
{
}

int Heap::getMin()
{
	if (!heap.empty()) {
		return heap[0];
	}
}

void Heap::heapify(int index)
{
	int left = getLeft(index);
	int right = getRight(index);
	int min = index;
	if (left < heap.size() && heap[left] < heap[min]) {
		min = left;
	}
	if (right < heap.size() && heap[right] < heap[min]) {
		min = right;
	}
	if (min != index) {
		iter_swap(heap.begin() + index, heap.begin() + min);
		heapify(min);
	}
}

int Heap::extractMin()
{
	if (heap.empty()) {
		return NULL;
	}
	int root = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.erase(heap.end() - 1);
	heapify(0);
	return root;
}

void Heap::decreaseKey(int index, int value)
{
	heap[index] = value;
	while (index != 0 && heap[getParent(index)] > heap[index]) {
		iter_swap(heap.begin() + getParent(index), heap.begin() + index);
		index = getParent(index);
	}
}

void Heap::insert(int key)
{
	heap.push_back(key);
	int index = heap.size() - 1;
	while (index != 0 && heap[getParent(index)] > heap[index]) {
		iter_swap(heap.begin() + getParent(index), heap.begin() + index);
		index = getParent(index);
	}
}

void Heap::remove(int index)
{
	decreaseKey(index, INT_MIN);
	extractMin();
}

int Heap::getLeft(int index)
{
	return 2 * index + 1;
}

int Heap::getRight(int index)
{
	return 2 * index + 2;
}

int Heap::getParent(int index)
{
	return (index - 1) / 2;
}
