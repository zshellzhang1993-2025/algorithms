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

class Solution_10 {
public:
    bool HasSubtree ( TreeNode* pRoot1, TreeNode* pRoot2 ) {
        int val = pRoot2->val;

    }

};

int main() {
    return 0;
}
