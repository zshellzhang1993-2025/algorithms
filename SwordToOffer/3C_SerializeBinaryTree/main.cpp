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

const int maxsize = 100;

class Solution_3c {
public:
    char* Serialize ( TreeNode *root ) {
        if ( !root ) {
            sequence[0] = '#';
            sequence[1] = '\0';
            return sequence;
        }
        TreeNode* stack[maxsize];
        int top = 0;
        stack[0] = root;
        TreeNode *node;
        int index = 0;
        while ( top != -1 ) {
            node = stack[top--];
            if ( !node ) {
                sequence[index++] = '#';
                continue;
            }
            writeValue ( node->val, index );
            if ( node->right )
                stack[++top] = node->right;
            else
                stack[++top] = NULL;
            if ( node->left )
                stack[++top] = node->left;
            else
                sequence[index++] = '#';
        }
        sequence[index++] = '\0';
        return sequence;
    }

    TreeNode* Deserialize ( char *str ) {
        TreeNode* stack[maxsize];
        int top = 0;
        int index = 0;
        TreeNode *root;
        if ( str[index] != '#' )
            root = new TreeNode ( readValue ( index ) );
        else
            return NULL;
        TreeNode *node1 = root;
        stack[0] = node1;
        TreeNode *node2;
        while ( top != -1 ) {
            node1 = stack[top];
            if ( !node1->left ) {
                if ( str[index] != '#' ) {
                    node2 = new TreeNode ( readValue ( index ) );
                    node1->left = node2;
                    stack[++top] = node2;
                } else {
                    index++;
                    if ( str[index] != '#' ) {
                        node2 = new TreeNode ( readValue ( index ) );
                        node1->right = node2;
                        stack[top] = node2;
                    } else {
                        top--;
                        index++;
                    }
                }
            } else {
                if ( str[index] != '#' ) {
                    node2 = new TreeNode ( readValue ( index ) );
                    node1->right = node2;
                    stack[top] = node2;
                } else {
                    top--;
                    index++;
                }
            }
        }
        return root;
    }

private:
    int readValue ( int& index ) {
        int val = 0;
        bool isNegative = false;
        char ch = sequence[index++];
        if ( ch == '-' ) {
            isNegative = true;
            ch = sequence[index++];
        }
        while ( ch != ' ' ) {
            val = val * 10;
            val = val + ( int ) ch - 48;
            ch = sequence[index++];
        }
        if ( isNegative )
            val = -val;
        return val;
    }

    void writeValue ( int val, int& index ) {
        if ( val < 0 ) {
            sequence[index++] = '-';
            val = -val;
        }
        int stack[maxsize];
        int top = -1;
        while ( val ) {
            stack[++top] = val % 10;
            val = val / 10;
        }
        char ch = '\0';
        while ( top != -1 ) {
            ch = stack[top--] + 48;
            sequence[index++] = ch;
        }
        sequence[index++] = ' ';
    }

private:
    char sequence[maxsize];
};

int main() {
    TreeNode *root1 = new TreeNode ( -8 );
    TreeNode *tmp1 = new TreeNode ( 433 );
    root1->right = tmp1;
    tmp1 = new TreeNode ( 7 );
    root1->left = tmp1;
    TreeNode *tmp2 = new TreeNode ( -59 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( 2 );
    tmp1->right = tmp2;
    tmp1 = root1->right;
    tmp2 = new TreeNode ( 11 );
    tmp1->left = tmp2;
    tmp2 = new TreeNode ( -5 );
    tmp1->right = tmp2;

    Solution_3c s;
    char *str = s.Serialize ( root1 );
    cout << str << endl;
    root1 = s.Deserialize ( str );
    str = s.Serialize ( root1 );
    cout << str;
    return 0;
}
