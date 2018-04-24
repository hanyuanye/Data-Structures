#pragma once
#include <vector>
#include <algorithm>

struct PriorityNode {
	int data;
	int priority;
	PriorityNode(int data, int priority) : data(data), priority(priority) {}
};

class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();
	void insert(int data, int priority);
	PriorityNode getHighestPriority();
	void deleteHighestPriority();
private:
	int getParent(int index);
	int getLeft(int index);
	int getRight(int index);
	void heapify(int index);
	std::vector<PriorityNode> queue;
};
