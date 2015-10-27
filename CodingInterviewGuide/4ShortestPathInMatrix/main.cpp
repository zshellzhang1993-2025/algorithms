#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//do not use condition compress and return the path
vector<int> shortestPathInMatrix1 ( int** matrix , int row, int col ) {
    int** dp = new int*[row];
    for ( int i = 0; i < row; i++ )
        dp[i] = new int[col];

    dp[0][0] = matrix[0][0];
    // initialize the dp array
    for ( int i = 1; i < col; i++ )
        dp[0][i] += dp[0][i - 1];
    for ( int i = 1; i < row; i++ )
        dp[i][0] += dp[i - 1][0];
    // run the dynamic programming algorithm
    for ( int i = 1; i < row; i++ )
        for ( int j = 1; j < col; j++ )
            dp[i][j] = matrix[i - 1][j] < matrix[i][j - 1] ?
                       matrix[i - 1][j] + matrix[i][j] : matrix[i][j - 1] + matrix[i][j];

    //find back to the path
    vector<int> v;
    stack<int> s;
    s.push ( matrix[row - 1][col - 1] );
    int i = row - 1;
    int j = col - 1;
    while ( i > 0 && j > 0 ) {
        if ( dp[i][j] == matrix[i][j] + matrix[i - 1][j] ) {
            s.push ( matrix[i - 1][j] );
            i = i - 1;
        } else {
            s.push ( matrix[i][j - 1] );
            j = j - 1;
        }
    }
    s.push ( matrix[0][0] );
    while ( !s.empty() ) {
        v.push_back ( s.top() );
        s.pop();
    }

    for ( int i = 0; i < row; i++ )
        delete dp[i];
    delete[] dp;

    return v;
}

//use condition compress and return the final cost
int shortestPathInMatrix2 ( int** matrix, int row, int col ) {
    int top = 0;
    if ( row < col ) {
        int *dp = new int[row];

        dp[0] = matrix[0][0];
        for ( int i = 1; i < row; i++ )
            dp[i] = dp[i - 1] + matrix[i][0];
        for ( int i = 1; i < col; i++ )
            for ( int j = 0; j < row; j++ ) {
                if ( j == 0 )
                    dp[j] = dp[j] + matrix[0][i];
                else {
                    top = dp[j];
                    dp[j] = top < dp[j - 1] ? top + matrix[i][j] : dp[j - 1] + matrix[i][j];
                }
            }
        int result = dp[row - 1];
        delete dp;
        return result;
    } else {
        int *dp = new int[col];

        dp[0] = matrix[0][0];
        for ( int i = 1; i < col; i++ )
            dp[i] = dp[i - 1] + matrix[0][i];
        for ( int i = 1; i < row; i++ )
            for ( int j = 0; j < col; j++ ) {
                if ( j == 0 )
                    dp[j] = dp[j] + matrix[i][0];
                else {
                    top = dp[j];
                    dp[j] = top < dp[j - 1] ? top + matrix[i][j] : dp[j - 1] + matrix[i][j];
                }
            }
        int result = dp[col - 1];
        delete dp;
        return result;
    }
}

int main () {
    const int size = 4;
    int data[4][4] = {
        1, 3, 5, 9,
        8, 1, 3, 4,
        5, 0, 6, 1,
        8, 8, 4, 0
    };
    int **matrix = new int*[size];
    for ( int i = 0; i < size; i++ )
        matrix[i] = new int[size];
    for ( int i = 0; i < size; i++ )
        for ( int j = 0; j < size; j++ )
            matrix[i][j] = data[i][j];

    vector<int> v = shortestPathInMatrix1 ( matrix, 4, 4 );
    for ( vector<int>::iterator iter = v.begin(); iter != v.end(); iter++ )
        cout << *iter << '\t';
    cout << endl;
    cout << shortestPathInMatrix2 ( matrix, 4, 4 ) << endl;

    for ( int i = 0; i < size; i++ )
        delete matrix[i];
    delete[] matrix;
    return 0;
}
