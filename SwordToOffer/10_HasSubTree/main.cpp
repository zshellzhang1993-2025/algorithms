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

class Solution_10 {
public:
    bool HasSubtree ( TreeNode* pRoot1, TreeNode* pRoot2 ) {
        if ( !pRoot1 || !pRoot2 )
            return false;
        int val = pRoot2->val;
        TreeNode* queue1[maxsize];
        TreeNode* queue2[maxsize][2];
        int top1 = 0;
        int top2 = 0;
        queue1[0] = pRoot1;
        TreeNode *pCurrent;     //used in outer while module
        TreeNode *pCurrent1;    //used in inner while module
        TreeNode *pCurrent2;    //used in inner while module
        bool hasSub = false;
        while ( top1 != -1 ) {
            pCurrent = queue1[top1--];
            if ( pCurrent->val == val ) {
                top2 = 0;
                queue2[0][0] = pRoot2;
                queue2[0][1] = pCurrent;
                while ( top2 != -1 ) {
                    hasSub = true;
                    pCurrent2 = queue2[top2][0];
                    pCurrent1 = queue2[top2--][1];
                    if ( pCurrent2->val == pCurrent1->val ) {
                        if ( pCurrent2->right ) {
                            if ( pCurrent1->right ) {
                                queue2[++top2][0] = pCurrent2->right;
                                queue2[top2][1] = pCurrent1->right;
                            } else {
                                hasSub = false;
                                break;
                            }
                        }
                        if ( pCurrent2->left ) {
                            if ( pCurrent1->left ) {
                                queue2[++top2][0] = pCurrent2->left;
                                queue2[top2][1] = pCurrent1->left;
                            } else {
                                hasSub = false;
                                break;
                            }
                        }
                    } else {
                        hasSub = false;
                        break;
                    }
                }
                if ( hasSub )
                    return true;
            }
            if ( pCurrent->right )
                queue1[++top1] = pCurrent->right;
            if ( pCurrent->left )
                queue1[++top1] = pCurrent->left;
        }
        return false;
    }
};

int main() {
    TreeNode *root1 = new TreeNode ( 8 );
    TreeNode *tmp1 = new TreeNode ( 7 );
    root1->right = tmp1;
    tmp1 = new TreeNode ( 8 );
    root1->left = tmp1;
    TreeNode *tmp2 = new TreeNode ( 9 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 2 );
    tmp1->right = tmp2;
    tmp1 = tmp2;
    tmp2 = new TreeNode ( 4 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 7 );
    tmp1->right = tmp2;

    TreeNode *root2 = new TreeNode ( 8 );
    tmp2 = new TreeNode ( 9 );
    root2->left = tmp2;
    tmp2 = new TreeNode ( 2 );
    root2->right = tmp2;

    Solution_10 s;
    cout << s.HasSubtree ( root1, root2 );
    return 0;
}
