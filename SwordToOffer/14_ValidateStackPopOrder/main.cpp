#include <iostream>
#include <vector>
using namespace std;

class Solution_14 {
public:
    bool IsPopOrder ( vector<int> pushV, vector<int> popV ) {
        if ( pushV.size() == 0 || popV.size() == 0 )
            return false;
        if ( pushV.size() != popV.size() )
            return false;
        int popindex = -1;
        int pushindex = -1;
        int stack[pushV.size()];
        int top = -1;
        int current = 0;
        int popsize = popV.size();
        int pushsize = pushV.size();
        while ( popindex < popsize ) {
            if ( popindex == popsize - 1 )
                return true;
            current = popV[++popindex];
            if ( top > -1 && stack[top] == current ) {
                top--;
                continue;
            }
            while ( ++pushindex < pushsize && pushV[pushindex] != current )
                stack[++top] = pushV[pushindex];
            if ( pushindex == pushV.size() )
                return false;
        }
    }
};

int main () {
    Solution_14 s;
    int push[5] = {1, 2, 3, 4, 5};
    int pop[5] = {4, 3, 5, 1, 2};
    vector<int> pushV ( push, push + 5 );
    vector<int> popV ( pop, pop + 5 );
    cout << s.IsPopOrder ( pushV, popV );
    return 0;
}
