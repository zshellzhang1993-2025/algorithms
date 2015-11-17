#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * @brief change str1 to str2,dynamic programming with O(n^2) space
 * @param ic:insert cost
 * @param dc:delete cost
 * @param rc:replace cost
 */
vector<string> shortestEditLength1 ( string str1, string str2, int ic, int dc, int rc ) {
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

    vector<string> result;
    stack<string> stk;
    int i = str1.size() - 1;
    int j = str2.size() - 1;

    while ( i > 0 || j > 0 ) {
        if ( i > 0 && j > 0 ) {
            if ( dp[i][j] + dc == dp[i - 1][j] )
                stk.push ( "delete " + str1[i--] );
            else if ( dp[i][j] + ic == dp[i][j - 1] )
                stk.push ( "insert " + str2[j--] );
            else if ( dp[i][j] == dp[i - 1][j - 1] ) {
                stk.push ( "the two strings have the same letter " + str1[i--] );
                j--;
            } else if ( dp[i][j] + rc == dp[i - 1][j - 1] ) {
                string tmp = "replace " + str1[i--];
                tmp = tmp + " to " + str2[j--];
                stk.push ( tmp );
            }
        } else if ( i == 0 ) {
            while ( j >= 0 )
                stk.push ( "insert " + str2[j--] );
        } else if ( j == 0 ) {
            while ( i >= 0 )
                stk.push ( "delete " + str1[i--] );
        }
    }

    while ( !stk.empty() ) {
        result.push_back ( stk.top() );
        stk.pop();
    }

    for ( unsigned int i = 0; i < str1.size(); i++ )
        delete dp[i];
    delete dp;

    return result;
}

// dynamic programming with condition compress in O(min{str1.size()+1,str2.size()+1}) space
int shortestEditLength2 ( string str1, string str2, int ic, int dc, int rc ) {
    int *dp;
    if ( str1.size() < str2.size() ) {
        dp = new int[str1.size()];
        for ( unsigned int i = 0; i < str1.size(); i++ )
            dp[i] = i * dc;

        for ( unsigned int i = 0; i < str1.size(); i++ ) {

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
