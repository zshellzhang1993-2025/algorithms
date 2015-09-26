#include <iostream>
using namespace std;

const int maxsize = 100;

class Solution_34 {
public:
    Solution_34() {
        front = rear = 0;
    }

    //Insert one char from stringstream
    void Insert ( char ch ) {
        if ( table[ch] == 0 ) {
            table[ch] = 1;
            if ( ( rear + 1 ) % maxsize != front ) {
                queue[rear] = ch;
                rear = ( rear + 1 ) % maxsize;
            }
        } else
            table[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while ( rear != front && table[queue[front]] > 1 )
            front = ( front + 1 ) % maxsize;
        if ( rear == front )
            return '#';
        return queue[front];
    }

private:
    int table[128];
    char queue[maxsize];
    int front;
    int rear;
};

int main() {
    Solution_34 s;
    s.Insert ( 'g' );
    s.Insert ( 'o' );
    cout << s.FirstAppearingOnce() << " ";
    s.Insert ( 'o' );
    s.Insert ( 'g' );
    s.Insert ( 'l' );
    s.Insert ( 'e' );
    cout << s.FirstAppearingOnce();
    return 0;
}
