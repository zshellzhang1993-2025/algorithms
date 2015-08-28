#include <iostream>
#include <vector>
using namespace std;

class Solution_20 {
public:
    int GetUglyNumber_Solution ( int index ) {
        if ( index < 1 )
            return 0;
        if ( index == 1 )
            return 1;
        t2 = 0;
        t3 = 0;
        t5 = 0;
        count = 1;
        record.push_back ( 1 );
        while ( count < index ) {
            pushMin();
            count++;
        }
        return record[count - 1];
    }

private:
    void pushMin () {
        if ( record[t2] * 2 < record[t3] * 3 ) {
            if ( record[t2] * 2 < record[t5] * 5 ) {
                if ( record[t2] * 2 > record[count - 1] ) {
                    record.push_back ( record[t2] * 2 );
                    t2++;
                } else {
                    t2++;
                    pushMin();
                }
            } else {
                if ( record[t5] * 5 > record[count - 1] ) {
                    record.push_back ( record[t5] * 5 );
                    t5++;
                } else {
                    t5++;
                    pushMin();
                }
            }
        } else {
            if ( record[t3] * 3 > record[t5] * 5 ) {
                if ( record[t5] * 5 > record[count - 1] ) {
                    record.push_back ( record[t5] * 5 );
                    t5++;
                } else {
                    t5++;
                    pushMin();
                }
            } else {
                if ( record[t3] * 3 > record[count - 1] ) {
                    record.push_back ( record[t3] * 3 );
                    t3++;
                } else {
                    t3++;
                    pushMin();
                }
            }
        }
    }

private:
    int t2;
    int t3;
    int t5;
    int count;
    vector<int> record;
};

int main () {
    Solution_20 s;
    cout << s.GetUglyNumber_Solution ( 16 );
    return 0;
}
