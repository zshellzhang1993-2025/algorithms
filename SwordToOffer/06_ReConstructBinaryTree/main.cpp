#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode ( int x ) : val ( x ), left ( NULL ), right ( NULL ) {}
};

class Solution_6 {
public:
    struct TreeNode* reConstructBinaryTree ( vector<int> pre, vector<int> in ) {
        if ( pre.size() == 0 )
            return NULL;
        int rootVal = pre[0];
        TreeNode *root = new TreeNode ( rootVal );
        int count = 0;
        vector<int>::iterator rootIter = in.begin();
        for ( ; rootIter != in.end(); rootIter++ ) {
            if ( *rootIter == rootVal )
                break;
            count++;
        }
        vector<int> leftPre;
        vector<int> leftIn;
        if ( rootIter - in.begin() > 0 ) {
            leftPre.assign ( pre.begin() + 1, pre.begin() + 1 + count );
            leftIn.assign ( in.begin(), in.begin() + count );
        }
        vector<int> rightPre;
        vector<int> rightIn;
        if ( in.end() - rootIter > 1 ) {
            rightPre.assign ( pre.begin() + 1 + count, pre.end() );
            rightIn.assign ( rootIter + 1, in.end() );
        }
        root->left = reConstructBinaryTree ( leftPre, leftIn );
        root->right = reConstructBinaryTree ( rightPre, rightIn );
        return root;
    }

    void postOrderTravesal ( TreeNode *node ) {
        if ( !node )
            return;
        else {
            postOrderTravesal ( node->left );
            postOrderTravesal ( node->right );
            post.push_back ( node->val );
        }
    }

    void deleteTree ( TreeNode *node ) {
        if ( !node )
            return;
        else {
            deleteTree ( node->left );
            deleteTree ( node->right );
            delete ( node );
        }
    }

    void printPostOrder() {
        for ( vector<int>::iterator iter = post.begin(); iter != post.end(); iter++ )
            cout << *iter << " ";
    }

private:
    vector<int> post;
};

int main() {
    int data1[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int data2[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    vector<int> pre ( data1, data1 + 8 );
    vector<int> in ( data2, data2 + 8 );
    Solution_6 s;
    TreeNode *root = s.reConstructBinaryTree ( pre, in );
    s.postOrderTravesal ( root );
    s.deleteTree ( root );
    s.printPostOrder();
    return 0;
}
