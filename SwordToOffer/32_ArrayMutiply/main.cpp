#include <iostream>
#include <vector>
using namespace std;

class Solution_32 {
public:
    vector<int> multiply ( const vector<int>& A ) {
        vector<int> B;
        if ( A.empty() )
            return B;
        if ( A.size() == 1 ) {
            B.push_back ( 1 );
            return B;
        }

        int **record = new int*[2];
        for ( int i = 0; i < 2; i++ )
            record[i] = new int[A.size()];

        record[0][0] = 1;
        for ( unsigned int i = 1; i < A.size(); i++ )
            record[0][i] = record[0][i - 1] * A[i - 1];

        record[1][A.size() - 1] = 1;
        for ( int i = A.size() - 2; i >= 0; i-- )
            record[1][i] = record[1][i + 1] * A[i + 1];

        for ( unsigned int i = 0; i < A.size(); i++ )
            B.push_back ( record[0][i]*record[1][i] );

        for ( int i = 0; i < 2; i++ )
            delete[] record[i];
        delete[] record;

        return B;
    }
};

int main() {
    Solution_32 s;
    const int size = 2;
    int array[size] = {3, 6};
    vector<int> A ( array, array + size );
    vector<int> B = s.multiply ( A );
    for ( vector<int>::iterator iter = B.begin(); iter < B.end(); iter++ )
        cout << *iter << " ";
    return 0;
}
