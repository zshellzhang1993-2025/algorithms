#include <iostream>
using namespace std;

class Solution_2a {
public:
    string LeftRotateString ( string str, int n ) {
        if ( str == "" )
            return "";
        this->s = str;
        n = n % str.size();
        if ( n == 0 )
            return s;
        Rotate ( 0, n - 1 );
        Rotate ( n, str.size() - 1 );
        Rotate ( 0, str.size() - 1 );
        return s;
    }

private:
    void Rotate ( int begin, int end ) {
        char tmp = '\0';
        while ( begin < end ) {
            tmp = s[begin];
            s[begin++] = s[end];
            s[end--] = tmp;
        }
    }

private:
    string s;
};

int main() {
    Solution_30 s;
    cout << s.LeftRotateString ( "abcxyzdevC++", 13 );
    return 0;
}
