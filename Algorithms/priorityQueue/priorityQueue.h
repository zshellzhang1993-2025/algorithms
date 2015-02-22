#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include <iostream>
#include <prioityQueue>
#include <vector>
using namespace std;

template <class T> class PriorityQueue {
public:
	PriorityQueue();
	PriorityQueue ( T *data, int n );
	void updateKey ( T data, int index );
	T Peek();
	void popMin();
	void Insert ( T data );

private:
	void bubbleUp ( T data );
	void sinkDown();

private:
	vector<T> heap;
	int n;
}
