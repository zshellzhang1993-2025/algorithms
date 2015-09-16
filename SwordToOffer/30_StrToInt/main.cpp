#include <iostream>
using namespace std;

class Solution_30 {
public:
    int StrToInt ( string str ) {
        bool isValid = true;
        bool isNegative = false;
        int result = 0;
        for ( unsigned int i = 0; i < str.size(); i++ ) {
            if ( str[i] < '0' || str[i] > '9' ) {
                if ( str[i] == '-' )
                    isNegative = true;
                else {
                    isValid = false;
                    return -1;
                }
            } else
                result = result * 10 + ( int ) ( str[i] - '0' );
        }
        if ( isNegative )
            return -1 * result;
        else
            return result;
    }
};

int main() {
    return 0;
}
