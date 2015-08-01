#include <iostream>
using namespace std;

const int maxsize = 100;

class Solution_13 {
public:
    Solution_13() {
        pos = -1;
    }
    void push ( int value ) {
        if ( pos == maxsize - 1 )
            return;
        if ( pos == -1 ) {
            valueStack[++pos] = value;
            minStack[pos] = value;
            return;
        }
        if ( value < minStack[pos] )
            minStack[++pos] = value;
        else {
            int oldmin = minStack[pos++];
            minStack[pos] = oldmin;
        }
        valueStack[pos] = value;

    }
    void pop() {
        if ( pos == -1 )
            return;
        pos--;
    }
    int top() {
        if ( pos == -1 )
            return -1;
        return valueStack[pos];
    }
    int min() {
        if ( pos == -1 )
            return -1;
        return minStack[pos];
    }
private:
    int valueStack[maxsize];
    int minStack[maxsize];
    int pos;
};

int main () {
    Solution_13 s;
    s.push ( 7 );
    cout << s.min() << " ";
    s.push ( 5 );
    cout << s.min() << " ";
    s.push ( 6 );
    cout << s.min() << " ";
    s.push ( 1 );
    cout << s.min() << " ";
    s.pop();
    cout << s.min() << " ";
    s.pop();
    cout << s.min() << " ";
    s.pop();
    cout << s.min() << " ";
    return 0;
}
