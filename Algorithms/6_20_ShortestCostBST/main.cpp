#include <iostream>
#include <limits.h>
using namespace std;

//only calculate the shortest cost
int shortestCostBST ( int cost[], int n ) {
    int ***dp = new int**[n];
    for ( int i = 0; i < n; i++ )
        dp[i] = new int*[n];
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ )
            dp[i][j] = new int[2];

    for ( int i = 0; i < n; i++ )
        for ( int j = i; j < n; j++ ) {
            if ( i == j ) {
                dp[i][j][0] = cost[i];
                dp[i][j][1] = cost[i];
            } else
                dp[i][j][0] = INT_MAX;
        }

    int j = 0;
    int temp = 0;
    for ( int offset = 1; offset < n; offset++ ) {
        j = offset;
        for ( int i = 0; j < n; i++, j++ ) {
            dp[i][j][1] = dp[i][i][1] + dp[i + 1][j][1];
            temp = dp[i][i][0] + dp[i + 1][j][0] + dp[i + 1][j][1];
            if ( temp < dp[i][j][0] )
                dp[i][j][0] = temp;
            temp = dp[i][j - 1][0] + dp[i][j - 1][1] + dp[j][j][0];
            if ( temp < dp[i][j][0] )
                dp[i][j][0] = temp;
            for ( int k = i + 1; k < j; k++ ) {
                temp = dp[i][k - 1][0] + dp[k + 1][j][0]
                       + dp[i][k - 1][1] + dp[k][k][0] + dp[k + 1][j][1];
                if ( temp < dp[i][j][0] )
                    dp[i][j][0] = temp;
            }
        }
    }

    int result = dp[0][n - 1][0];
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ )
            delete dp[i][j];
    for ( int i = 0; i < n; i++ )
        delete[] dp[i];
    delete[] dp;

    return result;
}

struct TreeNode {
    string name;
    TreeNode *left;
    TreeNode *right;
    TreeNode ( string n ) : name ( n ), left ( NULL ), right ( NULL ) {}
};

struct Element {
    TreeNode *node;
    int root;
    int left;
    int right;
    Element ( TreeNode *n, int ro, int l, int ri ) : node ( n ), root ( ro ),
        left ( l ), right ( ri ) {}
    Element() {}
};

//calculate the shortest cost and generate the optimize tree
TreeNode* shortestCostBST ( string name[], int cost[], int n ) {
    int ***dp = new int**[n];
    for ( int i = 0; i < n; i++ )
        dp[i] = new int*[n];
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ )
            dp[i][j] = new int[3];

    for ( int i = 0; i < n; i++ )
        for ( int j = i; j < n; j++ ) {
            if ( i == j ) {
                dp[i][j][0] = cost[i];
                dp[i][j][1] = cost[i];
                dp[i][j][2] = -1;
            } else
                dp[i][j][0] = INT_MAX;
        }

    int j = 0;
    int temp = 0;
    for ( int offset = 1; offset < n; offset++ ) {
        j = offset;
        for ( int i = 0; j < n; i++, j++ ) {
            dp[i][j][1] = dp[i][i][1] + dp[i + 1][j][1];
            temp = dp[i][i][0] + dp[i + 1][j][0] + dp[i + 1][j][1];
            if ( temp < dp[i][j][0] ) {
                dp[i][j][0] = temp;
                dp[i][j][2] = i;
            }
            temp = dp[i][j - 1][0] + dp[i][j - 1][1] + dp[j][j][0];
            if ( temp < dp[i][j][0] ) {
                dp[i][j][0] = temp;
                dp[i][j][2] = j;
            }
            for ( int k = i + 1; k < j; k++ ) {
                temp = dp[i][k - 1][0] + dp[k + 1][j][0]
                       + dp[i][k - 1][1] + dp[k][k][0] + dp[k + 1][j][1];
                if ( temp < dp[i][j][0] ) {
                    dp[i][j][0] = temp;
                    dp[i][j][2] = k;
                }
            }
        }
    }

    Element tmp;
    TreeNode *node = new TreeNode ( name[dp[0][n - 1][2]] );
    TreeNode *root = node;
    const int max = 100;
    Element stk[max];
    stk[0] = Element ( node, dp[0][n - 1][2], 0, n - 1 );
    int pos = 0;
    while ( pos != -1 ) {
        tmp = stk[pos--];
        if ( tmp.left != tmp.root ) {
            if ( dp[tmp.left][tmp.root - 1][2] != -1 ) {
                node = new TreeNode ( name[dp[tmp.left][tmp.root - 1][2]] );
                tmp.node->left = node;
                stk[++pos] = Element ( node, dp[tmp.left][tmp.root - 1][2],
                                       tmp.left, tmp.root - 1 );
            } else
                tmp.node->left = new TreeNode ( name[tmp.left] );
        }
        if ( tmp.right != tmp.root ) {
            if ( dp[tmp.root + 1][tmp.right][2] != -1 ) {
                node = new TreeNode ( name[dp[tmp.root + 1][tmp.right][2]] );
                tmp.node->right = node;
                stk[++pos] = Element ( node, dp[tmp.root + 1][tmp.right][2],
                                       tmp.root + 1, tmp.right );
            } else
                tmp.node->right = new TreeNode ( name[tmp.right] );
        }
    }

    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ )
            delete dp[i][j];
    for ( int i = 0; i < n; i++ )
        delete[] dp[i];
    delete[] dp;

    return root;
}

void inOrder ( TreeNode *node ) {
    if ( node != NULL ) {
        inOrder ( node->left );
        cout << node->name << " ";
        inOrder ( node->right );
    }
}

int main () {
    int cost[7] = {5, 40, 8, 4, 10, 10, 23};
    string name[7] = {"begin", "do", "else", "end", "if", "then", "while"};
    cout << shortestCostBST ( cost, 7 ) << endl;
    TreeNode *node = shortestCostBST ( name, cost, 7 );
    inOrder ( node );
    return 0;
}
