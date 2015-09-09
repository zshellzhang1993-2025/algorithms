class Solution {
public:
    string ReverseSentence ( string str ) {
        if ( str == "" )
            return "";
        unsigned int begin = 0;
        unsigned int end = str.size() - 1;
        char tmp = '\0';
        while ( begin < end ) {
            tmp = str[begin];
            str[begin++] = str[end];
            str[end--] = tmp;
        }
        begin = 0;
        end = 0;
        unsigned int i = 0;
        unsigned int j = 0;
        while ( begin < str.size() && str[begin] == ' ' )
            begin++;
        while ( begin < str.size() && end < str.size() ) {
            while ( end < str.size() && end + 1 < str.size() && str[end + 1] != ' ' )
                end++;
            i = begin;
            j = end;
            while ( i < j ) {
                tmp = str[i];
                str[i++] = str[j];
                str[j--] = tmp;
            }
            begin = end + 1;
            while ( begin < str.size() && str[begin] == ' ' )
                begin++;
            end = begin;
        }
        return str;
    }
};
