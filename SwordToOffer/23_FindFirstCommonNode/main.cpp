#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode ( int x ) :
        val ( x ), next ( NULL ) {
    }
};

class Solution_23 {
    public:
    ListNode* FindFirstCommonNode ( ListNode *pHead1, ListNode *pHead2 ) {
        if ( !pHead1 || !pHead2 )
            return NULL;
        int count = 0;
        ListNode *p = pHead1;
        while ( p ) {
            count++;
            p = p->next;
        }
        p = pHead2;
        while ( p ) {
            count--;
            p = p->next;
        }
        if ( count > 0 ) {
            while ( count ) {
                pHead1 = pHead1->next;
                count--;
            }
        } else if ( count < 0 ) {
            while ( count ) {
                pHead2 = pHead2->next;
                count++;
            }
        }
        while ( pHead1 ) {
            if ( pHead1 == pHead2 )
                return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
    }
};

int main () {
    return 0;
}
