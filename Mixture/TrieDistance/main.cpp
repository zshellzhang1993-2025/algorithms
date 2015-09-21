#include <iostream>
#include <math.h>
using namespace std;

int getAll ( int len ) {
    int max = 0;
    for ( int i = 0; i < len; i++ )
        max = max + ( int ) pow ( 26, i );
    return max;
}

int distance ( string s1, string s2, int len ) {
    int dist = 26 * getAll ( len );
    int left = 0;
    int right = 0;

    int before = 0;
    for ( unsigned int i = 0; i < s1.size(); i++ ) {
        before = ( int ) ( s1[i] - 'a' );
        left += before * getAll ( len - i ) + 1;
    }

    int after = 0;
    for ( unsigned int i = 0; i < s2.size(); i++ ) {
        after = ( int ) ( 'z' - s2[i] );
        right += after * getAll ( len - i );
    }
    right = right + 1;

    return dist - left - right;

}

int main () {
    cout << distance ( "ab", "ce", 2 );
    return 0;
}
