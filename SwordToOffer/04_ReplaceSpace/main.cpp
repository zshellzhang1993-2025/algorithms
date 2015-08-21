#include <iostream>
#include <vector>
using namespace std;

class Solution_04 {
public:
    string replaceSpace ( string str ) {
        int i = str.size() - 1;
        while ( i >= 0 ) {
            if ( str[i] == ' ' )
                str.replace ( i, 1, "%20" );
            i--;
        }
        return str;
    }
};

int main() {
    return 0;
}
