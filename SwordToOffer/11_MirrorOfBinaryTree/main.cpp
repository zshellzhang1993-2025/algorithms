#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode ( int x ) :
        val ( x ), left ( NULL ), right ( NULL ) {
    }
};

class Solution_11 {
public:
    void Mirror ( TreeNode *pRoot ) {
        if ( pRoot == NULL )
            return;
        else {
            Mirror ( pRoot->left );
            Mirror ( pRoot->right );
            TreeNode *tmp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = tmp;
        }
    }
};

int main () {
    return 0;
}
