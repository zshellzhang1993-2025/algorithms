#include <iostream>
using namespace std;

/*
 * this question wasn't solved by me,I reference someone else's code,such a hard problem!
 */

class Solution4 {
public:
	double findMedianSortedArrays ( int A[], int m, int B[], int n ) {
		int k = m + n;
		// if the length of two arrays' data is odd
		if ( k & 0x1 )
			return findKth ( A, m, B, n, k / 2 + 1 );
		// else if even we will return the average of the two medial data
		else
			return ( findKth ( A, m, B, n, k / 2 ) + findNext() ) / 2;	//use findNext() to reduce unnecessary computing
	}																	//on the next data with O(log(m+n))

private:
	double findKth ( int A[], int m, int B[], int n, int k ) {
		if ( m > n )
			return findKth ( B, n, A, m, k );
		else if ( m == 0 ) {
			pNextA = NULL;
			pNextB = B + k;
			return B[k - 1];
		} else if ( k == 1 ) {
			if ( A[0] <= B[0] ) {
				if ( m == 1 )
					pNextA = NULL;
				else
					pNextA = A + 1;
				pNextB = B;
				return A[0];
			} else if ( A[0] > B[0] ) {
				if ( n == 1 )
					pNextB = NULL;
				else
					pNextB = B + 1;
				pNextA = A;
				return B[0];
			}
		} else {
			int pa = m > k / 2 ? k / 2 : m;
			int pb = k - pa;
			if ( A[pa - 1] < B[pb - 1] )
				return findKth ( A + pa, m - pa, B, n, k - pa );
			else if ( A[pa - 1] > B[pb - 1] )
				return findKth ( A, m, B + pb, n - pb, k - pb );
			else {
				pNextA = A + pa;
				pNextB = B + pb;
				return A[pa - 1];
			}
		}
	}

	double findNext () {
		if ( !pNextA )
			return *pNextB;
		if ( !pNextB )
			return *pNextA;
		return *pNextA < *pNextB ? *pNextA : *pNextB;
	}

private:
	int *pNextA;
	int *pNextB;
};

int main () {
	int A[5] = { 1, 5, 9, 12, 25 };
	int B[6] = { 2, 4, 7, 19, 25, 31 };
	int C[7] = { 10, 13, 14, 21, 34, 41, 50 };
	Solution4 s;
	cout << s.findMedianSortedArrays ( A, 5, B, 6 ) << endl;
	cout << s.findMedianSortedArrays ( A, 5, C, 7 );
	return 0;
}
