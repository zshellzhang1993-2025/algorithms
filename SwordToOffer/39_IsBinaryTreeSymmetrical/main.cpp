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

const int maxsize = 100;

class Solution_39 {
public:
    bool isSymmetrical ( TreeNode* pRoot ) {
        if ( !pRoot )
            return true;
        TreeNode* stackleft[maxsize];
        int topleft = 0;
        TreeNode* stackright[maxsize];
        int topright = 0;
        TreeNode *leftNode;
        TreeNode *rightNode;
        bool hasleft = false;
        bool hasright = false;
        if ( pRoot->left ) {
            stackleft[0] = pRoot->left;
            hasleft = true;
        }
        if ( pRoot->right ) {
            stackright[0] = pRoot->right;
            hasright = true;
        }
        if ( !hasleft && !hasright )
            return true;
        if ( ! ( hasleft && hasright ) )
            return false;
        while ( topleft != -1 ) {
            leftNode = stackleft[topleft--];
            rightNode = stackright[topright--];
            if ( leftNode->val != rightNode->val )
                return false;
            if ( leftNode->right ) {
                stackleft[++topleft] = leftNode->right;
                hasleft = true;
            } else
                hasleft = false;
            if ( rightNode->left ) {
                stackright[++topright] = rightNode->left;
                hasleft = true;
            } else
                hasright = false;
            if ( hasleft != hasright )
                return false;
            if ( leftNode->left ) {
                stackleft[++topleft] = leftNode->left;
                hasleft = true;
            } else
                hasleft = false;
            if ( rightNode->right ) {
                stackright[++topright] = rightNode->right;
                hasright = true;
            } else
                hasright = false;
            if ( hasleft != hasright )
                return false;
        }
        return true;
    }
};

int main() {
    TreeNode *root1 = new TreeNode ( 8 );
    TreeNode *tmp1 = new TreeNode ( 8 );
    root1->right = tmp1;
    tmp1 = new TreeNode ( 7 );
    root1->left = tmp1;
    TreeNode *tmp2 = new TreeNode ( 9 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 2 );
    tmp1->right = tmp2;
    tmp1 = root1->right;
    tmp2 = new TreeNode ( 2 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 9 );
    tmp1->right = tmp2;

    Solution_39 s;
    cout << s.isSymmetrical ( root1 );
    return 0;
}
