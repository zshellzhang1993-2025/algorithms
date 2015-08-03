#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode ( int x ) :
        val ( x ), left ( NULL ), right ( NULL ) {
    }
};

class Solution_15 {
public:
    vector<int> PrintFromTopToBottom ( TreeNode *root ) {
        vector<int> result;
        if ( !root )
            return result;
        const int size = 500;
        TreeNode* queue[size];
        int front = size - 1;
        int rear = 0;
        queue[rear] = root;
        TreeNode *current;
        while ( rear != front ) {
            front = ( front + 1 ) % size;
            current = queue[front];
            if ( current->left ) {
                rear = ( rear + 1 ) % size;
                queue[rear] = current->left;
            }
            if ( current->right ) {
                rear = ( rear + 1 ) % size;
                queue[rear] = current->right;
            }
            result.push_back ( current->val );
        }
        return result;
    }
};

int main() {
    Solution_15 s;
    TreeNode *root = new TreeNode ( 0 );
    TreeNode *tmp1 = new TreeNode ( 1 );
    root->left = tmp1;
    tmp1 = new TreeNode ( 2 );
    root->right = tmp1;
    TreeNode *tmp2 = new TreeNode ( 3 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 4 );
    tmp1->right = tmp2;
    vector<int> v = s.PrintFromTopToBottom ( root );
    for ( vector<int>::iterator iter = v.begin(); iter < v.end(); iter++ )
        cout << *iter << " ";
    return 0;
}
