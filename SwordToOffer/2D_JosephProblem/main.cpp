#include <iostream>
using namespace std;

struct Node {
    int index;
    Node *next;
    Node ( int i ) : index ( i ) {}
};

class Solution_2d {
public:
    int LastRemaining_Solution ( unsigned int n, unsigned int m ) {
        if ( n < 1 || m < 1 )
            return -1;
        int remaining = n;
        Node *node = createJosephRing ( n );
        while ( remaining > 1 ) {
            for ( unsigned int i = 1; i < m; i++ )
                node = node->next;
            deleteSelf ( node );
            remaining--;
        }
        int last = node->index;
        delete node;
        return last;
    }

private:
    Node* createJosephRing ( int n ) {
        Node *head = new Node ( 0 );
        Node *node;
        Node *pre = head;
        for ( int i = n - 1; i > 0; i-- ) {
            node = new Node ( i );
            node->next = pre;
            pre = node;
        }
        head->next = node;
        return head;
    }

    void deleteSelf ( Node *node ) {
        Node *node2 = node->next;
        node->index = node2->index;
        node->next = node2->next;
        delete node2;
    }
};

int main() {
    Solution_2d s;
    cout << s.LastRemaining_Solution ( 5, 3 );
    return 0;
}
