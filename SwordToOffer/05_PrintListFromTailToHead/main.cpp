#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode ( int x ) :
        val ( x ), next ( NULL ) {
    }
};

class Solution_05 {
public:
    vector<int> printListFromTailToHead ( ListNode *head ) {
        vector<int> list;
        getNodeVal ( head, list );
        return list;
    }

    void getNodeVal ( ListNode *head, vector<int> &list ) {
        if ( !head )
            return;
        else {
            getNodeVal ( head->next, list );
            list.push_back ( head->val );
        }
    }
};

int main() {
    return 0;
}
