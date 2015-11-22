#include <iostream>
#include <vector>
using namespace std;

// complete backpack problem
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
    int current = dp[aim] - 1;
    int target = aim;
    while ( target > 0 ) {
        for ( int i = 0; i < n; i++ ) {
            if ( dp[target] - 1 == dp[target - array[i]] ) {
                v[current] = array[i];
                current--;
                target = target - array[i];
                break;
            }
        }
    }

    delete dp;
    return v;
}

// 0/1 backpack problem
int leastNumberOfMoneyChange2 ( int array[], int n, int aim ) {

}

int main () {
    return 0;
}
