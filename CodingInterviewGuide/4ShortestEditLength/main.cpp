#include <iostream>
using namespace std;

/**
 * @brief dynamic programming with O(n^2) space
 * @param ic:insert cost
 * @param dc:delete cost
 * @param rc:replace cost
 */
int shortestEditLength1 ( string str1, string str2, int ic, int dc, int rc ) {
    int **dp = new int*[str1.size() + 1];
    for ( unsigned int i = 0; i < str1.size(); i++ )
        dp[i] = new int[str2.size() + 1];

    //initialize
    for ( unsigned int i = 0; i < str2.size(); i++ )
        dp[0][i] = i * ic;
    for ( unsigned int i = 1; i < str1.size(); i++ )
        dp[i][0] = i * dc;

    //run dynamic programming algorithm
    for ( unsigned int i = 1; i < str1.size(); i++ )
        for ( unsigned int j = 1; j < str2.size(); j++ ) {
            if ( str1[i] == str2[j] )
                dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = dp[i - 1][j] + dc < dp[i][j - 1] + ic ?
                           dp[i - 1][j] + dc : dp[i][j - 1] + ic;
                if ( dp[i - 1][j - 1] + rc < dp[i][j] )
                    dp[i][j] = dp[i - 1][j - 1] + rc;
            }
        }

    int result = dp[str1.size() - 1][str2.size() - 1];

    for ( unsigned int i = 0; i < str1.size(); i++ )
        delete dp[i];
    delete[] dp;

    return result;
}

// dynamic programming with condition compress in O(min{str1.size()+1,str2.size()+1}) space
int shortestEditLength2 ( string str1, string str2, int ic, int dc, int rc ) {
    int *dp;
    if ( str1.size() < str2.size() ) {
        dp = new int[str1.size()];
        for ( int i = 0; i < str1.size(); i++ )
            dp[i] = i * dc;

        for ( int i = 0; i < str1.size(); i++ ) {

        }

        delete dp;
    } else {
        dp = new int[str2.size()];
        delete dp;
    }
}

int main () {
    return 0;
}
