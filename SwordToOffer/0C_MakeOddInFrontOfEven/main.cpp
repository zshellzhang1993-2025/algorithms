#include <iostream>
#include <vector>
using namespace std;

class Solution_c {
public:

    /**
     * @brief the method taking no account of the stability
     */

    void reOrderArrayI ( vector<int> &array ) {
        if ( array.empty() )
            return;
        int top = 0;
        int tail = array.size() - 1;
        while ( top < tail ) {
            while ( array[top] % 2 == 1 && top < tail )
                top++;
            while ( array[tail] % 2 == 0 && top < tail )
                tail--;
            array[top] = array[top] ^ array[tail];
            array[tail] = array[top] ^ array[tail];
            array[top] = array[top] ^ array[tail];
        }
    }

    /**
     * @brief the method taking account of the stability
     */

    void reOrderArrayII ( vector<int> &array ) {
        if ( array.empty() )
            return;
        vector<int> arrayOdd;
        vector<int> arrayEven;
        for ( unsigned int i = 0; i < array.size(); i++ ) {
            if ( array[i] % 2 == 1 || array[i] % 2 == -1 )
                arrayOdd.push_back ( array[i] );
            else
                arrayEven.push_back ( array[i] );
        }
        arrayOdd.insert ( arrayOdd.end(), arrayEven.begin(), arrayEven.end() );
        for ( unsigned int i = 0; i < array.size(); i++ )
            array[i] = arrayOdd[i];
    }

};

int main () {
    int a[11] = { -1, 7, 2, 4, 5, 0, 9, 6, 4, 7, 9};
    vector<int> array ( a, a + 11 );
    Solution_c s;
    s.reOrderArrayII ( array );
    for ( unsigned int i = 0; i < array.size(); i++ )
        cout << array[i];
    return 0;
}
