#include <iostream>
#include <vector>
using namespace std;

class Solution_24 {
public:
    int GetNumberOfK ( vector<int> data , int k ) {
        if ( data.empty() )
            return 0;
        int left = 0;
        int right = 0;
        int begin = 0;
        int end = data.size() - 1;
        while ( begin <= end ) {
            left = ( begin + end ) / 2;
            if ( data[left] < k )
                begin = left + 1;
            else
                end = left - 1;
        }
        while ( data[left] < k )
            left++;
        begin = 0;
        end = data.size() - 1;
        while ( begin <= end ) {
            right = ( begin + end ) / 2;
            if ( data[right] > k )
                end = end - 1;
            else
                begin = begin + 1;
        }
        if ( data[right] > k )
            right--;
        while ( data[right] == k && data[right + 1] == k )
            right++;
        if ( right < left )
            return 0;
        return right - left + 1;
    }
};

int main() {
    Solution_24 s;
    const int size = 12;
    int array[size] = {1, 2, 2, 2, 4, 4, 4, 4, 5, 5, 6, 9};
    vector<int> data ( array, array + size );
    cout << s.GetNumberOfK ( data, 10 );
    return 0;
}
