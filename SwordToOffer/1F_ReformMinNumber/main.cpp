#include <iostream>
#include <vector>
using namespace std;

class Solution_1f {
public:
    string PrintMinNumber ( vector<int> numbers ) {
        if ( numbers.empty() )
            return "";
        this->data = numbers;
        quickSort ( 0, data.size() - 1 );
        string result = "";
        for ( vector<int>::iterator iter = data.begin(); iter < data.end(); iter++ )
            result = result + int2Str ( *iter );
        return result;
    }

private:
    void quickSort ( int begin, int end ) {
        if ( begin < end ) {
            int pivot = Partition ( begin, end );
            quickSort ( begin, pivot - 1 );
            quickSort ( pivot + 1, end );
        }
    }

    int Partition ( int begin, int end ) {
        int i = begin;
        int j = end;
        while ( i < j ) {
            while ( i < j && smallerThan ( data[i], data[j] ) )
                j--;
            if ( i < j ) {
                data[i] ^= data[j];
                data[j] ^= data[i];
                data[i] ^= data[j];
                i++;
            }
            while ( i < j && smallerThan ( data[i], data[j] ) )
                i++;
            if ( i < j ) {
                data[i] ^= data[j];
                data[j] ^= data[i];
                data[i] ^= data[j];
                j--;
            }
        }
        return i;
    }

    bool smallerThan ( int n1, int n2 ) {
        string number1 = int2Str ( n1 );
        string number2 = int2Str ( n2 );
        string tmp = number1;
        number1 = number1 + number2;
        number2 = number2 + tmp;
        unsigned int i = -1;
        while ( ++i < number1.size() ) {
            if ( number1[i] < number2[i] )
                return true;
            if ( number1[i] > number2[i] )
                return false;
        }
        return false;
    }

    string int2Str ( int number ) {
        char t[256];
        sprintf ( t, "%d", number );
        string str = t;
        return str;
    }

private:
    vector<int> data;
};

int main () {
    Solution_1f s;
    const int size = 5;
    int data[size] = {411, 321, 3, 32, 189};
    vector<int> numbers ( data, data + size );
    string str = s.PrintMinNumber ( numbers );
    cout << str;
    return 0;
}
