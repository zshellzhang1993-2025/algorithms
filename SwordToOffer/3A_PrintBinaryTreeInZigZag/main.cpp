#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode ( int x ) :
        val ( x ), left ( NULL ), right ( NULL ) {
    }
};

const int maxsize = 100;

class Solution_3a {
public:
    vector<vector<int> > Print ( TreeNode* pRoot ) {
        if ( !pRoot )
            return result;
        int countleft = 0;
        int countright = 1;
        TreeNode* deque[maxsize];
        TreeNode *node;
        int left = 0;
        int right = 0;
        deque[0] = pRoot;
        vector<int> tmp;
        while ( countleft > 0 || countright > 0 ) {
            tmp.clear();
            while ( countleft > 0 ) {
                node = deque[left];
                tmp.push_back ( node->val );
                left = ( left + 1 ) % maxsize;
                countleft--;
                if ( countleft + countright < maxsize && node->right ) {
                    countright++;
                    right = ( right + 1 ) % maxsize;
                    deque[right] = node->right;
                }
                if ( countleft + countright < maxsize && node->left ) {
                    countright++;
                    right = ( right + 1 ) % maxsize;
                    deque[right] = node->left;
                }
            }
            if ( !tmp.empty() )
                result.push_back ( tmp );
            tmp.clear();
            while ( countright > 0 ) {
                node = deque[right];
                tmp.push_back ( node->val );
                right = ( right + maxsize - 1 ) % maxsize;
                countright--;
                if ( countleft + countright < maxsize && node->left ) {
                    countleft++;
                    left = ( left + maxsize - 1 ) % maxsize;
                    deque[left] = node->left;
                }
                if ( countleft + countright < maxsize && node->right ) {
                    countleft++;
                    left = ( left + maxsize - 1 ) % maxsize;
                    deque[left] = node->right;
                }
            }
            if ( !tmp.empty() )
                result.push_back ( tmp );
        }
        return result;
    }

private:
    vector< vector<int> > result;
};

int main() {
    TreeNode *root1 = new TreeNode ( 8 );
    TreeNode *tmp1 = new TreeNode ( 4 );
    root1->right = tmp1;
    tmp1 = new TreeNode ( 7 );
    root1->left = tmp1;
    TreeNode *tmp2 = new TreeNode ( 9 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 2 );
    tmp1->right = tmp2;
    tmp1 = root1->right;
    tmp2 = new TreeNode ( 1 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 5 );
    tmp1->right = tmp2;

    Solution_3a s;
    vector< vector<int> > result = s.Print ( root1 );

    for ( vector< vector<int> >::iterator iter1 = result.begin(); iter1 < result.end(); iter1++ ) {
        for ( vector<int>::iterator iter2 = ( *iter1 ).begin(); iter2 < ( *iter1 ).end(); iter2++ )
            cout << *iter2 << ' ';
        cout << '\n';
    }
    return 0;
}
