#ifndef __HEAP_H__
#define __HEAP_H__

#include <vector>
#include <functional>

template <typename T>
class Heap{
protected:
	std::function<bool(const T&,const T&)> m_cmp;
	std::vector<T> m_heap;
		
	void heapify();

public:
	Heap(std::function<bool(const T&, const T&)> cmp): m_cmp(cmp), m_heap(){}

	~Heap(){}

	void pop();
	void push(T);
	int size();
	bool isEmpty();
	void printHeap();
	T& top();
	std::vector<T> toVector();
};

template <typename T>
class MinHeap : public Heap<T> {
public:
	MinHeap(): Heap<T>([](const T& a,const T& b)->bool{return a < b;}) {}
	MinHeap(std::function<bool(const T&, const T&)> comparator) : Heap<T>(comparator) {}
};

template <typename T>
class MaxHeap : public Heap<T> {
public:
	MaxHeap(): Heap<T>([](const T& a,const T& b)->bool{return a >= b;}) {}
	MaxHeap(std::function<bool(const T&, const T&)> comparator) : Heap<T>(comparator) {}
};
#endif
