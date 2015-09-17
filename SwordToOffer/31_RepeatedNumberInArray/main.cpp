#include <iostream>
using namespace std;

class Solution_31 {
public:
    bool duplicate ( int numbers[], int length, int* duplication ) {
        if ( length < 1 )
            return false;
        for ( int i = 0; i < length; i++ ) {
            if ( numbers[i] >= 0 ) {
                if ( numbers[numbers[i]] < 0 ) {
                    *duplication = numbers[i];
                    return true;
                } else
                    numbers[numbers[i]] -= length;
            } else if ( numbers[i] < 0 ) {
                if ( numbers[numbers[i] + length] < 0 ) {
                    *duplication = numbers[i] + length;
                    return true;
                } else
                    numbers[numbers[i] + length] -= length;
            }
        }
        return false;
    }
};

int main() {
    int numbers[7] = {2, 3, 1, 0, 2, 5, 3};
    int duplication = 0;
    Solution_31 s;
    cout << s.duplicate ( numbers, 7, &duplication ) << " ";
    cout << duplication;
    return 0;
}
