#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include <iostream>
#include <vector>
using namespace std;

template <class T> class PriorityQueue {
public:
	PriorityQueue ( T *cost, int n );
	void updateKey ( int heapIndex );
	T Peek();
	void Pop();
	void Push();
	int getHeapIndex ( int index );

private:
	void makeSet();
	void bubbleUp ( int index );
	void sinkDown ( int index );

private:
	vector<int> heap;
	vector<int> Index;
	T *cost;
};

#endif
