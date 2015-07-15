#include <iostream>
#include <stack>
using namespace std;

class Solution_7 {
public:
    void push ( int node ) {
        int tmp = 0;
        if ( stack2.empty() )
            stack1.push ( node );
        else {
            while ( !stack2.empty() ) {
                tmp = stack2.top();
                stack1.push ( tmp );
                stack2.pop();
            }
            stack1.push ( node );
        }
    }

    int pop() {
        int tmp = 0;
        if ( stack1.empty() ) {
            tmp = stack2.top();
            stack2.pop();
        } else {
            while ( stack1.size() > 1 ) {
                tmp = stack1.top();
                stack2.push ( tmp );
                stack1.pop();
            }
            tmp = stack1.top();
            stack1.pop();
        }
        return tmp;
    }

private:
    stack<int> stack1;//stack for push
    stack<int> stack2;//stack for pop
};

int main () {
    Solution_7 s;
    s.push ( 1 );
    s.push ( 2 );
    s.push ( 3 );
    cout << s.pop() << " ";
    cout << s.pop() << " ";
    s.push ( 4 );
    cout << s.pop() << " ";
    s.push ( 5 );
    cout << s.pop() << " ";
    cout << s.pop() << " ";
    return 0;
}
