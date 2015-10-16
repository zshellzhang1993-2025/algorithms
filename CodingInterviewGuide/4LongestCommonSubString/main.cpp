#include <iostream>
using namespace std;

string longestCommonSubString ( string a, string b ) {
    int max = 0;
    int tmp = 0;
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int maxX = 0;
    for ( unsigned int i = 0; i < a.size(); i++ ) {
        tmp = 0;
        y = 0;
        x = i;
        while ( x < a.size() && y < b.size() ) {
            if ( a[x] == b[y] ) {
                if ( ++tmp > max ) {
                    max = tmp;
                    maxX = x;
                }
            } else
                tmp = 0;
            x++;
            y++;
        }
    }
    for ( unsigned int i = 1; i < b.size(); i++ ) {
        tmp = 0;
        x = 0;
        y = i;
        while ( x < a.size() && y < b.size() ) {
            if ( a[x] == b[y] ) {
                if ( ++tmp > max ) {
                    max = tmp;
                    maxX = x;
                }
            } else
                tmp = 0;
            x++;
            y++;
        }
    }
    if ( max > 0 )
        return a.substr ( maxX - max + 1, max );
    else
        return "";
}

int main () {
    cout << longestCommonSubString ( "abcbaim", "cdcccbaia" ) << endl;
    return 0;
}
