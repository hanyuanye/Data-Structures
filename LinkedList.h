#pragma once
#include <iostream>

struct Node {
	Node* next;
	Node* prev;
	int data;
	Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void addNode(int data);
	void deleteNode(int data);
	Node* getNode(int index);
	Node* searchNode(int data);
	void printList();
	void deleteList();
private:
	Node* head;
	Node* tail;
};

