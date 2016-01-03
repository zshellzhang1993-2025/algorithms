#include <iostream>
#include <vector>
using namespace std;

const int maxsize = 10;

struct Record {
    int value;
    int index;
    Record() {}
    Record ( int v, int i ) : value ( v ), index ( i ) {}
};

class Solution_3f {
public:
    Solution_3f() {
        front1 = rear1 = 0;
        front2 = rear2 = 0;
    }

    vector<int> maxInWindows ( const vector<int>& num, unsigned int size ) {
        if ( num.empty() || size == 0 || num.size() < size )
            return result;
        unsigned int index = 0;
        for ( ; index < size; index++ )
            enQueue ( num[index] );
        result.push_back ( getMax() );
        for ( index = size; index < num.size(); index++ ) {
            deQueue();
            enQueue ( num[index] );
            result.push_back ( getMax() );
        }
        return result;
    }

private:
    void enQueue ( int number ) {
        if ( ( rear1 + 1 ) % maxsize != front1 ) {
            queue[rear1] = number;
            rear1 = ( rear1 + 1 ) % maxsize;
        }
        if ( ( rear2 + 1 ) % maxsize != front2 ) {
            Record record ( number, rear1 - 1 );
            max_record[rear2] = record;
            rear2 = ( rear2 + 1 ) % maxsize;
        }
        while ( ( rear2 - 1 ) % maxsize != front2 ) {
            if ( number >= max_record[ ( rear2 - 2 ) % maxsize ].value ) {
                max_record[ ( rear2 - 2 ) % maxsize].value = number;
                max_record[ ( rear2 - 2 ) % maxsize].index = rear1 - 1;
                rear2 = ( rear2 - 1 ) % maxsize;
            } else
                break;
        }
    }

    void deQueue() {
        if ( max_record[front2].index == front1 )
            front2 = ( front2 + 1 ) % maxsize;
        if ( front1 != rear1 )
            front1 = ( front1 + 1 ) % maxsize;
    }

    int getMax() {
        return max_record[front2].value;
    }

private:
    int queue[maxsize];
    int front1;
    int rear1;
    Record max_record[maxsize];
    int front2;
    int rear2;
    vector<int> result;
};

int main() {
    int data[8] = {2, 3, 7, 2, 6, 5, 4, 1};
    vector<int> num ( data, data + 8 );
    Solution_3f s;
    vector<int> v = s.maxInWindows ( num, 3 );
    for ( int i = 0; i < v.size(); i++ )
        cout << v[i] << " ";
    return 0;
}
