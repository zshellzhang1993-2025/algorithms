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
		unsigned int *radium = new unsigned int[str.length()];
		radium[0] = 0;
		unsigned int currentLength = 0;
		unsigned int offset = 1;
		i = 1;
		while ( i < str.length() ) {
			while ( currentLength + i + 1 < str.length() && i >= currentLength + 1 &&
			        str[currentLength + i + 1] == str[i - ( currentLength + 1 )] )
				currentLength++;
			radium[i] = currentLength;
			while ( offset <= radium[i] ) {
				if ( i - offset - radium[i - offset] != i - radium[i] ) {
					radium[i + offset] = i - offset - radium[i - offset] < i - radium[i]
					                     ? radium[i] - offset : radium[i - offset];
					if ( offset == radium[i] ) {
						currentLength = 0;
						break;
					}
					offset++;
				} else {
					currentLength = radium[i - offset];
					break;
				}
			}
			i = i + offset;
			offset = 1;
		}
		int longestRadiumIndex = 0;
		for ( i = 0; i < str.length(); i++ ) {
			if ( radium[i] > radium[longestRadiumIndex] )
				longestRadiumIndex = i;
		}
		string temp = str.substr ( longestRadiumIndex - radium[longestRadiumIndex],
		                           2 * radium[longestRadiumIndex] + 1 );
		delete[] radium;
		string objectStr = "";
		for ( int i = 0; i < temp.length(); i++ ) {
			if ( temp[i] == '#' )
				continue;
			objectStr.append ( 1, temp[i] );
		}
		return objectStr;
	}
};

int main () {
	string str = "mmdmm";
	Solution5 s;
	cout << s.longestPalindrome ( str );
	return 0;
}
