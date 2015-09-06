#include <iostream>
#include <vector>
using namespace std;

class Solution_28 {
public:
    vector<vector<int> > FindContinuousSequence ( int sum ) {
        vector< vector<int> > result;
        if ( sum < 3 )
            return result;
        vector<int> current_sequence;
        current_sequence.push_back ( 1 );
        current_sequence.push_back ( 2 );
        int begin = 1;
        int end = 2;
        int current_sum = 3;
        while ( begin < ( 1 + sum ) / 2 ) {
            if ( current_sum < sum ) {
                end++;
                current_sequence.push_back ( end );
                current_sum += end;
            } else if ( current_sum > sum ) {
                current_sum -= begin;
                begin++;
                current_sequence.erase ( current_sequence.begin() );
            } else {
                result.push_back ( current_sequence );
                end++;
                current_sum = current_sum + end - begin;
                begin++;
                current_sequence.erase ( current_sequence.begin() );
                current_sequence.push_back ( end );
            }
        }
        return result;
    }
};

int main() {
    Solution_28 s;
    vector< vector<int> > result = s.FindContinuousSequence ( 100 );
    for ( vector< vector<int> >::iterator iter1 = result.begin(); iter1 < result.end(); iter1++ ) {
        for ( vector<int>::iterator iter2 = ( *iter1 ).begin(); iter2 < ( *iter1 ).end(); iter2++ )
            cout << *iter2 << ' ';
        cout << '\n';
    }
    return 0;
}
