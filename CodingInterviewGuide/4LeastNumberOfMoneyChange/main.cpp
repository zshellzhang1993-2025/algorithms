#include <iostream>
using namespace std;

//complete backpack problem
vector<int> leastNumberOfMoneyChange1 ( int array[], int n, int aim ) {
    int *dp = new int[aim + 1];

    for ( int i = 0; i < aim + 1; i++ )
        dp[i] = -1;
    dp[0] = 0;

    for ( int i = 1; i < aim + 1; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            if ( i >= array[j] && dp[i - array[j]] != -1 &&
                    dp[i - array[j]] + 1 < dp[i] )
                dp[i] = dp[i - array[j]] + 1;
        }
    }

    vector<int> v ( dp[aim] );
    while ( 1 ) {

    }

    delete dp;
}

// 0/1 backpack problem
int leastNumberOfMoneyChange2 ( int array[], int n, int aim ) {

}

int main () {
    return 0;
}
