#include <iostream>
#include <vector>
using namespace std;

class Solution_27 {
public:
    void FindNumsAppearOnce ( vector<int> data, int* num1, int *num2 ) {
        if ( data.size() < 2 ) {
            *num1 = 0;
            *num2 = 0;
            return;
        }
        *num1 = 0;
        *num2 = 0;
        int tmp = 0;
        for ( unsigned int i = 0; i < data.size(); i++ )
            tmp ^= data[i];
        int judge = 1;
        while ( ( tmp & judge ) == 0 )
            judge = judge << 1;
        for ( unsigned int i = 0; i < data.size(); i++ ) {
            if ( ( data[i] & judge ) == 0 )
                *num1 = *num1 ^ data[i];
            else
                *num2 = *num2 ^ data[i];
        }
    }
};

int main() {
    int array[8] = {2, 4, 3, 6, 4, 2, 5, 5};
    vector<int> data ( array, array + 8 );
    Solution_27 s;
    int num1 = 0;
    int num2 = 0;
    s.FindNumsAppearOnce ( data, &num1, &num2 );
    cout << num1 << " " << num2;
    return 0;
}
