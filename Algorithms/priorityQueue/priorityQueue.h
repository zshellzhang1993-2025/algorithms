#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T> class PriorityQueue {
public:
	PriorityQueue();
	PriorityQueue ( T *array, int n );
	bool updateKey ( int index, T newData );
	T Peek();
	bool Pop();
	void Push ( T data );
	bool isEmpty();

private:
	void makeSet();
	void bubbleUp ( int index );
	void sinkDown ( int index );
	int getHeapIndex ( int index );

private:
	vector<T> heap;
	vector<int> heapIndices;		//solve the performance bottleneck in updateKey(...)
	vector<int> entityIndices;		//cooperate with the heapIndices to get an O(1) location
};

#endif	/* _PRIORITY_QUEUE_H */
