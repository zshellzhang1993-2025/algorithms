#include <iostream>
using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int value;
    TreeNode ( int v ) : value ( v ) {}
};

TreeNode* unSerialize ( string sequence ) {

}

void Serialize ( TreeNode *node ) {

}

/**
 * @brief Morris Order free of recursion with O(n) time && O(1) space
 */

TreeNode* findPrev ( TreeNode *node ) {
    if ( !node || !node->left )
        return NULL;
    TreeNode *leftchild = node->left;
    if ( !leftchild->right )
        return leftchild;
    else {
        TreeNode *rightchild = leftchild->right;
        while ( rightchild && rightchild != node ) {
            leftchild = rightchild;
            rightchild = leftchild->right;
        }
        return leftchild;
    }
}

void morrisInOrder ( TreeNode *node ) {
    while ( true ) {
        while ( node && node->left ) {
            TreeNode *pre = findPrev ( node );
            pre->right = node;
            node = node->left;
        }
        while ( node ) {
            cout << node->value << " ";
            TreeNode *next = node->right;
            if ( node == findPrev ( next ) ) {
                node->right = NULL;
                node = next;
            } else {
                node = next;
                break;
            }
        }
        if ( !node ) {
            cout << endl;
            break;
        }
    }
}

void morrisPreOrder ( TreeNode *node ) {
    while ( true ) {
        while ( node ) {
            cout << node->value << " ";
            if ( node->left ) {
                TreeNode *pre = findPrev ( node );
                pre->right = node;
                node = node->left;
            } else
                break;
        }
        while ( node ) {
            TreeNode *next = node->right;
            if ( node == findPrev ( next ) ) {
                node->right = NULL;
                node = next;
            } else {
                node = next;
                break;
            }
        }
        if ( !node ) {
            cout << endl;
            break;
        }
    }
}

void morrisSubOrder ( TreeNode *node ) {

}

int main () {
    return 0;
}
