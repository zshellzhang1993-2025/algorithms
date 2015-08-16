#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode ( int x ) : val ( x ), left ( NULL ), right ( NULL ) {}
};

struct Info {
    int val;
    TreeNode *node;
    unsigned int pathlength;             //mark how many steps should the path have before the node
    Info() {}
    Info ( int x, TreeNode *n, int p ) : val ( x ), node ( n ), pathlength ( p ) {}
};

const int maxsize = 100;

class Solution_17 {
public:
    vector< vector<int> > FindPath ( TreeNode* root, int expectNumber ) {
        if ( !root )
            return result;
        Info stack[maxsize];
        int top = 0;
        Info tmp ( root->val, root , 0 );
        stack[0] = tmp;
        vector<int> path;       //mark the temporary path
        Info current;
        bool haschild = false;  //mark if the node has childs
        while ( top != -1 ) {
            current = stack[top--];
            haschild = false;
            while ( path.size() > current.pathlength ) { //pop the nodes which have been visited already
                path.pop_back();
            }
            path.push_back ( current.node->val );
            if ( current.node->right ) {
                tmp.node = current.node->right;
                tmp.val = tmp.node->val + current.val;
                tmp.pathlength = current.pathlength + 1;
                stack[++top] = tmp;
                haschild = true;
            }
            if ( current.node->left ) {
                tmp.node = current.node->left;
                tmp.val = tmp.node->val + current.val;
                tmp.pathlength = current.pathlength + 1;
                stack[++top] = tmp;
                haschild = true;
            }
            if ( !haschild && current.val == expectNumber )
                result.push_back ( path );
        }
        return result;
    }

private:
    vector< vector<int> > result;
};

int main () {
    TreeNode *root = new TreeNode ( 5 );
    TreeNode *tmp1 = new TreeNode ( 3 );
    root->left = tmp1;
    tmp1 = new TreeNode ( 4 );
    root->right = tmp1;
    TreeNode *tmp2 = new TreeNode ( 6 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 5 );
    tmp1->right = tmp2;
    tmp1 = root->left;
    tmp2 = new TreeNode ( 6 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 9 );
    tmp1->right = tmp2;
    Solution_17 s;
    vector< vector<int> > result = s.FindPath ( root, 14 );
    for ( vector< vector<int> >::iterator iter1 = result.begin(); iter1 < result.end(); iter1++ ) {
        for ( vector<int>::iterator iter2 = iter1->begin(); iter2 < iter1->end(); iter2++ )
            cout << *iter2 << " ";
        cout << "\n";
    }
    return 0;
}
