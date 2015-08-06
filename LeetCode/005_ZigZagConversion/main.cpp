#include <iostream>
using namespace std;

class Solution6 {
public:
	string convert ( string s, int nRows ) {
		string *str = new string[nRows];
		unsigned int CYCLE;
		if ( nRows != 1 )
			CYCLE = ( nRows - 1 ) * 2;
		else
			CYCLE = 1;
		unsigned int current = 0;
		for ( unsigned int i = 0; i < s.length(); i++ ) {
			if ( current == CYCLE )
				current = 0;
			if ( current < nRows )
				str[current].append ( 1, s[i] );
			else
				str[nRows - 1 - current % ( nRows - 1 )].append ( 1, s[i] );
			current++;
		}
		string result = "";
		for ( int i = 0; i < nRows; i++ )
			result += str[i];
		delete[] str;
		return result;
	}
};

int main () {
	Solution6 s;
	string str = s.convert ( "PAYPALISHIRING", 3 );
	cout << str;
	return 0;
}
