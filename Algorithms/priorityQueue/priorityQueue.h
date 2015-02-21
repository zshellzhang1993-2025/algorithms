#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

template <class T> class PriorityQueue {
public:
	PriorityQueue();
	PriorityQueue ( T *data, int n );
	void decreaseKey ( T data );
	T deleteMin();

private:
	void bubbleUp();
	void sinkDown();

private:
	T *data;
	int n;
}
