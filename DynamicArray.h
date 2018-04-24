#pragma once
#include <cmath>
const int initialSize = 8;
const float multiplier = 1.6;

template <typename T>
class DynamicArray
{
private:
	T * ptr;
	int maxSize;
	int containerSize;
public:
	DynamicArray();
	void push_back(T t);
	void resize(int size, T t);
	T at(int index);
	int size();
	void sort();
};

template <typename T>
DynamicArray<T>::DynamicArray() {
	ptr = new T[initialSize];
	maxSize = initialSize;
	containerSize = 0;
}

template <typename T>
void DynamicArray<T>::push_back(T t) {
	if (containerSize == maxSize) {
		maxSize = std::round(maxSize * multiplier);
		T * newptr = new T[maxSize];
		for (int i = 0; i < containerSize; i++) {
			newptr[i] = ptr[i];
		}
		newptr[containerSize] = t;
		containerSize++;
		delete ptr;
		ptr = newptr;
		return;
	}
	ptr[containerSize] = t;
	containerSize++;
}

template <typename T>
void DynamicArray<T>::resize(int size, T t) {
	if (size >= this->maxSize) {
		T * newptr = new T[size];
		delete ptr;
		ptr = newptr;
	}
	else {
		T * newptr = new T[initialSize];
		delete ptr;
		ptr = newptr;
	}
	for (int i = 0; i < size; i++) {
		ptr[size] = t;
	}
	this->size = size;
}

template <typename T>
T DynamicArray<T>::at(int index) {
	if (index >= containerSize || index < 0) {
		return NULL;
	}
	return ptr[index];
}

template <typename T>
int DynamicArray<T>::size() {
	return this->containerSize;
}

template <typename T>
void DynamicArray<T>::sort() {
	//implement quicksort
	
}