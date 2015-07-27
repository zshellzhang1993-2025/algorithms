#include <iostream>
#include <math.h>
using namespace std;

class Solution_b {

public:

    double Power ( double base, int exponent ) {
        isvalid = true;
        if ( equal ( base, 0 ) ) {
            if ( exponent < 0 ) {
                isvalid = false;
                return 0;
            }
            if ( exponent == 0 )
                return 1;
            return 0;
        }
        unsigned int absExponent = ( unsigned int ) exponent;
        double result = 0;
        if ( exponent < 0 ) {
            absExponent = ( unsigned int ) ( -exponent );
            result = powerWithUnsignedExponent ( base, absExponent );
            result = 1.0 / result;
        } else
            result = powerWithUnsignedExponent ( base, absExponent );
        return result;
    }

    bool getValid() {
        return isvalid;
    }

private:

    bool equal ( double a, double b ) {
        if ( fabs ( a - b ) < 1e-6 )
            return true;
        else
            return false;
    }

    double powerWithUnsignedExponent ( double base, unsigned int exponent ) {
        if ( exponent == 0 )
            return 1;
        if ( exponent == 1 )
            return base;
        double result = powerWithUnsignedExponent ( base, exponent >> 1 );
        result *= result;
        if ( exponent & 0x1 == 1 )
            result *= base;
        return result;
    }

private:

    bool isvalid;

};

int main () {
    return 0;
}
