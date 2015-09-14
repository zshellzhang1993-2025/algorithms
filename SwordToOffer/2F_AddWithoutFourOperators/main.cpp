#include <iostream>
using namespace std;

class Solution_2f {
public:
    int Add ( int num1, int num2 ) {
        int sum = num1;
        int carry = 0;
        while ( num2 != 0 ) {
            sum = num1 ^ num2;
            carry = ( num1 & num2 ) << 1;
            num1 = sum;
            num2 = carry;
        }
        return sum;
    }
};

int main() {
    Solution_2f s;
    cout << s.Add ( 13, 56 );
    return 0;
}
