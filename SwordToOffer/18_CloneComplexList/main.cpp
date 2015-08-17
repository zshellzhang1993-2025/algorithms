#include <iostream>
#include <map>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode ( int x ) :
        label ( x ), next ( NULL ), random ( NULL ) {
    }
};

class Solution_18 {
public:
    RandomListNode* Clone ( RandomListNode* pHead ) {
        if ( !pHead )
            return NULL;
        map<RandomListNode*, RandomListNode*> table;
        RandomListNode *pCloneHead = new RandomListNode ( pHead->label );
        RandomListNode *pCurrent = pHead->next;
        RandomListNode *pCloneCurrent = pCloneHead;
        table.insert ( pair<RandomListNode*, RandomListNode*> ( pHead, pCloneHead ) );
        RandomListNode *pCloneNext;
        while ( pCurrent ) {
            pCloneNext = new RandomListNode ( pCurrent->label );
            pCloneCurrent->next = pCloneNext;
            table.insert ( pair<RandomListNode*, RandomListNode*> ( pCurrent, pCloneNext ) );
            pCloneCurrent = pCloneNext;
            pCurrent = pCurrent->next;
        }
        pCloneCurrent->next = NULL;
        RandomListNode *randomNext;
        for ( map<RandomListNode*, RandomListNode*>::iterator iter = table.begin();
                iter != table.end(); iter++ ) {
            randomNext = iter->first->random;
            if ( randomNext )
                iter->second->random = table.find ( randomNext )->second;
            else
                iter->second->random = NULL;
        }
        return pCloneHead;
    }
};

int main() {
    return 0;
}
