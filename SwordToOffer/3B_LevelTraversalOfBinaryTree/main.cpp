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

class Solution_3b {
public:
    vector<vector<int> > Print ( TreeNode* pRoot ) {
        vector< vector<int> > result;
        if ( !pRoot )
            return result;
        const int size = 100;
        TreeNode* queue[size];
        int front = size - 1;
        int rear = 0;
        queue[rear] = pRoot;
        TreeNode *current;
        int count1 = 1;
        int count2 = 0;
        vector<int> tmp;
        while ( rear != front ) {
            tmp.clear();
            while ( count1 > 0 ) {
                front = ( front + 1 ) % size;
                current = queue[front];
                count1--;
                tmp.push_back ( current->val );
                if ( current->left ) {
                    count2++;
                    rear = ( rear + 1 ) % size;
                    queue[rear] = current->left;
                }
                if ( current->right ) {
                    count2++;
                    rear = ( rear + 1 ) % size;
                    queue[rear] = current->right;
                }
            }
            if ( !tmp.empty() )
                result.push_back ( tmp );
            tmp.clear();
            while ( count2 > 0 ) {
                front = ( front + 1 ) % size;
                current = queue[front];
                count2--;
                tmp.push_back ( current->val );
                if ( current->left ) {
                    count1++;
                    rear = ( rear + 1 ) % size;
                    queue[rear] = current->left;
                }
                if ( current->right ) {
                    count1++;
                    rear = ( rear + 1 ) % size;
                    queue[rear] = current->right;
                }
            }
            if ( !tmp.empty() )
                result.push_back ( tmp );
        }
        return result;
    }
};

int main() {
    TreeNode *root1 = new TreeNode ( 8 );
    TreeNode *tmp1 = new TreeNode ( 4 );
    root1->right = tmp1;
    tmp1 = new TreeNode ( 7 );
    root1->left = tmp1;
    TreeNode *tmp2 = new TreeNode ( 9 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 2 );
    tmp1->right = tmp2;
    tmp1 = root1->right;
    tmp2 = new TreeNode ( 1 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 5 );
    tmp1->right = tmp2;

    Solution_3b s;
    vector< vector<int> > result = s.Print ( root1 );

    for ( vector< vector<int> >::iterator iter1 = result.begin(); iter1 < result.end(); iter1++ ) {
        for ( vector<int>::iterator iter2 = ( *iter1 ).begin(); iter2 < ( *iter1 ).end(); iter2++ )
            cout << *iter2 << ' ';
        cout << '\n';
    }
    return 0;
}
