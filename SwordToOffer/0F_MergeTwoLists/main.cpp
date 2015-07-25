#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode ( int x ) :
        val ( x ), next ( NULL ) {
    }
};
class Solution_f {
public:
    ListNode* Merge ( ListNode* pHead1, ListNode* pHead2 ) {
        if ( !pHead1 )
            return pHead2;
        if ( !pHead2 )
            return pHead1;
        ListNode *tmp = new ListNode ( 0 );
        ListNode *pHead = tmp;
        while ( pHead1 && pHead2 ) {
            if ( pHead1->val < pHead2->val ) {
                tmp->next = pHead1;
                tmp = pHead1;
                pHead1 = pHead1->next;
            } else {
                tmp->next = pHead2;
                tmp = pHead2;
                pHead2 = pHead2->next;
            }
        }
        if ( pHead1 )
            tmp->next = pHead1;
        else if ( pHead2 )
            tmp->next = pHead2;
        tmp = pHead->next;
        delete pHead;
        return tmp;
    }
};

int main() {
    return 0;
}
