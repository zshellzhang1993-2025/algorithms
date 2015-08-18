#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode ( int x ) :
        val ( x ), left ( NULL ), right ( NULL ) {
    }
};

class Solution_19 {
public:
    TreeNode* Convert ( TreeNode* pRootOfTree ) {
        if ( !pRootOfTree )
            return NULL;
        makeDoubleLink ( pRootOfTree );
        while ( pRootOfTree->left )
            pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }

private:
    TreeNode* getExtreme ( TreeNode *node, bool isleft ) {
        if ( !node )
            return NULL;
        if ( isleft ) {
            while ( node->right )
                node = node->right;
            return node;
        } else {
            while ( node->left )
                node = node->left;
            return node;
        }
    }

    void makeDoubleLink ( TreeNode *node ) {
        if ( !node )
            return;
        TreeNode *leftMax = getExtreme ( node->left, true );
        TreeNode *rightMin = getExtreme ( node->right, false );
        makeDoubleLink ( node->left );
        makeDoubleLink ( node->right );
        node->left = leftMax;
        if ( leftMax )
            leftMax->right = node;
        node->right = rightMin;
        if ( rightMin )
            rightMin->left = node;
    }
};

int main () {
    TreeNode *root = new TreeNode ( 5 );
    root->left = new TreeNode ( 3 );
    root->right = new TreeNode ( 8 );
    TreeNode *tmp = root->right;
    tmp->left = new TreeNode ( 7 );
    tmp->right = new TreeNode ( 10 );
    tmp = tmp->left;
    tmp->left = new TreeNode ( 6 );
    tmp = root->right->right;
    tmp->left = new TreeNode ( 9 );
    tmp->right = new TreeNode ( 12 );
    tmp = root->left;
    tmp->left = new TreeNode ( 1 );
    tmp->right = new TreeNode ( 4 );
    tmp = tmp->left;
    tmp->right = new TreeNode ( 2 );

    Solution_19 s;
    tmp = s.Convert ( root );
    while ( tmp ) {
        cout << tmp->val;
        tmp = tmp->right;
    }
    return 0;
}
