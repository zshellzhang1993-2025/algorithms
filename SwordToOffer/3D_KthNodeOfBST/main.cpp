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

class Solution_3d {
public:
    TreeNode* KthNode ( TreeNode* pRoot, unsigned int k ) {
        if ( !pRoot || k == 0 )
            return NULL;
        TreeNode* stack[maxsize];
        int top = 0;
        unsigned int count = 0;
        TreeNode *node = pRoot;
        stack[0] = node;
        while ( node->left ) {
            stack[++top] = node->left;
            node = node->left;
        }
        while ( top != -1 ) {
            node = stack[top--];
            count++;
            if ( count == k )
                break;
            node = node->right;
            if ( node ) {
                stack[++top] = node;
                while ( node->left ) {
                    stack[++top] = node->left;
                    node = node->left;
                }
            }
        }
        if ( count == k )
            return node;
        return NULL;
    }
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

    Solution_3d s;
    root1 = s.KthNode ( root1, 5 );
    cout << root1->val;
    return 0;
}
