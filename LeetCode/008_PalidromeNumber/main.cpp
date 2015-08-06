#include <iostream>
using namespace std;

class Solution9 {
public:
	bool isPalindrome ( int x ) {
		int temp = x;
		int palindrome = 0;
		if ( x < 0 )
			return false;
		while ( temp > 0 ) {
			palindrome = palindrome * 10 + temp % 10;
			temp = temp / 10;
		}
		return palindrome == x;
	}
};

int main () {
	Solution9 s;
	cout << s.isPalindrome ( 1231 );
	return 0;
}
