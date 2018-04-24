#include "LinkedList.h"



LinkedList::LinkedList()
{
	head = new Node(0);
	tail = new Node(0);
	head->next = tail;
	tail->prev = head;
}


LinkedList::~LinkedList()
{
	deleteList();
}

void LinkedList::addNode(int data)
{
	Node* node = new Node(data);
	if (head->next == tail) {
		head->next = node;
		node->next = tail;
		node->prev = head;
		tail->prev = node;
		return;
	}
	Node* curr = head;
	while (curr != tail && curr->data < node->data) {
		curr = curr->next;
	}
	if (curr != head) {
		curr = curr->prev;
	}
	node->next = curr->next;
	curr->next = node;
	node->prev = curr;
}

void LinkedList::deleteNode(int data)
{
	Node* curr = head;
	while (curr != tail && curr->data != data) {
		curr = curr->next;
	}
	if (curr != tail) {
		Node* prev = curr->prev;
		prev->next = curr->next;
		Node* next = curr->next;
		next->prev = curr->prev;
		delete curr;
	}
}

Node* LinkedList::getNode(int index)
{
	Node* curr = head;
	for (int i = 0; i < index; i++) {
		if (curr == tail) {
			return nullptr;
		}
		curr = curr->next;
	}
	return curr;
}

Node* LinkedList::searchNode(int data)
{
	Node* curr = head;
	while (curr != tail && curr->data != data) {
		curr = curr->next;
	}
	return curr;
}

void LinkedList::deleteList()
{
	Node* curr = head;
	Node* prev;
	while (curr != tail) {
		prev = curr;
		curr = curr->next;
		delete prev;
	}
}

void LinkedList::printList()
{
	Node* curr = head;
	while (curr != tail) {
		curr = curr->next;
		if (curr != tail) {
			std::cout << curr->data << std::endl;
		}
	}
}
