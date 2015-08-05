#include <iostream>
#include <vector>
using namespace std;

class Solution_16 {
public:
    bool VerifySquenceOfBST ( vector<int> sequence ) {
        this->sequence = sequence;
        if ( !sequence.size() )
            return false;
        return verifyPart ( 0, sequence.size() - 1 );
    }
private:
    bool verifyPart ( int begin, int end ) {
        if ( begin == end )
            return true;
        int pivot = sequence[end];
        int index = end - 1;
        int division = -1;
        while ( index >= begin ) {
            if ( sequence[index] > pivot )
                index--;
            else {
                division = index;
                break;
            }
        }
        while ( index >= begin ) {
            if ( sequence[index] < pivot )
                index--;
            else
                return false;
        }
        if ( division == -1 || division == end - 1 )
            return verifyPart ( begin, end - 1 );

        else
            return verifyPart ( begin, division ) && verifyPart ( division + 1, end - 1 );
    }
private:
    vector<int> sequence;
};

int main () {
    int array[12] = {2, 1, 4, 3, 7, 11, 6, 9, 12, 10, 8, 5};
    vector<int> sequence ( array, array + 12 );
    Solution_16 s;
    cout << s.VerifySquenceOfBST ( sequence );
    return 0;
}
