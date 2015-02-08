#include <iostream>
using namespace std;

/*
 * this question wasn't solved by me,I reference someone else's code,such a hard problem!
 */

class Solution {
  public:
    double findMedianSortedArrays ( int A[], int m, int B[], int n ) {
	int k = m + n;
	if ( k & 0x1 ) // if the number of two arrays' data is odd
	    return findKth ( A, m, B, n, k / 2 + 1 );
	else // else if even we will return the average of the medial two data
	    return ( findKth ( A, m, B, n, k / 2 ) + findKth ( A, m, B, n, k / 2 + 1 ) ) / 2;
    }

  private:
    double findKth ( int A[], int m, int B[], int n, int k ) {
		if ( m > n )
			return findKth ( B, n, A, m, k );
		else if ( m == 0 )
			return B[k - 1];
		else if ( k == 1 )
			return A[0] < B[0] ? A[0] : B[0];
		else {
			int pa = m > k / 2 ? k / 2 : m;
			int pb = k - pa;
			if ( A[pa - 1] < B[pb - 1] )
				return findKth ( A + pa, m - pa, B, n, k - pa );
			else if ( A[pa - 1] > B[pb - 1] )
				return findKth ( A, m, B + pb, n - pb, k - pb );
			else
				return A[pa - 1];
		}
    }
};

int main () {
    int A[5] = { 1, 5, 9, 12, 25 };
    int B[6] = { 2, 4, 7, 19, 25, 31 };
    int C[7] = { 10, 13, 14, 21, 34, 41, 50 };
    Solution s;
    cout << s.findMedianSortedArrays ( A, 5, B, 6 ) << endl;
    cout << s.findMedianSortedArrays ( A, 5, C, 7 );
    return 0;
}