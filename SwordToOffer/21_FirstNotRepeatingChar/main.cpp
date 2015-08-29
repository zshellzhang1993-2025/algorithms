#include <iostream>
using namespace std;

struct Record {
    int count;
    int index;
};

class Solution_21 {
public:
    int FirstNotRepeatingChar ( string str ) {
        if ( str == "" )
            return -1;
        Record table[58];
        for ( int i = 0; i < 58; i++ ) {
            table[i].count = 0;
            table[i].index = -1;
        }
        for ( unsigned int i = 0; i < str.size(); i++ ) {
            if ( table[str[i] - 65].count == 0 ) {
                table[str[i] - 65].count = 1;
                table[str[i] - 65].index = i;
            } else if ( table[str[i] - 65].count == 1 )
                table[str[i] - 65].count = -1;
        }
        int result = 10000;
        for ( int i = 0; i < 58; i++ ) {
            if ( table[i].count == 1 && table[i].index < result )
                result = table[i].index;
        }
        if ( result == 10000 )
            result = -1;
        return result;
    }
};

int main () {
    string str = "aabccdbd";
    Solution_21 s;
    cout << s.FirstNotRepeatingChar ( str );
    return 0;
}
