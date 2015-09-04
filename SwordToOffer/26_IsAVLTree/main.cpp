#include <iostream>
#include <math.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode ( int x ) :
        val ( x ), left ( NULL ), right ( NULL ) {
    }
};

class Solution_26 {
public:
    bool IsBalanced_Solution ( TreeNode* pRoot ) {
        if ( !pRoot )
            return true;
        return -1 != getHeight ( pRoot );
    }

private:
    int getHeight ( TreeNode *node ) {
        if ( !node )
            return 0;
        int left_height = getHeight ( node->left );
        if ( left_height == -1 )
            return -1;
        int right_height = getHeight ( node->right );
        if ( right_height == -1 )
            return -1;
        if ( abs ( left_height - right_height ) > 1 )
            return -1;
        return left_height > right_height ? left_height + 1 : right_height + 1;
    }
};

int main () {
    return 0;
}
