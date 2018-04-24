#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
}


BinaryTree::~BinaryTree()
{
	deleteTree();
}

void BinaryTree::addNode(int data)
{
	if (root == nullptr) {
		root = new Node(data);
		return;
	}
	Node* curr = root;
	Node* prev = root;
	while (curr != nullptr) {
		prev = curr;
		if (data > curr->data) {
			curr = curr->right;
		}
		else if (data < curr->data) {
			curr = curr->left;
		}
		else {
			return;
		}
	}
	Node* node = new Node(data);
	if (prev->data > node->data) {
		prev->left = node;
	}
	else {
		prev->right = node;
	}
}

void BinaryTree::deleteNode(int data)
{
	Node* toDelete = searchTree(data);
	if (toDelete != nullptr) {
		delete toDelete;
	}
}

Node* BinaryTree::searchTree(int data)
{
	Node* curr = root;
	while (curr != nullptr && curr->data != data) {
		if (data > curr->data) {
			curr = curr->right;
		}
		else if (data < curr->data) {
			curr = curr->left;
		}
		else {
			return nullptr;
		}
	}
	return curr;
}

void BinaryTree::printAscending()
{
	printInOrderHelper(root);
}

void BinaryTree::printDescending()
{
	printPostOrderHelper(root);
}

void BinaryTree::deleteTree()
{
	deleteTreeHelper(root);
}

void BinaryTree::printInOrderHelper(Node * node)
{
	if (node == nullptr) {
		return;
	}

	printInOrderHelper(node->left);
	std::cout << node->data << std::endl;
	printInOrderHelper(node->right);
}

void BinaryTree::printPostOrderHelper(Node * node)
{
	if (node == nullptr) {
		return;
	}

	printPostOrderHelper(node->right);
	std::cout << node->data << std::endl;
	printPostOrderHelper(node->left);
}

void BinaryTree::deleteTreeHelper(Node * node) {
	if (node == nullptr) {
		return;
	}
	deleteTreeHelper(node->left);
	deleteTreeHelper(node->right);
	delete node;
}

