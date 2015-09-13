#include <iostream>
using namespace std;

class Solution_2e {
public:
    int Sum_Solution ( int n ) {
        if ( n < 1 )
            return 0;
        return getSum ( n );
    }

private:
    int getSum ( int n ) {
        int sum = n;
        n && ( sum += getSum ( n - 1 ) );
        return sum;
    }
};

int main() {
    Solution_2e s;
    cout << s.Sum_Solution ( 10 );
    return 0;
}
