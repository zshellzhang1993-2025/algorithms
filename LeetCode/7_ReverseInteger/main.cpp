#include <iostream>
using namespace std;

/*
 * this is a great problem to consider two points:
 * 		1.if the last digit of x is 0 then the method should return 0;
 * 		2.if the inputed number x is too large which is over 32-bit integer the the computer will overflow
 * 			and it should return 0;
 * */

class Solution7 {
public:
	int reverse ( int x ) {
		if ( !x % 10 )		//judge if the last digit of x is 0
			return 0;
		int isNegtive = 1;
		if ( x < 0 ) {
			isNegtive = -1;
			x *= -1;
		}
		int result = 0;
		int reminder = 0;
		while ( x > 0 ) {
			reminder = x % 10;
			if ( result <= 214748364 )		//judge if the current value overflow
				result = result * 10 + reminder;
			else
				return 0;
			x = x / 10;
		}
		return isNegtive * result;
	}
};

int main () {
	int x = 1534236469;
	Solution7 s;
	cout << s.reverse ( x );
	return 0;
}
