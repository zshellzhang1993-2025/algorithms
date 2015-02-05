#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> twoSum ( vector<int> &numbers, int target ) {
	// initialize
	int begin = numbers[0];
	int end = numbers[0];
	for ( int i = 1; i < numbers.size (); i++ ) {
	    if ( begin > numbers[i] )
		begin = numbers[i];
	    if ( end < numbers[i] )
		end = numbers[i];
	}
	bool *table = new bool[end - begin + 1];
	for ( int i = 0; i < end - begin + 1; i++ )
	    table[i] = false;
	for ( int i = 1; i < numbers.size (); i++ )
	    table[numbers[i] - begin] = true;

	// working
	int num1 = 0;
	int num2 = 0;
	for ( int i = 0; i < numbers.size (); i++ ) {
	    num2 = target - numbers[i];
		if(num2 > end)
			continue;
	    else if ( table[num2 - begin] ) {
		num1 = numbers[i];
		break;
	    }
	}
	delete[] table;

	// output
	int index1 = 0;
	int index2 = 0;
	if ( num1 != num2 ) {
	    for ( int i = 0; i < numbers.size (); i++ ) {
			if ( num1 == numbers[i] ) {
				index1 = i;
				break;
			}
	    }
	    for ( int i = 0; i < numbers.size (); i++ ) {
			if ( num2 == numbers[i] ) {
				index2 = i;
				break;
			}
	    }
	}
	else {
	    for ( int i = 0; i < numbers.size (); i++ ) {
			if ( num1 == numbers[i] ) {
				index1 = i;
				break;
			}
	    }
	    for ( int i = index1 + 1; i < numbers.size (); i++ ) {
			if ( num2 == numbers[i] ) {
				index2 = i;
				break;
			}
	    }
	}
	vector<int> answer;
	if ( index1 < index2 ) {
	    answer.push_back ( index1 + 1 );
	    answer.push_back ( index2 + 1 );
	} else {
	    answer.push_back ( index2 + 1 );
	    answer.push_back ( index1 + 1 );
	}
	return answer;
    }
};

int main () {
    vector<int> numbers;
    numbers.push_back ( 5 );
    numbers.push_back ( 75 );
    numbers.push_back ( 25 );
    //numbers.push_back ( 15 );
    Solution s;
    vector<int> answer = s.twoSum ( numbers, 100 );
    cout << answer[0] << answer[1] << endl;
    return 0;
}