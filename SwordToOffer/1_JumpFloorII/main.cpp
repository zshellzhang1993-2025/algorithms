#include <iostream>
using namespace std;

/**
 * @class Solution
 * @author Zhi
 * @date 12/07/2015
 * @file main.cpp
 * @brief a frog can jump 1,2...or "number" floors once,how many cases will it jump
 * for a stairs with "number" steps?
 */

class Solution_1 {
public:
    int jumpFloor1 ( int number ) {
        if ( number < 1 )
            return 0;
        else if ( number == 1 )
            return 1;
        else {
            int result = 1;
            for ( int i = 0; i < number - 1; i++ )
                result = result * 2;
            return result;
        }
    }

    int jumpFloor2 ( int number ) {
        if ( number <= 1 ) {
            return 1;
        }
        return jumpFloor2 ( number - 1 ) * 2;

    }
};

int main () {
    Solution_1 s;
    cout << s.jumpFloor1 ( 10 ) << endl << s.jumpFloor2 ( 10 );
    return 0;
}
