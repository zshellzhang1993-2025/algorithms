#include <iostream>
#include <vector>
using namespace std;

class Solution_8 {
public:
    int minNumberInRotateArray ( vector<int> rotateArray ) {
        //if the array is empty
        if ( rotateArray.size() == 0 )
            return 0;
        //if the array is rotating
        int i = 0;
        int j = rotateArray.size() - 1;
        int mid = 0;
        while ( rotateArray[i] >= rotateArray[j] ) {
            if ( j - i == 1 )
                return rotateArray[j];
            mid = ( i + j ) / 2;
            if ( rotateArray[mid] == rotateArray[i] && rotateArray[mid] == rotateArray[j] ) {
                return linearMin ( rotateArray, i, j );
            }
            if ( rotateArray[mid] >= rotateArray[i] )
                i = mid;
            else if ( rotateArray[mid] <= rotateArray[j] )
                j = mid;
        }
        return rotateArray[mid];
    }

private:
    int linearMin ( vector<int> rotateArray, int start, int end ) {
        int target = rotateArray[start];
        int i = start + 1;
        while ( i <= end ) {
            if ( target > rotateArray[i] )
                target = rotateArray[i];
            i++;
        }
        return target;
    }
};

int main () {
    int data[6] = {2, 2, 1, 2, 2, 2};
    vector<int> rotateArray ( data, data + 6 );
    Solution_8 s;
    cout << s.minNumberInRotateArray ( rotateArray );
    return 0;
}
