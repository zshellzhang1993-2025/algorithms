#include <iostream>
#include <math.h>
using namespace std;

class Solution_1e {
public:
    int NumberOf1Between1AndN_Solution ( int n ) {
        if ( n < 1 )
            return 0;
        count = 0;
        int number = n;
        int nextnumber = n;
        int pownumber = -1;
        int current = 0;
        while ( nextnumber > 0 ) {
            number = nextnumber;
            nextnumber = number / 10;
            pownumber++;
            current = number % 10;
            if ( current > 1 )
                count += ( nextnumber + 1 ) * pow ( 10, pownumber );
            else if ( current == 1 )
                count += nextnumber * pow ( 10, pownumber ) + n % ( int ) pow ( 10, pownumber ) + 1;
            else
                count += nextnumber * pow ( 10, pownumber );
        }
        return count;
    }

private:
    int count;
};

int main () {
    Solution_1e s;
    cout << s.NumberOf1Between1AndN_Solution ( 1 );
    return 0;
}
