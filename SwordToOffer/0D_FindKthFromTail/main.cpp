#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode ( int x ) :
        val ( x ), next ( NULL ) {
    }
};
class Solution_d {
public:
    ListNode* FindKthToTail ( ListNode* pListHead, unsigned int k ) {
        if ( k <= 0 )
            return NULL;
        if ( pListHead == NULL )
            return NULL;
        ListNode *fast = pListHead;
        for ( unsigned int i = 1; i < k; i++ ) {
            if ( fast != NULL )
                fast = fast->next;
            else
                break;
        }
        if ( fast == NULL )
            return NULL;
        ListNode *low = pListHead;
        fast = fast->next;
        while ( fast != NULL ) {
            low = low->next;
            fast = fast->next;
        }
        return low;
    }
};

int main () {
    return 0;
}
