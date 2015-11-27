#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// complete backpack problem
vector<int> leastNumberOfMoneyChange1 ( int array[], int n, int aim ) {
    int *dp = new int[aim + 1];

    dp[0] = 0;
    for ( int i = 1; i < aim + 1; i++ )
        dp[i] = INT_MAX - 1;

    for ( int i = 1; i < aim + 1; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            if ( i >= array[j] && dp[i - array[j]] + 1 < dp[i] )
                dp[i] = dp[i - array[j]] + 1;
        }
    }

    // if has no result
    if ( dp[aim] == INT_MAX - 1 ) {
        vector<int> error ( 1, -1 );
        return error;
    }

    vector<int> result ( dp[aim] );
    int current = dp[aim] - 1;
    int target = aim;
    while ( target > 0 ) {
        for ( int i = 0; i < n; i++ ) {
            if ( target >= array[i] && dp[target] - 1 == dp[target - array[i]] ) {
                result[current] = array[i];
                current--;
                target = target - array[i];
                break;
            }
        }
    }

    delete dp;
    return result;
}

// 0/1 backpack problem without condition compress
vector<int> leastNumberOfMoneyChange2 ( int array[], int n, int aim ) {
    int **dp = new int*[n];
    for ( int i = 0; i < n; i++ )
        dp[i] = new int[aim + 1];

    for ( int i = 0; i < n; i++ )
        dp[i][0] = 0;
    for ( int i = 1; i < aim + 1; i++ )
        dp[0][i] = INT_MAX - 1;
    if ( array[0] <= aim )
        dp[0][array[0]] = 1;

    for ( int i = 1; i < n; i++ )
        for ( int j = 1; j < aim + 1; j++ ) {
            if ( j >= array[i] && dp[i - 1][j - array[i]] + 1 < dp[i - 1][j] )
                dp[i][j] = dp[i - 1][j - array[i]] + 1;
            else
                dp[i][j] = dp[i - 1][j];
        }

    // if has no result
    if ( dp[n - 1][aim] == INT_MAX - 1 ) {
        vector<int> error ( 1, -1 );
        return error;
    }

    vector<int> result ( dp[n - 1][aim] );
    int current = dp[n - 1][aim] - 1;
    int target = aim;
    int index = n;
    while ( target > 0 ) {
        index--;
        if ( index == 0 ) {
            if ( dp[0][target] == 1 && target == array[0] )
                result[current] = array[0];
            break;
        }
        if ( target >= array[index] && dp[index][target] - 1
                == dp[index - 1][target - array[index]] ) {
            result[current] = array[index];
            current--;
            target = target - array[index];
        }
    }

    for ( int i = 0; i < n; i++ )
        delete dp[i];
    delete dp;

    return result;
}

// 0/1 backpack problem with condition compress
int leastNumberOfMoneyChange3 ( int array[], int n, int aim ) {
    int *dp = new int[aim + 1];
    dp[0] = 0;
    for ( int i = 1; i < aim + 1; i++ )
        dp[i] = INT_MAX - 1;
    if ( array[0] <= aim )
        dp[array[0]] = 1;

    for ( int i = 1; i < n - 1; i++ ) {
        for ( int j = aim; j > 0 ; j-- ) {
            if ( j >= array[i] && dp[j - array[i]] + 1 < dp[j] )
                dp[j] = dp[j - array[i]] + 1;
        }
    }

    //the last row does not need to be all-element calculated at all
    //the last element of the last row is enough
    int result = 0;
    if ( aim >= array[n - 1] && dp[aim - array[n - 1]] + 1 < dp[aim] )
        result = dp[aim - array[n - 1]] + 1;
    else
        result = dp[aim];

    delete dp;

    return result == INT_MAX - 1 ? -1 : result;
}

// multi backpack problem
vector<int> leastNumberOfMoneyChange4 ( int array[], int n, int aim ) {

}

int main () {
    int array1[3] = {5, 2, 3};
    vector<int> result = leastNumberOfMoneyChange1 ( array1, 3, 1 );
    for ( vector<int>::iterator iter = result.begin(); iter != result.end(); iter++ )
        cout << *iter << " ";
    cout << endl;
    int array2[5] = {5, 2, 3, 5};
    result = leastNumberOfMoneyChange2 ( array2, 4, 1 );
    for ( vector<int>::iterator iter = result.begin(); iter != result.end(); iter++ )
        cout << *iter << " ";
    cout << endl;
    cout << leastNumberOfMoneyChange3 ( array2, 4, 12 );
    cout << endl;
    return 0;
}
