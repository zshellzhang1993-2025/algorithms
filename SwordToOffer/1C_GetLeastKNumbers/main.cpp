#include <iostream>
#include <vector>
using namespace std;

class Solution_1c {
public:
    vector<int> GetLeastNumbers_Solution ( vector<int> input, int k ) {
        this->k = k;
        if ( k < 1 || input.empty() || input.size() < k ) {
            vector<int> empty;
            return empty;
        }
        vector<int> frontK;
        vector<int>::iterator iter = input.begin();
        frontK.push_back ( -1 );
        for ( ; iter < input.begin() + k; iter++ )
            frontK.push_back ( *iter );
        makeHeap ( frontK );
        for ( ; iter < input.end(); iter++ ) {
            if ( *iter < data[1] ) {
                data[1] = *iter;
                filterData ( 1 );
            }
        }
        vector<int> result ( data + 1, data + k + 1 );
        delete data;
        return result;
    }

private:
    void makeHeap ( vector<int> array ) {
        this->data = new int[k + 1];
        for ( unsigned int i = 0; i < array.size(); i++ )
            data[i] = array[i];
        for ( int i = k / 2; i > 0; i-- )
            filterData ( i );
    }

    void filterData ( int index ) {
        int target = 0;
        int childindex = 0;
        while ( index * 2 < k + 1 ) {
            childindex = index * 2;
            target = data[index * 2];
            if ( index * 2 < k && target < data[index * 2 + 1] ) {
                target = data[index * 2 + 1];
                childindex = childindex + 1;
            }
            if ( data[index] < data[childindex] ) {
                data[childindex] = data[index];
                data[index] = target;
                index = childindex;
            } else
                break;
        }
    }

private:
    int *data;
    int k;
};

int main() {
    int data[20] = {3, 9, 56, 2, 33, 17, 99, 48, 189, 156, 65, 77, 123, 245, 634, 5, 709, 87, 1, 100};
    vector<int> input ( data, data + 20 );
    Solution_1c s;
    vector<int> result = s.GetLeastNumbers_Solution ( input, 21 );
    for ( vector<int>::iterator iter = result.begin(); iter < result.end(); iter++ )
        cout << *iter << " ";
    return 0;
}
