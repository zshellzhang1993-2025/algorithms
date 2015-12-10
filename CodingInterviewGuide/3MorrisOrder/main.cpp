#include <iostream>
using namespace std;

struct TreeNode {
    char value;
    TreeNode *left;
    TreeNode *right;
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
    TreeNode *tmp;
    TreeNode *next;
    TreeNode *father;
    TreeNode *root = node;
    bool canPrint = false;
    while ( true ) {
        while ( node && node->left && !canPrint ) {
            TreeNode *pre = findPrev ( node );
            pre->right = node;
            node = node->left;
        }
        while ( ( node && !node->left ) || canPrint ) {
            canPrint = false;
            TreeNode *next = node->right;
            if ( node == findPrev ( next ) || !next ) {
                if ( next ) {
                    node->right = NULL;
                    node = next->left;
                } else
                    node = root;
                father = next;
                canPrint = true;
                break;
            }
            node = next;
        }
        if ( canPrint ) {
            tmp = NULL;
            while ( node ) {
                next = node->right;
                node->right = tmp;
                tmp = node;
                node = next;
            }
            node = tmp;
            tmp = NULL;
            while ( node ) {
                cout << node->value << " ";
                next = node->right;
                node->right = tmp;
                tmp = node;
                node = next;
            }
            node = father;
        }
        if ( !father ) {
            cout << endl;
            break;
        }
    }
}

/**
 * @brief a serial of operations based on the above morris traversal
 */

TreeNode* unSerialize ( string sequence ) {
    string::iterator iter = sequence.begin();
    TreeNode *current = new TreeNode ( *iter );
    TreeNode *root = current;
    TreeNode *child;
    for (  iter++; iter != sequence.end(); iter++ ) {
        if ( *iter != '#' ) {
            child = new TreeNode ( *iter );
            if ( * ( iter - 1 ) == '#' ) {
                child->right = current->right;
                current->right = child;
            } else {
                current->left = child;
                child->right = current;
            }
            current = child;
        } else if ( * ( iter - 1 ) == '#' ) {
            current = child->right;
            child->right = NULL;
        }
    }
    return root;
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
            result.append ( 1, '#' );
            //cout << endl;
            break;
        }
    }
    return result;
}

void Free ( TreeNode *node ) {

}

int main () {
    string s1 = "124##58##9##36##7##";
    string s2 = "12#58##9##36###";
    TreeNode *root = unSerialize ( s2 );
    morrisInOrder ( root );
    morrisPreOrder ( root );
    morrisSubOrder ( root );
    cout << Serialize ( root ) << endl;
    Free ( root );
    return 0;
}
