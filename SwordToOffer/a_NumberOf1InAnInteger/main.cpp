#include <iostream>
using namespace std;

class Solution_a {
public:
    int  NumberOf1 ( int n ) {
        int count = 0;
        while ( n ) {
            count++;
            n = ( n - 1 ) &n;
        }
        return count;
    }
};

int main () {
    Solution_a s;
    cout << s.NumberOf1 ( 43 );
    return 0;
}
