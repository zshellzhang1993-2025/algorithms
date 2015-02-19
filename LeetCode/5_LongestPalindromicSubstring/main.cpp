#include <iostream>
using namespace std;

class Solution5 {
public:
	string longestPalindrome ( string s ) {
		unsigned int i = 0;
		string str = "#";
		while ( i < s.length() ) {
			str.append ( 1, s[i] );
			str.append ( 1, '#' );
			i++;
		}
		this->p = new int[str.length()];
		getLength ( str );
		int longest = 0;
		for ( i = 0; i < str.length(); i++ ) {
			if ( p[i] > p[longest] )
				longest = i;
		}
		longest = ( longest - 1 ) / 2;
		int length = ( p[longest] - 2 ) / 2;
		string result = s.substr ( longest - length, p[longest] - 1 );
		delete[] p;
		return result;
	}

private:
	void getLength ( string str ) {
		int i;
		int mx = 0;
		int id;
		for ( i = 0; i < str.length(); i++ ) {
			if ( mx > i )
				p[i] = p[2 * id - i] < mx - i ? p[2 * id - i] : mx - i;
			else
				p[i] = 1;
			for ( ; str[i + p[i]] == str[i - p[i]]; p[i]++ )
				;
			if ( p[i] + i > mx ) {
				mx = p[i] + i;
				id = i;
			}
		}
	}

private:
	int *p;
};

int main () {
	string str = "madam";
	Solution5 s;
	cout << s.longestPalindrome ( str );
	return 0;
}
