#include <iostream>
using namespace std;

class Solution_9 {
public:
    int Fibonacci ( int n ) {
        if ( n < 1 )
            return 0;
        if ( n == 1 || n == 2 )
            return 1;
        int i = 1;
        int j = 1;
        int count = 2;
        while ( count <= n ) {
            i = i + j;
            i = i ^ j;
            j = i ^ j;
            i = i ^ j;
            count++;
        }
        return i;
    }
};

int main () {
    Solution_9 s;
    cout << s.Fibonacci ( 7 );
    return 0;
}
