#include <iostream>
#include <vector>
using namespace std;

class Solution_2c {
public:
    bool IsContinuous ( vector<int> numbers ) {
        if ( numbers.empty() )
            return false;
        int table[14];
        for ( int i = 0; i < 14; i++ )
            table[i] = 0;
        for ( vector<int>::iterator iter = numbers.begin(); iter < numbers.end(); iter++ )
            table[*iter]++;
        int random = table[0];
        int count = 0;
        int index = 1;
        int begin = 1;
        int end = 1;
        while ( index < 14 && table[index] == 0 ) {
            begin++;
            index++;
        }
        end = begin - 1;
        for ( ; index < 14; index++ ) {
            if ( table[index] > 0 ) {
                if ( table[index] > 1 )
                    return false;
                count++;
                end = index;
            }
        }
        if ( end - begin - count + 1 > random )
            return false;
        else
            return true;
    }
};

int main() {
    Solution_2c s;
    int data[7] = {1, 3, 0, 4, 6, 7, 8};
    vector<int> numbers ( data, data + 7 );
    cout << s.IsContinuous ( numbers );
    return 0;
}
