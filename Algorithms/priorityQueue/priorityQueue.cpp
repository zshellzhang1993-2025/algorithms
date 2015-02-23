#include <priorityQueue.h>

template <class T>
PriorityQueue<T>::PriorityQueue ( T *cost, int n ) {
	this->cost = cost;
	for ( int i = 0; i < n; i++ ) {
		this->heap.push_back ( i );
		this->Index.push_back ( i );
	}
	makeSet();
}

//this will be the performance bottleneck if I do not change the data structure
template <class T>
void PriorityQueue<T>::updateKey ( int heapIndex ) {
	bubbleUp ( heapIndex );
}

template <class T>
T PriorityQueue<T>::Peek() {
	return this->heap[0];
}

template <class T>
void PriorityQueue<T>::Pop() {
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	sinkDown ( 0 );
}

template <class T>
void PriorityQueue<T>::Push () {
	int data = heap.size();
	heap.push_back ( data );
	Index.push_back ( data );
	bubbleUp ( data );
}

template<class T>
void PriorityQueue<T>::makeSet() {
	for ( int i = ( heap.size() - 1 ) / 2; i >= 0; i-- )
		sinkDown ( i );
}

template <class T>
void PriorityQueue<T>::bubbleUp ( int index ) {
	int parent = 0;
	int temp = 0;
	while ( index > 0 ) {
		parent = ( index - 1 ) / 2;
		if ( cost[heap[index]] < cost[heap[parent]] ) {
			temp = heap[index];
			heap[index] = heap[parent];
			heap[parent] = temp;
			temp = Index[index];
			Index[index] = Index[parent];
			Index[parent] = temp;
		} else
			break;
	}
}

template <class T>
void PriorityQueue<T>::sinkDown ( int index ) {
	int lchild = 0;
	int rchild = 0;
	int objectChild = 0;
	int temp = 0;
	while ( index * 2 + 1 < heap.size() ) {
		lchild = index * 2 + 1;
		rchild = lchild + 1;
		if ( rchild < heap.size() ) {
			if ( cost[heap[lchild]] < cost[heap[rchild]] )
				objectChild = lchild;
			else
				objectChild = rchild;
		} else
			objectChild = lchild;
		temp = heap[objectChild];
		heap[objectChild] = heap[index];
		heap[index] = temp;
		temp = Index[objectChild];
		Index[objectChild] = Index[index];
		Index[index] = temp;

		index = objectChild;
	}
}
