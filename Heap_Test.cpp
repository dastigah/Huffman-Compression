#include "gtest/gtest.h"

#include "Heap.H"

#include <iostream>
#include <string>
#include <vector>

#include<bits/stdc++.h>


class HeapTest : public ::testing::Test{
	protected:
		MaxHeap<int> maxHeap;
		MinHeap<int> minHeap;

		HeapTest() {}
		virtual ~HeapTest(){}

		virtual void SetUp(){
			maxHeap = MaxHeap<int>();
			minHeap = MinHeap<int>();
		}

		virtual void TearDown(){}
};

TEST_F(HeapTest,toVectorTest){
	std::vector<int> lst = {2,4,3,15,10};		
	for (auto elem : lst){
		maxHeap.push(elem);
		minHeap.push(elem);
	}

	std::vector<int> maxHeapList = maxHeap.toVector();
	std::vector<int> minHeapList = minHeap.toVector();

	std::vector<int> expectedMaxHeapList = {15,10,3,2,4};
	std::vector<int> expectedMinHeapList = {2,4,3,15,10};
	
	EXPECT_TRUE(std::equal(expectedMaxHeapList.begin(),expectedMaxHeapList.end(),maxHeapList.begin()) && maxHeapList.size() == expectedMaxHeapList.size())
		<< "Max Heap - Input Order {2,4,3,15,10} - Expected {15,10,3,2,4}";
	EXPECT_TRUE(std::equal(expectedMinHeapList.begin(),expectedMinHeapList.end(),minHeapList.begin()) && minHeapList.size() == expectedMinHeapList.size())
		<< "Min Heap - Input Order {2,4,3,15,10} - Expected {2,4,3,15,10}";

}

TEST_F(HeapTest,heapifyTest){	
	std::vector<int> lst = {2,4,3,15,10};		
	
	bool isDescending = true;
	int prev = INT_MAX;


	for (auto elem : lst){
		maxHeap.push(elem);
		minHeap.push(elem);
	}

	while(!maxHeap.isEmpty() && isDescending){
		isDescending = prev >= maxHeap.top(); 	
		prev = maxHeap.top();
		maxHeap.pop();
	}

	EXPECT_TRUE(isDescending) << "Max Heap : Input {2,4,3,15,10} : Output Should be : 15,10,4,3,2";
	
	bool isAscending = true;
	prev = INT_MIN;

	while(!minHeap.isEmpty() && isAscending){
		isAscending = prev < minHeap.top();
		prev = minHeap.top();
		minHeap.pop();
	}
	
	EXPECT_TRUE(isAscending) << "Min Heap: Input {2,4,3,15,10} : Output Should be : 2,3,4,10,15";
}

TEST_F(HeapTest,minHeapPushPopTopTest){
	minHeap.push(1);
	minHeap.push(2);
	minHeap.pop();
	EXPECT_EQ(minHeap.top(),2) << "MinHeap - Push 1,2, pop(), top = 2";
}

TEST_F(HeapTest,maxHeapPushPopTopTest){
	maxHeap.push(2);
	maxHeap.push(1);
	maxHeap.pop();
	EXPECT_EQ(maxHeap.top(),1) << "MaxHeap - Push 2,1 , pop(), top = 1";
}

TEST_F(HeapTest,sizeTest){
	EXPECT_EQ(minHeap.size(),0) << "Heap of size 0";
	
	minHeap.push(1);
	minHeap.push(2);
	EXPECT_EQ(minHeap.size(),2) << "Push on two elements";

	minHeap.pop();
	minHeap.pop();
	EXPECT_EQ(minHeap.size(),0) << "Pop all elements off";
}

TEST_F(HeapTest,isEmptyTest){
	EXPECT_TRUE(minHeap.isEmpty()) << "IsEmpty() on empty Heap";
	EXPECT_FALSE({minHeap.push(1);minHeap.isEmpty();}) << "push, isEmpty()";
	
	EXPECT_FALSE(
		{
			minHeap.push(1);
			minHeap.pop();
			minHeap.isEmpty();
		}
	) << "push, Pop , Isempty() Check";
		
}



TEST_F(HeapTest,exceptionTest){	
	EXPECT_THROW({maxHeap.pop();},std::out_of_range) << "Pop on an empty heap";
	EXPECT_THROW({maxHeap.top();},std::out_of_range) << "Top on an empty heap";
}


int main(int argc, char * argv[]){
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
