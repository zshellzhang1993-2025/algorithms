#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode ( int x ) :
        val ( x ), next ( NULL ) {
    }
};

class Solution_37 {
public:
    ListNode* deleteDuplication ( ListNode* pHead ) {
        if ( !pHead )
            return NULL;
        ListNode *current = pHead;
        ListNode *ahead = current->next;
        ListNode *pre = NULL;
        int count = 1;
        while ( ahead ) {
            if ( ahead->val == current->val ) {
                ahead = ahead->next;
                count++;
            } else {
                if ( count > 1 ) {
                    deleteSequence ( current, ahead , count );
                    ahead = current->next;
                    count = 1;
                } else {
                    pre = current;
                    current = ahead;
                    ahead = current->next;
                }
            }
        }
        if ( count > 1 ) {
            while ( current ) {
                ahead = current->next;
                delete current;
                current = ahead;
            }
            if ( pre )
                pre->next = NULL;
            else
                return NULL;
        }
        return pHead;
    }

private:
    void deleteSequence ( ListNode *begin, ListNode *end , int count ) {
        ListNode *node = begin->next;
        ListNode *node2;
        begin->val = end->val;
        begin->next = end->next;
        for ( int i = 0; i < count - 1; i++ ) {
            node2 = node->next;
            delete node;
            node = node2;
        }
    }
};

int main() {
    ListNode *phead = new ListNode ( 1 );
    ListNode *node1 = phead;
    ListNode *node2;
    int value[7] = {  1, 2, 3, 3, 4, 5, 6};
    for ( int i = 0; i < 7; i++ ) {
        node2 = new ListNode ( value[i] );
        node1->next = node2;
        node1 = node2;
    }
    node1->next = NULL;
    Solution_37 s;
    phead = s.deleteDuplication ( phead );
    while ( phead ) {
        cout << phead->val << " ";
        phead = phead->next;
    }
    return 0;
}
