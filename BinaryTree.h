#pragma once
#include <iostream>
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void addNode(int data);
	void deleteNode(int data);
	Node* searchTree(int data);
	void printAscending();
	void printDescending();
	void deleteTree();
private:
	Node * root;
	void printInOrderHelper(Node* node);
	void printPostOrderHelper(Node* node);
	void deleteTreeHelper(Node* node);
};

