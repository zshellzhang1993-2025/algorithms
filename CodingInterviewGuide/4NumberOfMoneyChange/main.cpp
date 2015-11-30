#include <iostream>
using namespace std;

//force recursion
int numberOfMoneyChange1 ( int array[], int n, int index, int aim ) {
    if ( index == n )
        return aim == 0 ? 1 : 0;
    else {
        int result = 0;
        for ( int i = 0; aim - i * array[index] >= 0; i++ )
            result += numberOfMoneyChange1 ( array, n, index + 1, aim - i * array[index] );
        return result;
    }
}

//process of recursion
int process ( int array[], int n, int index, int aim, int** mem ) {
    if ( index == n )
        return aim == 0 ? 1 : 0;
    else {
        int result = 0;
        for ( int i = 0; aim - i * array[index] >= 0; i++ ) {
            if ( * ( * ( mem + index + 1 ) + aim - i * array[index] ) != -1 )
                result += * ( * ( mem + index + 1 ) + aim - i * array[index] );
            else
                result += process ( array, n, index + 1, aim - i * array[index], mem );
        }
        * ( * ( mem + index ) + aim ) = result;
        return result;
    }
}

//recursion search with memory
int numberOfMoneyChange2 ( int array[], int n, int aim ) {
    int **mem = new int*[n + 1];
    for ( int i = 0; i < n + 1; i++ )
        mem[i] = new int[aim + 1];

    //initialize memory array
    for ( int i = 0; i < n + 1; i++ )
        for ( int j = 0; j < aim + 1; j++ )
            mem[i][j] = -1;

    int result = process ( array, n, 0, aim, mem );

    for ( int i = 0; i < n + 1; i++ )
        delete mem[i];
    delete mem;

    return result;
}

//dynamic programming
int numberOfMoneyChange3 ( int array[], int n, int aim ) {
    int *dp = new int[aim + 1];
    dp[0] = 1;
    for ( int i = 1; i < aim + 1; i++ ) {
        if ( i % array[0] == 0 )
            dp[i] = 1;
        else
            dp[i] = 0;
    }

    for ( int i = 1; i < n; i++ )
        for ( int j = 0; j < aim + 1; j++ ) {
            if ( j >= array[i] )
                dp[j] += dp[j - array[i]];
        }

    int result = dp[aim];
    delete dp;

    return result;
}

int main () {
    int array[4] = {5, 10, 25, 1};
    cout << numberOfMoneyChange1 ( array, 4, 0, 15 ) << endl;
    cout << numberOfMoneyChange2 ( array, 4, 15 ) << endl;
    cout << numberOfMoneyChange3 ( array, 4, 15 ) << endl;
    return 0;
}
