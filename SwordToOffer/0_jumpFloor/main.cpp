#include <iostream>
using namespace std;

/**
 * @class Solution
 * @author Zhi
 * @date 11/07/2015
 * @file main.cpp
 * @brief a frog can jump 1 or 2 floors once,how many cases will it jump
 * for a stairs with "number" steps?
 */

class Solution_0 {
public:

    /**
     * @brief the traditional method implemented by recursion
     */

    int jumpFloor1 ( int number ) {
        if ( number == 1 )
            return 1;
        else if ( number == 2 )
            return 2;
        else if ( number < 1 )
            return 0;
        else
            return jumpFloor1 ( number - 1 ) + jumpFloor1 ( number - 2 );
    }

    /**
     * @brief this problem is fundumentally the same as the problem of Fibonacci
     */

    int jumpFloor2 ( int number ) {
        if ( number <= 1 )
            return 1;
        int pre, cur, next;
        pre = 0;
        cur = 1;
        for ( int i = 1; i <= number; i++ ) {
            next = pre + cur;
            pre = cur;
            cur = next;
        }
        return cur;
    }

};

int main() {
    Solution_0 s;
    cout << s.jumpFloor1 ( 10 ) << endl << s.jumpFloor2 ( 10 );
    return 0;
}
