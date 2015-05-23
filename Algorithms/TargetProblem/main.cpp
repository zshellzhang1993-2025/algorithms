#include <iostream>
using namespace std;

/**
 * @brief give you the count of people and the total score we want to get,
 * 		  return how many ways to fit the given condition;
 * @param count
 * @param score
 * @return int
 */

int findCount ( int amount, int score ) {
	if ( score > amount * 10 )
		return 0;
	if ( amount == 1 && score >= 0 && score <= 10 )
		return 1;
	int count = 0;
	for ( int i = 0; i <= 10; i++ ) {
		if ( score >= i )
			count += findCount ( amount - 1, score - i );
		else
			break;
	}
	return count;
}

int main() {
	cout << findCount ( 10, 90 );
	return 0;
}
