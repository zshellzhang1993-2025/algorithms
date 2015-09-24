#include <iostream>
using namespace std;

class Solution_33 {
public:
    bool match ( char* str, char* pattern ) {
        if ( !pattern || !str )
            return false;
        int i = 0;
        int j = 0;
        while ( str[i] != '\0' && pattern[j] != '\0' ) {
            if ( pattern[j] == '.' && pattern[j + 1] == '*' ) {
                j = j + 2;
                i--;
                int num1 = 0;
                while ( str[i + num1 + 1] != '\0' )
                    num1++;
                i++;
                for ( int k = 0; k <= num1; k++ ) {
                    if ( match ( str + i + k, pattern + j ) )
                        return true;
                }
                return false;
            } else if ( str[i] == pattern[j] ) {
                if ( pattern[j + 1] != '*' ) {
                    i++;
                    j++;
                } else {
                    char p = pattern[j];
                    j = j + 2;
                    i--;
                    int num1 = 0;
                    while ( str[i + num1 + 1] == p )
                        num1++;
                    i++;
                    for ( int k = 0; k <= num1; k++ ) {
                        if ( match ( str + i + k, pattern + j ) )
                            return true;
                    }
                    return false;
                }
            } else if ( pattern[j + 1] == '*' )
                j += 2;
            else if ( pattern[j] == '.' ) {
                i++;
                j++;
            } else
                return false;
        }
        if ( str[i] != '\0' )
            return false;
        if ( pattern[j] != '\0' ) {
            int tmp = j;
            while ( pattern[tmp] != '\0' )
                tmp++;
            for ( int i = j; i < tmp; i++ ) {
                if ( pattern[i] != '*' && pattern[i + 1] != '*' )
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution_33 s;
    char *pattern = ".*a*a";
    char *str = "bbbba";
    cout << s.match ( str, pattern );
    return 0;
}
