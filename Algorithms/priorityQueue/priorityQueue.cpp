template <class T>
PriorityQueue<T>::PriorityQueue() {}

template <class T>
PriorityQueue<T>::PriorityQueue ( T *data, int n ) {

}

template <class T>
void PriorityQueue<T>::updateKey ( T data, int index ) {		//this is the performance bottleneck of the data structure

}

template <class T>
T PriorityQueue<T>::Peek() {
	return this->heap[0];
}

template <class T>
void PriorityQueue<T>::popMin() {
	T min = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	sinkDown();
}

template <class T>
void PriorityQueue<T>::Insert ( T data ) {
	this->heap.push_back ( data );
	bubbleUp();
}

template <class T>
void PriorityQueue<T>::bubbleUp ( int index ) {

}

template <class T>
void PriorityQueue<T>::sinkDown() {

}
