#include "Heap.H"
#include "Huffman.H"

#include<vector>
#include<iostream>

#include <stdlib.h>

//PRIVATE

template<class T>
void Heap<T>::heapify(){
	//TODO
	int currentNode = 0;

	while (currentNode < m_heap.size()){
		int leftChild =	(2*currentNode) + 1;
		int rightChild = 2 * (currentNode+1);
		int minChild = -1;
	
		if (leftChild < m_heap.size()){
			minChild = leftChild;
		}
		if (rightChild < m_heap.size()){
			if (minChild == -1) minChild = rightChild;
			else minChild = (m_cmp(m_heap[minChild],m_heap[rightChild])) ? minChild : rightChild;
		}
		

		if (minChild == -1 || m_cmp(m_heap[currentNode],m_heap[minChild])) return;

		T tmp = m_heap[minChild];
		m_heap[minChild] = m_heap[currentNode];
		m_heap[currentNode] = tmp;

		currentNode = minChild;
	}
}

template<class T>
std::vector<T> Heap<T>::toVector(){
	return m_heap; 
}

// PUBLIC 

template <class T>
int Heap<T>::size(){
	return m_heap.size();
}

template <class T>
void Heap<T>::pop(){
	if (m_heap.size() < 1){
		throw std::out_of_range("Attempting to pop from an empty heap");
	}

	m_heap[0] = m_heap[m_heap.size()-1];	
	m_heap.erase(m_heap.end()-1);
	heapify();
}

template <class T>
void Heap<T>::push(T input){
	m_heap.emplace_back(input);
	
	if (m_heap.size() == 1) return;

	int currentNode = m_heap.size() - 1;

	while (currentNode > 0){
		int parentNode = (currentNode & 0x1) ? (currentNode - 1)/2 : (currentNode/2)-1;
		if (!m_cmp(m_heap[currentNode],m_heap[parentNode])){
			break;
		}

		T tmp = m_heap[currentNode];
		m_heap[currentNode] = m_heap[parentNode];
		m_heap[parentNode] = tmp;

		currentNode = parentNode;
	}
}

template <class T>
bool Heap<T>::isEmpty(){
	return (m_heap.size() == 0) ? true : false;
}

template <class T>
T& Heap<T>::top(){
	if (m_heap.size() < 1){
		throw std::out_of_range("Attempting to access element from an empty heap");
	}

	return m_heap[0];
}


/*
int main(int argc, char * argv[]){
	auto cmp = [](const int& a,const int& b)->bool{return a<b;}; 
	Heap<int> tst = MinHeap<int>();

	if (argc > 1){
		int index = 1;
		while (index < argc){
			tst.push(atoi(argv[index++]));
		}
		std::cout << "finished pushing" << std::endl;
		while (!tst.isEmpty()){
			std::cout << tst.top() << ", ";
			tst.pop();
		}

	}
	else{
		std::cout << "No input given" << std::endl;
	}

	
	return 0;
}
*/
template class Heap<int>;
template class Heap<std::shared_ptr<Node>>;

