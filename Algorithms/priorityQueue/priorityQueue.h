#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include <iostream>
#include <vector>
using namespace std;

template <typename CT, typename T> class PriorityQueue {
public:
	PriorityQueue();
	PriorityQueue ( T *array, int n );

	typedef void ( CT::*pClassFunc1 ) ( T );
	void updateKey ( CT* pClassType, pClassFunc1 decreaseKey, int index );
	void updateKey();

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
	vector<int> Indices;		//solve the performance bottleneck in updateKey(...)
};

#endif	/* _PRIORITY_QUEUE_H */
