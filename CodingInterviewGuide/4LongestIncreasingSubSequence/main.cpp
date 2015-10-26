#include <iostream>
using namespace std;

//traditional linear traversal for O(n^2) time
void getDp1 ( string str, int dp[] ) {
    dp[0] = 1;
    int max;
    for ( unsigned int i = 1; i < str.size(); i++ ) {
        max = 0;
        for ( unsigned int j = 0; j < i; j++ ) {
            if ( str[j] < str[i] && dp[j] > max )
                max = dp[j];
        }
        dp[i] = max + 1;
    }
}

//using binary serach for O(nlogn) time
void getDp2 ( string str, int dp[] ) {
    int *ends = new int[str.size()];
    ends[0] = str[0];
    dp[0] = 1;
    unsigned int right = 0;
    int begin;
    int end;
    int current;
    for ( unsigned int i = 0; i < str.size(); i++ ) {
        begin = 0;
        end = right;
        while ( begin <= end ) {
            current = ( begin + end ) / 2;
            if ( str[i] < ends[current] )
                end = current - 1;
            else if ( str[i] > ends[current] )
                begin = current + 1;
            else {
                begin = current;
                break;
            }
        }
        if ( begin > right )
            right++;
        ends[begin] = str[i];
        dp[i] = begin + 1;
    }
}

//using given dp array to generate all the longest increasing sub strings
string generateLIS ( string str, int dp[] ) {
    int size = 0;
    int pos = 0;
    int current = 0;
    for ( unsigned int i = 0; i < str.size(); i++ ) {
        if ( dp[i] > size ) {
            pos = i;
            size = dp[i];
        }
    }
    current = pos;
    string result ( size--, str[pos] );
    while ( size > 0 ) {
        if ( dp[--current] != dp[pos] - 1 )
            continue;
        else {
            result[--size] = str[current];
            pos = current;
        }
    }
    return result;
}

//using getDp1
string longestIncreasingSubString1 ( string str ) {
    if ( str.empty() )
        return "";
    else {
        int *dp = new int[str.size()];
        getDp1 ( str, dp );
        string result = generateLIS ( str, dp );
        delete dp;
        return result;
    }
}


//using getDp2
string longestIncreasingSubString2 ( string str ) {
    if ( str.empty() )
        return "";
    else {
        int *dp = new int[str.size()];
        getDp2 ( str, dp );
        string result = generateLIS ( str, dp );
        delete dp;
        return result;
    }
}

int main () {
    cout << longestIncreasingSubString1 ( "215364897" ) << endl;
    cout << longestIncreasingSubString2 ( "215364897" ) << endl;
    return 0;
}
