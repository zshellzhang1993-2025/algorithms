#include <iostream>
using namespace std;

const int maxsize = 150;

class Solution_3e {
public:
    Solution_3e() {
        count1 = count2 = 0;
        order = true;
    }

    void Insert ( int num ) {
        if ( order ) {
            count1++;
            if ( num > heap2[1] ) {
                heap1[count1] = heap2[1];
                heap2[1] = num;
                filterDown ( 1, false );
            } else
                heap1[count1] = num;
            filterUp ( count1, true );
        } else {
            count2++;
            if ( num < heap1[1] ) {
                heap2[count2] = heap1[1];
                heap1[1] = num;
                filterDown ( 1, true );
            } else
                heap2[count2] = num;
            filterUp ( count2, false );
        }
        order = !order;
    }

    double GetMedian() {
        if ( count1 == 0 && count2 == 0 )
            return 0;
        if ( count1 < count2 )
            return ( double ) heap2[1];
        if ( count1 > count2 )
            return ( double ) heap1[1];
        return ( ( double ) heap1[1] + ( double ) heap2[1] ) / 2.00;
    }

private:
    void filterUp ( int index , bool isheap1 ) {
        if ( isheap1 ) {
            heap1[0] = heap1[index];
            while ( index > 1 ) {
                if ( heap1[index / 2] < heap1[0] ) {
                    heap1[index] = heap1[index / 2];
                    index = index / 2;
                } else
                    break;
            }
            heap1[index] = heap1[0];
        } else {
            heap2[0] = heap2[index];
            while ( index > 1 ) {
                if ( heap2[index / 2] > heap2[0] ) {
                    heap2[index] = heap2[index / 2];
                    index = index / 2;
                } else
                    break;
            }
            heap2[index] = heap2[0];
        }
    }

    void filterDown ( int index, bool isheap1 ) {
        if ( isheap1 ) {
            heap1[0] = heap1[index];
            for ( int i = index * 2; i <= count1 - 1; i *= 2 ) {
                if ( i < count1 - 1 && heap1[i] < heap1[i + 1] )
                    i++;
                if ( heap1[0] < heap1[i] ) {
                    heap1[index] = heap1[i];
                    index = i;
                } else
                    break;
            }
            heap1[index] = heap1[0];
        } else {
            heap2[0] = heap2[index];
            for ( int i = index * 2; i <= count2 - 1; i *= 2 ) {
                if ( i < count2 - 1 && heap2[i] < heap2[i + 1] )
                    i++;
                if ( heap2[0] < heap2[i] ) {
                    heap2[index] = heap2[i];
                    index = i;
                } else
                    break;
            }
            heap2[index] = heap2[0];
        }
    }

private:
    bool order;
    int count1;
    int count2;
    int heap1[maxsize];
    int heap2[maxsize];
};

int main() {
    Solution_3e s;
    s.Insert ( 5 );
    cout << s.GetMedian() << " ";
    s.Insert ( 2 );
    cout << s.GetMedian() << " ";
    s.Insert ( 3 );
    cout << s.GetMedian() << " ";
    s.Insert ( 4 );
    cout << s.GetMedian() << " ";
    s.Insert ( 1 );
    cout << s.GetMedian() << " ";
    s.Insert ( 6 );
    cout << s.GetMedian() << " ";
    s.Insert ( 7 );
    cout << s.GetMedian() << " ";
    s.Insert ( 0 );
    cout << s.GetMedian() << " ";
    s.Insert ( 8 );
    cout << s.GetMedian() << " ";
    return 0;
}
