#include <iostream>
#include <vector>
using namespace std;

class Solution_29 {
public:
    vector<int> FindNumbersWithSum ( vector<int> array, int sum ) {
        vector<int> result;
        if ( array.empty() )
            return result;
        int begin = 0;
        int end = array.size() - 1;
        while ( begin < end ) {
            if ( array[begin] + array[end] == sum ) {
                result.push_back ( array[begin] );
                result.push_back ( array[end] );
                return result;
            } else if ( array[begin] + array[end] > sum )
                end--;
            else
                begin++;
        }
        return result;
    }
};

int main() {
    int data[9] = {1, 2, 3, 5, 9, 12, 14, 20, 21};
    vector<int> array ( data, data + 9 );
    Solution_29 s;
    vector<int> result = s.FindNumbersWithSum ( array, 4 );
    cout << result[0] << " " << result[1];
    return 0;
}
