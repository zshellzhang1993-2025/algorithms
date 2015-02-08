#include <iostream>
using namespace std;

template <class T> class FindKth {
  public:
    FindKth () {
	data = NULL;
    }

    FindKth ( T data[], int n ) {
	this->n = n;
	this->data = new T[n];
	for ( int i = 0; i < n; i++ )
	    this->data[i] = data[i];
    }

    ~FindKth () {
	if ( data != NULL )
	    delete[] data;
    }

    T findKth ( int k ) {
	return findKth ( k - 1, 0, n - 1 );
    }

    T findMedian () {
	if ( n && 0x1 )
	    return findKth ( n / 2, 0, n - 1 );
	else
	    return ( findKth ( n / 2 - 1, 0, n - 1 ) + findKth ( n / 2, 0, n - 1 ) ) / 2;
    }

  private:
    T findKth ( int k, int begin, int end ) {
	int pivot = Partition ( begin, end );
	if ( pivot > k )
	    return findKth ( k, begin, pivot - 1 );
	if ( pivot == k )
	    return data[pivot];
	else
	    return findKth ( k, pivot + 1, end );
    }

    int Partition ( int begin, int end ) {
	int i = begin;
	int j = end;
	int pivot = data[begin];
	while ( i < j ) {
	    while ( i < j && pivot < data[j] ) {
		j--;
	    }
	    if ( i < j ) {
		data[i] = data[j];
		i++;
	    }
	    while ( i < j && pivot > data[i] ) {
		i++;
	    }
	    if ( i < j ) {
		data[j] = data[i];
		j--;
	    }
	}
	data[i] = pivot;
	return i;
    }

  private:
    T *data;
    int n;
};

int main () {
    int data[10] = { 7, 6, 7, 8, 1, 2, 3, 4, 8, 5 };
    FindKth<int> s1 ( data, 10 );
    cout << s1.findKth ( 4 ) << '\t' << s1.findMedian () << endl;
    double data2[10] = { 6.8, 1.9, 3.0, 6.0, 9.9, 12.1, 10.5, 19.3, 15.6 };
    FindKth<double> s2 ( data2, 9 );
    cout << s2.findKth ( 3 ) << '\t' << s2.findMedian () << endl;
    return 0;
}