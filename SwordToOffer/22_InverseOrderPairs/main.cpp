#include <iostream>
#include <vector>
using namespace std;

class Solution_22 {
public:
    int InversePairs ( vector<int> data ) {
        if ( data.empty() )
            return 0;
        count = 0;
        this->data = data;
        inverseCount ( 0, data.size() - 1 );
        return count;
    }

private:
    void inverseCount ( int begin, int end ) {
        if ( begin < end ) {
            int pivot = ( begin + end ) / 2;
            inverseCount ( begin, pivot );
            inverseCount ( pivot + 1, end );
            merge ( begin, pivot, pivot + 1, end );
        }
    }

    void merge ( int begin1, int end1, int begin2, int end2 ) {
        int i1 = begin1;
        int j1 = end1;
        int i2 = begin2;
        int j2 = end2;
        int current = 0;
        int inverse = 0;
        int *tmp = new int[end2 - begin1 + 1];
        while ( i1 <= j1 && i2 <= j2 ) {
            if ( data[i1] <= data[i2] ) {
                tmp[current++] = data[i1++];
                count += inverse;
            } else {
                tmp[current++] = data[i2++];
                inverse++;
            }
        }
        while ( i1 <= j1 ) {
            count += inverse;
            tmp[current++] = data[i1++];
        }
        while ( i2 <= j2 )
            tmp[current++] = data[i2++];
        for ( int i = begin1, j = 0; i <= end2; i++, j++ )
            data[i] = tmp[j];
        delete tmp;
    }

private:
    vector<int> data;
    int count;
};

int main() {
    int array[9] = {3, 2, 1, 4, 5, 1, 7, 5, 4};
    Solution_22 s;
    vector<int> data ( array, array + 9 );
    cout << s.InversePairs ( data );
    return 0;
}
