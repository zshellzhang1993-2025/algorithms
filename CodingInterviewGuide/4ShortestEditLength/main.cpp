#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const string del = "delete ";
const string insert = "insert ";
const string same = "the two strings have the same letter ";
const string replace = "replace ";

/**
 * @brief change str1 to str2,dynamic programming with O(n^2) space
 * @param ic:insert cost
 * @param dc:delete cost
 * @param rc:replace cost
 */
vector<string> shortestEditLength1 ( string str1, string str2, int ic, int dc, int rc ) {
    int **dp = new int*[str1.size() + 1];
    for ( unsigned int i = 0; i < str1.size() + 1; i++ )
        dp[i] = new int[str2.size() + 1];

    //initialize
    for ( unsigned int i = 0; i < str2.size() + 1; i++ )
        dp[0][i] = i * ic;
    for ( unsigned int i = 1; i < str1.size() + 1; i++ )
        dp[i][0] = i * dc;

    //run dynamic programming algorithm
    for ( unsigned int i = 1; i < str1.size() + 1; i++ )
        for ( unsigned int j = 1; j < str2.size() + 1; j++ ) {
            dp[i][j] = dp[i - 1][j] + dc < dp[i][j - 1] + ic ?
                       dp[i - 1][j] + dc : dp[i][j - 1] + ic;
            if ( str1[i - 1] == str2[j - 1] && dp[i - 1][j - 1] < dp[i][j] ) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if ( str1[i - 1] != str2[j - 1] && dp[i - 1][j - 1] + rc < dp[i][j] )
                dp[i][j] = dp[i - 1][j - 1] + rc;
        }

    vector<string> result;
    stack<string> stk;
    int i = str1.size();
    int j = str2.size();

    //find from the tail to the head for the path
    while ( i > 0 || j > 0 ) {
        if ( i > 0 && j > 0 ) {
            if ( dp[i][j] - dc == dp[i - 1][j] )
                stk.push ( del + str1[--i] );
            else if ( dp[i][j] - ic == dp[i][j - 1] )
                stk.push ( insert + str2[--j] );
            else if ( str1[i - 1] == str2[j - 1] && dp[i][j] == dp[i - 1][j - 1] ) {
                stk.push ( same + str1[--i] );
                j--;
            } else if ( str1[i - 1] != str2[j - 1] && dp[i][j] - rc == dp[i - 1][j - 1] ) {
                string tmp = replace + str1[--i];
                tmp = tmp + " to ";
                tmp = tmp + str2[--j];
                stk.push ( tmp );
            }
        } else if ( i == 0 ) {
            while ( j >= 0 )
                stk.push ( insert + str2[--j] );
        } else if ( j == 0 ) {
            while ( i >= 0 )
                stk.push ( del + str1[--i] );
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
    int result = 0;
    int left_top = 0;
    int tmp = 0;
    if ( str1.size() < str2.size() ) {
        dp = new int[str1.size() + 1];
        for ( unsigned int i = 0; i < str1.size() + 1; i++ )
            dp[i] = i * dc;

        for ( unsigned int i = 1; i < str2.size() + 1; i++ )
            for ( unsigned int j = 0; j < str1.size() + 1; j++ ) {
                tmp = dp[j];
                if ( j == 0 ) {
                    dp[j] = dp[j] + ic;
                } else {
                    dp[j] = dp[j] + ic < dp[j - 1] + dc ?
                            dp[j] + ic : dp[j - 1] + dc;
                    if ( str1[j - 1] == str2[i - 1] && left_top < dp[j] )
                        dp[j] = left_top;
                    else if ( str1[j - 1] != str2[i - 1] && left_top + rc < dp[j] )
                        dp[j] = left_top + rc;
                }
                left_top = tmp;
            }

        result = dp[str1.size()];
        delete dp;

        return result;

    } else {
        dp = new int[str2.size() + 1];
        for ( unsigned int i = 0; i < str2.size() + 1; i++ )
            dp[i] = i * ic;

        for ( unsigned int i = 1; i < str1.size() + 1; i++ )
            for ( unsigned int j = 0; j < str2.size() + 1; j++ ) {
                tmp = dp[j];
                if ( j == 0 ) {
                    dp[j] = dp[j] + dc;
                } else {
                    dp[j] = dp[j - 1] + ic < dp[j] + dc ?
                            dp[j - 1] + ic : dp[j] + dc;
                    if ( str1[i - 1] == str2[j - 1] && left_top < dp[j] )
                        dp[j] = left_top;
                    else if ( str1[i - 1] != str2[j - 1] && left_top + rc < dp[j] )
                        dp[j] = left_top + rc;
                }
                left_top = tmp;
            }

        result = dp[str2.size()];
        delete dp;

        return result;
    }
}

int main () {
    vector<string> v = shortestEditLength1 ( "ab12cd3", "abcdf", 5, 3, 2 );
    for ( vector<string>::iterator iter = v.begin(); iter != v.end(); iter++ )
        cout << *iter << endl;

    cout << shortestEditLength2 ( "ab12cd3", "abcdf", 5, 3, 2 ) << endl;
    return 0;
}
