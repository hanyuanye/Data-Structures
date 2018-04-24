#include "PriorityQueue.h"



PriorityQueue::PriorityQueue()
{

}


PriorityQueue::~PriorityQueue()
{

}

void PriorityQueue::insert(int data, int priority)
{
	PriorityNode node(data, priority);
	queue.push_back(node);
	int index = queue.size() - 1;
	while (index != 0 && queue[index].priority < queue[getParent(index)].priority) {
		iter_swap(queue.begin() + index, queue.begin() + getParent(index));
		index = getParent(index);
	}
}

PriorityNode PriorityQueue::getHighestPriority()
{
	return queue[0];
}

void PriorityQueue::deleteHighestPriority()
{
	if (queue.empty()) {
		return;
	}
	queue[0] = queue[queue.size() - 1];
	queue.erase(queue.end() - 1);
	heapify(0);
}

void PriorityQueue::heapify(int index)
{
	int left = getLeft(index);
	int right = getRight(index);
	int max = index;
	if (left < queue.size() && queue[left].priority > queue[max].priority) {
		max = left;
	}
	if (right < queue.size() && queue[right].priority > queue[max].priority) {
		max = right;
	}
	if (index != max) {
		iter_swap(queue.begin() + max, queue.begin() + index);
		heapify(max);
	}
}

int PriorityQueue::getParent(int index)
{
	return (index - 1) / 2;
}

int PriorityQueue::getLeft(int index)
{
	return index * 2 + 1;
}

int PriorityQueue::getRight(int index)
{
	return index * 2 + 2;
}
