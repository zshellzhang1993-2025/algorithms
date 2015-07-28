#include <iostream>
#include <vector>
using namespace std;

class Solution_12 {
public:
    vector<int> printMatrix ( vector<vector<int> > matrix ) {
        int x1 = 0;
        int y1 = 0;
        int x2 = matrix.size() - 1;
        int y2 = matrix[0].size() - 1;
        vector<int> result;
        while ( x1 < x2 && y1 < y2 ) {
            for ( int i = y1; i < y2; i++ )
                result.push_back ( matrix[x1][i] );
            for ( int i = x1; i < x2; i++ )
                result.push_back ( matrix[i][y2] );
            for ( int i = y2; i > y1; i-- )
                result.push_back ( matrix[x2][i] );
            for ( int i = x2; i > x1; i-- )
                result.push_back ( matrix[i][y1] );
            x1++;
            y1++;
            x2--;
            y2--;
        }
        if ( x1 < x2 && y1 == y2 ) {
            for ( int i = x1; i <= x2; i++ )
                result.push_back ( matrix[i][y1] );
        }
        if ( y1 < y2 && x1 == x2 ) {
            for ( int i = y1; i <= y2; i++ )
                result.push_back ( matrix[x1][i] );
        }
        if ( x1 == x2 && y1 == y2 )
            result.push_back ( matrix[x1][y1] );
        return result;
    }
};

int main () {
    int array[5][2] = {
        1,  2,
        3, 4,
        5, 6,
        7, 8,
        9, 10
    };
    vector< vector<int> > matrix;
    for ( int i = 0; i < 5; i++ ) {
        vector<int> tmp ( array[i], array[i] + 2 );
        matrix.push_back ( tmp );
    }
    Solution_12 s;
    vector<int> v = s.printMatrix ( matrix );
    for ( vector<int>::iterator iter = v.begin(); iter < v.end(); iter++ )
        cout << *iter << " ";
    return 0;
}
