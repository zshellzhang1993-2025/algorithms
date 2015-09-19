#include <iostream>
#include <vector>
using namespace std;

class Solution_d {
public:
    vector<int> twoStacksSort ( vector<int> numbers ) {
        vector<int> tmpStack;
        int tmp = 0;
        int count = 0;
        while ( numbers.size() ) {
            tmp = numbers[0];
            numbers.erase ( numbers.begin() );
            if ( tmpStack.size() == 0 )
                tmpStack.push_back ( tmp );
            else {
                while ( tmpStack.size() && tmp > tmpStack[0] ) {
                    numbers.insert ( numbers.begin(), tmpStack[0] );
                    tmpStack.erase ( tmpStack.begin() );
                    count++;
                }
                tmpStack.insert ( tmpStack.begin(), tmp );
                while ( count > 0 ) {
                    tmpStack.insert ( tmpStack.begin(), numbers[0] );
                    numbers.erase ( numbers.begin() );
                    count--;
                }
            }
        }
        while ( tmpStack.size() ) {
            numbers.insert ( numbers.begin(), tmpStack[0] );
            tmpStack.erase ( tmpStack.begin() );
        }
        return numbers;
    }
};

int main () {
    int data[9] = { 678, 6, 8, 12, 345, 25, 689, 999, 123};
    int data2[5] = {1, 2, 3, 4, 5};
    vector<int> numbers ( data2, data2 + 5 );
    Solution_d s;
    vector<int> temp = s.twoStacksSort ( numbers );
    for ( unsigned int i = 0; i < temp.size(); i++ )
        cout << temp[i] << " ";
    return 0;
}
