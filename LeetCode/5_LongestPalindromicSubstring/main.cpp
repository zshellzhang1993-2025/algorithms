#include <iostream>
using namespace std;

/*
 * to solve the problem in O(n^2) is easy,but to solve it limited in O(n) is difficult,
 * I reference someone else's code which is called Manacher Algorithm.
 */

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

	string findLongestPalindrome3 ( string s ) {
		int length = s.size();
		for ( int i = 0, k = 1; i < length - 1; i++ ) {
			s.insert ( k, "#" );
			k = k + 2;
		}
		length = length * 2 - 1;
		int *rad = new int[length]();
		rad[0] = 0;
		for ( int i = 1, j = 1, k; i < length; i = i + k ) {
			while ( i - j >= 0 && i + j < length && s.at ( i - j ) == s.at ( i + j ) )
				j++;
			rad[i] = j - 1;
			for ( k = 1; k <= rad[i] && rad[i - k] != rad[i] - k; k++ )
				rad[i + k] = min ( rad[i - k], rad[i] - k );

			j = max ( j - k, 0 );

		}
		int max = 0;
		int center;
		for ( int i = 0; i < length; i++ ) {
			if ( rad[i] > max ) {
				max = rad[i];
				center = i;
			}
		}
		return s.substr ( center - max, 2 * max + 1 );
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
			for ( ; str[i + p[i]] == str[i - p[i]]; p[i]++ ) {}
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
	cout << s.findLongestPalindrome3 ( str );
	return 0;
}
