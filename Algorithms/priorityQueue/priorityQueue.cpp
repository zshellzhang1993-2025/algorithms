#include <priorityQueue.h>

template <typename T>
PriorityQueue<T>::PriorityQueue ( T *array, int n ) {
	for ( int i = 0; i < n; i++ ) {
		this->heap.push_back ( array[i] );
		this->heapIndices.push_back ( i );
		this->entityIndices.push_back ( i );
	}
	makeSet();
}

/*the two following methods will be the performance bottleneck if I do not change the data structure*/
template <typename T>
bool PriorityQueue<T>::updateKey ( int index, T newData ) {
	int heapIndex = getHeapIndex ( index );
	if ( heapIndex < 0 )
		return false;
	heap[heapIndex] = newData;
	bubbleUp ( heapIndex );
	return true;
}

template <typename T>
T PriorityQueue<T>::Peek() {
	if ( heap.size() < 1 )
		throw "Empty Queue";
	return this->heap[0];
}

template <typename T>
bool PriorityQueue<T>::Pop() {
	if ( heap.size() < 1 )
		return false;
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	entityIndices[heapIndices[0]] = -1;
	entityIndices[heapIndices[heapIndices.size() - 1]] = 0;
	heapIndices[0] = heapIndices[heapIndices.size() - 1];
	heapIndices.pop_back();
	sinkDown ( 0 );
	return true;
}

template <typename T>
void PriorityQueue<T>::Push ( T data ) {
	int index = heap.size();
	heap.push_back ( data );
	entityIndices.push_back ( index );
	heapIndices.push_back ( index );
	bubbleUp ( index );
}

template <typename T>
void PriorityQueue<T>::makeSet() {
	for ( int i = ( heap.size() - 1 ) / 2; i >= 0; i-- )
		sinkDown ( i );
}

template <typename T>
void PriorityQueue<T>::bubbleUp ( int index ) {
	int parent = 0;
	T temp;
	int indexTemp = 0;
	while ( index > 0 ) {
		parent = ( index - 1 ) / 2;
		if ( heap[index] < heap[parent] ) {

			temp = heap[index];
			heap[index] = heap[parent];
			heap[parent] = temp;

			indexTemp = entityIndices[heapIndices[index]];
			entityIndices[heapIndices[index]] = entityIndices[heapIndices[parent]];
			entityIndices[heapIndices[parent]] = indexTemp;

			temp = heapIndices[index];
			heapIndices[index] = heapIndices[parent];
			heapIndices[parent] = temp;

		} else
			break;
		index = parent;
	}
}

template <typename T>
void PriorityQueue<T>::sinkDown ( int index ) {
	int objectChild = 0;
	T temp;
	int indexTemp = 0;
	while ( ( objectChild = index * 2 + 1 ) < heap.size() ) {
		if ( objectChild + 1 < heap.size() && heap[objectChild + 1] < heap[objectChild] )
			++objectChild;
		if ( heap[objectChild] < heap[index] ) {

			temp = heap[objectChild];
			heap[objectChild] = heap[index];
			heap[index] = temp;

			indexTemp = entityIndices[heapIndices[index]];
			entityIndices[heapIndices[index]] = entityIndices[heapIndices[objectChild]];
			entityIndices[heapIndices[objectChild]] = indexTemp;

			temp = heapIndices[index];
			heapIndices[index] = heapIndices[objectChild];
			heapIndices[objectChild] = temp;

		}
		index = objectChild;
	}
}

template <typename T>
bool PriorityQueue<T>::isEmpty() {
	return this->heap.empty();
}

template <typename T>
int PriorityQueue<T>::getHeapIndex ( int index ) {
	return this->entityIndices[index];
}
