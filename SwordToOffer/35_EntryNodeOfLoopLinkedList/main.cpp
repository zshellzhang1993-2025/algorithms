#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode ( int x ) :
        val ( x ), next ( NULL ) {
    }
};

class Solution_35 {
public:
    ListNode* EntryNodeOfLoop ( ListNode* pHead ) {
        if ( pHead == NULL )
            return NULL;
        ListNode *slow = pHead->next;
        ListNode *quick = pHead->next;
        if ( quick )
            quick = quick->next;
        else
            return NULL;
        while ( quick != NULL && slow != quick ) {
            slow = slow->next;
            if ( ( quick = quick->next ) != slow )
                quick = quick->next;
            else
                break;
        }
        if ( quick == NULL )
            return NULL;
        slow = pHead;
        while ( slow != quick ) {
            slow = slow->next;
            quick = quick->next;
        }
        return slow;
    }
};

int main() {
    return 0;
}
