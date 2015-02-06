#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> twoSum ( vector<int> &numbers, int target ) {
	// initialize
	int begin = numbers[0];
	int end = numbers[0];
	for ( unsigned int i = 1; i < numbers.size (); i++ ) {
	    if ( begin > numbers[i] )
			begin = numbers[i];
	    if ( end < numbers[i] )
			end = numbers[i];
	}
	bool **table = new bool *[end - begin + 1];
	for ( int i = 0; i < end - begin + 1; i++ )
	    table[i] = new bool[2];
	for ( int i = 0; i < end - begin + 1; i++ ) {
	    table[i][0] = table[i][1] = false;
	}
	for ( unsigned int i = 1; i < numbers.size (); i++ ) {
	    if ( table[numbers[i] - begin][0] == false )
			table[numbers[i] - begin][0] = true;
	    else
			table[numbers[i] - begin][1] = true;
	}

	// working & finding
	int num1 = 0;
	int num2 = 0;
	bool flag = false;
	for ( unsigned int i = 0; i < numbers.size (); i++ ) {
	    num2 = target - numbers[i];
	    if ( num2 > end || num2 < 0 )
			continue;
	    else if ( num2 * 2 == target ) {
			if ( table[num2 - begin][0] == true && table[num2 - begin][1] == true ) {
				num1 = num2;
				flag = true;
			}
			break;
	    } else if ( table[num2 - begin][0] ) {
			num1 = numbers[i];
			flag = true;
			break;
	    }
	}
	for ( int i = 0; i < end - begin + 1; i++ )
	    delete[] table[i];
	delete[] table;
	if ( flag == false ) {
	    vector<int> none;
	    return none;
	}

	// data processing & output
	int index1 = 0;
	int index2 = 0;
	if ( num1 != num2 ) {
	    for ( unsigned int i = 0; i < numbers.size (); i++ ) {
			if ( num1 == numbers[i] ) {
				index1 = i;
				break;
			}
	    }
	    for ( unsigned int i = 0; i < numbers.size (); i++ ) {
			if ( num2 == numbers[i] ) {
				index2 = i;
				break;
			}
	    }
	} else {
	    for ( unsigned int i = 0; i < numbers.size (); i++ ) {
			if ( num1 == numbers[i] ) {
				index1 = i;
				break;
			}
	    }
	    for ( unsigned int i = index1 + 1; i < numbers.size (); i++ ) {
			if ( num2 == numbers[i] ) {
				index2 = i;
				break;
			}
	    }
	}
	vector<int> answer;
	if ( index1 < index2 ) {
	    answer.push_back ( index1 );
	    answer.push_back ( index2 );
	} else {
	    answer.push_back ( index2 );
	    answer.push_back ( index1 );
	}
	return answer;
    }
};

int main () {
    vector<int> numbers;
    numbers.push_back ( 5 );
    numbers.push_back ( 75 );
    numbers.push_back ( 25 );
    numbers.push_back ( 15 );
    Solution s;
    vector<int> answer = s.twoSum ( numbers, 50 );
    if ( answer.size () != 0 )
		cout << answer[0] << " " << answer[1];
    else
		cout << "no pairs has been found!";
    return 0;
}