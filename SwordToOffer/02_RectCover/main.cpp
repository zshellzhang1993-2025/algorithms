#include <iostream>
using namespace std;

class Solution_02 {
public:
    int rectCover ( int number ) {
        if ( number < 1 )
            return 0;
        if ( number == 1 )
            return 1;
        else if ( number == 2 )
            return 2;
        else
            return rectCover ( number - 1 ) + rectCover ( number - 2 );
    }
};

int main() {
    return 0;
}
