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

class Solution {
public:

    /**
     * @brief the traditional method implemented by recursion
     */

    int jumpFloor ( int number ) {
        if ( number == 1 )
            return 1;
        else if ( number == 2 )
            return 2;
        else if ( number < 1 )
            return 0;
        else
            return jumpFloor ( number - 1 ) + jumpFloor ( number - 2 );
    }

    /**
     * @brief the problem is fundumentally the problem of Fibonacci
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
    return 0;
}
