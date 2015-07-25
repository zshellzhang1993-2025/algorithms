#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode ( int x ) :
        val ( x ), next ( NULL ) {
    }
};

class Solution_e {
public:
    ListNode* ReverseList ( ListNode *pHead ) {
        if ( !pHead )
            return NULL;
        ListNode *pCurrent = pHead->next;
        ListNode *pFormer = pHead;
        ListNode *pNext;
        pHead->next = NULL;
        while ( pCurrent ) {
            pNext = pCurrent->next;
            pCurrent->next = pFormer;
            pFormer = pCurrent;
            pCurrent = pNext;
        }
        pHead = pFormer;
        while ( pFormer ) {
            cout << pFormer->val;
            pFormer = pFormer->next;
        }
        return pHead;
    }
};

int main() {
    ListNode *pHead = new ListNode ( 0 );
    ListNode *pCurrent = pHead;
    ListNode *pNode;
    for ( int i = 1; i < 10; i++ ) {
        pNode = new ListNode ( i );
        pCurrent->next = pNode;
        pCurrent = pNode;
    }
    pNode->next = NULL;
    Solution_e s;
    pHead = s.ReverseList ( pHead );
    return 0;
}
