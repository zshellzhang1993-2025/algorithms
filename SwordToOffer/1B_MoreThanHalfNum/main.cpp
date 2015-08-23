#include <iostream>
#include <vector>
using namespace std;

class Solution_1b {
public:
    int MoreThanHalfNum_Solution ( vector<int> numbers ) {
        if ( numbers.size() == 0 )
            return 0;
        int count = 1;
        int target = numbers[0];
        for ( vector<int>::iterator iter = numbers.begin() + 1; iter < numbers.end(); iter++ ) {
            if ( *iter == target )
                count++;
            else {
                if ( count > 1 )
                    count--;
                else
                    target = *iter;
            }
        }
        count = 0;
        for ( vector<int>::iterator iter = numbers.begin(); iter < numbers.end(); iter++ ) {
            if ( *iter == target )
                count++;
        }
        if ( count > numbers.size() / 2 )
            return target;
        else
            return 0;
    }
};

int main () {
    Solution_1b s;
    int array[11] = {1, 2, 3, 2, 2, 6, 2, 9, 7, 2, 2};
    vector<int> numbers ( array, array + 7 );
    cout << s.MoreThanHalfNum_Solution ( numbers );
    return 0;
}
