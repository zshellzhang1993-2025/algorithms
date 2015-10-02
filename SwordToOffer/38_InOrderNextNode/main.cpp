#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode ( int x ) : val ( x ), left ( NULL ), right ( NULL ), next ( NULL ) {

    }
};

class Solution_38 {
public:
    TreeLinkNode* GetNext ( TreeLinkNode* pNode ) {
        if ( !pNode )
            return NULL;
        if ( pNode->right ) {
            TreeLinkNode *node = pNode->right;
            while ( node->left )
                node = node->left;
            return node;
        } else {
            TreeLinkNode *node = pNode;
            while ( node->next && node->next->left != node )
                node = node->next;
            return node->next;
        }
    }
};

int main() {
    return 0;
}
