#include <iostream>
using namespace std;

class Solution8 {
public:
	int atoi ( string str ) {
		bool hasgotValue = false;
		int isNegtive = 1;
		string substr = "";
		int num = 0;
		int result = 0;
		bool hasOperator = false;
		bool canbeZero = false;
		for ( unsigned int i = 0 ; i < str.length(); i++ ) {
			if ( str[i] == ' ' && !hasgotValue && !canbeZero && !hasOperator )
				continue;
			if ( str[i] == '-' && !hasgotValue && !canbeZero ) {
				isNegtive = -1;
				if ( !hasOperator )
					hasOperator = true;
				else
					return 0;
				continue;
			}
			if ( str[i] == '+' && !hasgotValue && !canbeZero ) {
				if ( !hasOperator )
					hasOperator = true;
				else
					return 0;
				continue;
			}
			if ( str[i] >= '0' && str[i] <= '9' ) {
				if ( str[i] == '0' && !hasgotValue ) {
					canbeZero = true;
					continue;
				} else {
					substr.append ( 1, str[i] );
					hasgotValue = true;
					continue;
				}
			}
			break;
		}
		if ( !substr.length() )
			return 0;
		for ( unsigned int i = 0; i < substr.length(); i++ ) {
			num = int ( substr[i] ) - 48;
			if ( result > INT_MAX / 10 ) {
				if ( isNegtive == 1 )
					return INT_MAX;
				else
					return INT_MIN;
			} else if ( result == INT_MAX / 10 ) {
				if ( isNegtive == 1 && num > 7 )
					return INT_MAX;
				else if ( isNegtive == -1 && num > 8 )
					return INT_MIN;
			}
			result = result * 10 + num;
		}
		return isNegtive * result;
	}
};

int main() {
	string str = "  - 123";
	Solution8 s;
	cout << s.atoi ( str );
	return 0;
}
