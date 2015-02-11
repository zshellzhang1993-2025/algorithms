#include <iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring ( string s ) {
		int max = 0;
		int idx = -1;		//note down the last index of the current substring
		int locs[128];
		for ( int i = 0; i < 128; i++ )
			locs[i] = -1;
		for ( unsigned int i = 0; i < s.size(); i++ ) {
			if ( locs[s[i]] > idx )
				idx = locs[s[i]];
			if ( i - idx > max ) {
				max = i - idx;
			}
			locs[s[i]] = i;
		}
		return max;
	}
};

int main() {
	string s = "I wish my code will be accepted in the LeetCode";
	Solution demo;
	cout << demo.lengthOfLongestSubstring ( s );
	return 0;
}
