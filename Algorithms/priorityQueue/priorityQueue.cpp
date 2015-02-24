#include <priorityQueue.h>

template <typename CT, typename T>
PriorityQueue<CT, T>::PriorityQueue ( T *array, int n ) {
	for ( int i = 0; i < n; i++ ) {
		this->heap.push_back ( array[i] );
		this->Indices.push_back ( i );
	}
	makeSet();
}

//this will be the performance bottleneck if I do not change the data structure
template <typename CT, typename T>
void PriorityQueue<CT, T>::updateKey ( CT* pClassType, pClassFunc1 decreaseKey, int index ) {
	int heapIndex = getHeapIndex ( index );
	pClassType->decreaseKey ( heap[heapIndex] );
	bubbleUp ( heapIndex );
}

template <typename CT, typename T>
T PriorityQueue<CT, T>::Peek() {
	if ( heap.size() < 1 )
		return NULL;
	return this->heap[0];
}

template <typename CT, typename T>
bool PriorityQueue<CT, T>::Pop() {
	if ( heap.size() < 1 )
		return false;
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	sinkDown ( 0 );
	return true;
}

template <typename CT, typename T>
void PriorityQueue<CT, T>::Push ( T data ) {
	int index = heap.size();
	heap.push_back ( data );
	Indices.push_back ( index );
	bubbleUp ( index );
}

template <typename CT, typename T>
void PriorityQueue<CT, T>::makeSet() {
	for ( int i = ( heap.size() - 1 ) / 2; i >= 0; i-- )
		sinkDown ( i );
}

template <typename CT, typename T>
void PriorityQueue<CT, T>::bubbleUp ( int index ) {
	int parent = 0;
	T temp;
	while ( index > 0 ) {
		parent = ( index - 1 ) / 2;
		if ( heap[index] < heap[parent] ) {

			temp = heap[index];
			heap[index] = heap[parent];
			heap[parent] = temp;

			temp = Indices[index];
			Indices[index] = Indices[parent];
			Indices[parent] = temp;

		} else
			break;
		index = parent;
	}
}

template <typename CT, typename T>
void PriorityQueue<CT, T>::sinkDown ( int index ) {
	int objectChild = 0;
	T temp;
	while ( ( objectChild = index * 2 + 1 ) < heap.size() ) {
		if ( objectChild + 1 < heap.size() && heap[objectChild + 1] < heap[objectChild] )
			++objectChild;
		if ( heap[objectChild] < heap[index] ) {

			temp = heap[objectChild];
			heap[objectChild] = heap[index];
			heap[index] = temp;

			temp = Indices[objectChild];
			Indices[objectChild] = Indices[index];
			Indices[index] = temp;

		}
		index = objectChild;
	}
}

template <typename CT, typename T>
bool PriorityQueue<CT, T>::isEmpty() {
	return this->heap.empty();
}

template <typename CT, typename T>
int PriorityQueue<CT, T>::getHeapIndex ( int index ) {
	return this->Indices[index];
}
