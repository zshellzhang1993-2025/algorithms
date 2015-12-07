#include <iostream>
using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    char value;
    TreeNode ( char v ) : value ( v ), left ( NULL ), right ( NULL ) {}
};

/**
 * @brief Morris Traversal free of recursion with O(n) time && O(1) space
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

/**
 * @brief a serial of operations based on the above morris traversal
 */

TreeNode* unSerialize ( string sequence ) {
    string::iterator iter = sequence.begin();
    TreeNode *current = new TreeNode ( *iter );
    TreeNode *child;
    for (  iter++; iter != sequence.end(); iter++ ) {
        if ( *iter != '#' ) {
            child = new TreeNode ( *iter );
            if ( * ( iter - 1 ) == '#' && * ( iter - 2 ) == '#' )
                current->right = child;
            else
                current->left = child;
            child->right = iter;
            current = child;
        } else if ( * ( iter - 1 ) == '#' ) {
            current = child->right;
            child->right = NULL;
        }
    }
}

string Serialize ( TreeNode *node ) {
    string result = "";
    while ( true ) {
        while ( node ) {
            result.append ( 1, node->value );
            if ( node->left ) {
                TreeNode *pre = findPrev ( node );
                pre->right = node;
                node = node->left;
            } else {
                result.append ( 1, '#' );
                break;
            }
        }
        while ( node ) {
            TreeNode *next = node->right;
            if ( node == findPrev ( next ) ) {
                result.append ( 1, '#' );
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
    return result;
}

void Free ( TreeNode *node ) {

}

int main () {
    return 0;
}
