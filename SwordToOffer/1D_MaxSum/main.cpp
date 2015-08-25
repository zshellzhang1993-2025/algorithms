#include <iostream>
#include <vector>
using namespace std;

class Solution_1d {
public:
    int FindGreatestSumOfSubArray ( vector<int> array ) {
        if ( array.empty() )
            return 0;
        vector<int>::iterator iter = array.begin();
        int current = *iter;
        while ( *iter < 1 && iter < array.end() ) {
            if ( current < *iter )
                current = *iter;
            iter++;
        }
        if ( iter == array.end() )
            return current;
        int maxsum = *iter;
        for ( iter++; iter < array.end(); iter++ ) {
            if ( *iter < 1 )
                current += *iter;
            else {
                if ( current < 1 )
                    current = *iter;
                else
                    current = *iter + current;
                if ( current > maxsum )
                    maxsum = current;
            }
        }
        return maxsum;
    }
};

int main () {
    const int size = 5;
    int data[size] = { -2, -8, -1, -5, -9};
    vector<int> array ( data, data + size );
    Solution_1d s;
    cout << s.FindGreatestSumOfSubArray ( array );
    return 0;
}
