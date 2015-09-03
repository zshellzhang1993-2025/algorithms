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

struct Record {
    int height;
    TreeNode *node;
    Record ( int x, TreeNode *n ) : height ( x ), node ( n ) {}
    Record() {}
};

const int maxsize = 100;

class Solution_25 {
public:
    int TreeDepth ( TreeNode* pRoot ) {
        if ( !pRoot )
            return 0;
        Record stack[maxsize];
        int top = 0;
        stack[0] = Record ( 1, pRoot );
        Record current;
        int height = 0;
        while ( top != -1 ) {
            current = stack[top--];
            if ( height < current.height )
                height = current.height;
            if ( current.node-> right )
                stack[++top] = Record ( current.height + 1, current.node->right );
            if ( current.node->left )
                stack[++top] = Record ( current.height + 1, current.node->left );
        }
        return height;
    }
};

int main() {
    return 0;
}
