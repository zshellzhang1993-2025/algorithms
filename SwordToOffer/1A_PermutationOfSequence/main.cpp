#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution_1a {
public:
    vector<string> Permutation ( string str ) {
        if ( str == "" )
            return result;
        map<char, int> table;
        for ( unsigned int i = 0; i < str.size(); i++ )
            table[str[i]]++;
        Permutation ( table, "" );
        return result;
    }

private:
    void Permutation ( map<char, int> table , string str ) {
        bool isterminal = true;
        for ( map<char, int>::iterator iter = table.begin(); iter != table.end(); iter++ ) {
            if ( iter->second > 0 ) {
                iter->second--;
                Permutation ( table , str + iter->first );
                iter->second++;
                isterminal = false;
            }
        }
        if ( isterminal )
            result.push_back ( str );
    }

private:
    vector<string> result;
};

int main () {
    Solution_1a s;
    vector<string> result = s.Permutation ( "aba" );
    for ( vector<string>::iterator iter = result.begin(); iter < result.end(); iter++ )
        cout << *iter << '\n';
    return 0;
}
