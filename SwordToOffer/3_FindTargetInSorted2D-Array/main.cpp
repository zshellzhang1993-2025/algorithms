#include <iostream>
#include <vector>
using namespace std;

/**
 * @class Solution3
 * @author Zhi
 * @date 14/07/2015
 * @file main.cpp
 * @brief give you a sorted 2D-array(every row is sorted and every column is sorted too),judge
 * if the target number given is in this array
 */

class Solution3 {
public:
    /**
     * @brief the first method is a divide-and-conquer algorithm
     * which implements the binary search in 2D-array
     */
    bool Find1 ( vector< vector<int> > array, int target ) {
        this->array = array;
        return find ( 0, 0, array.size() - 1, array[0].size() - 1, target );
    }

    /**
     * @brief the second method is a O(n) algorithm
     */
    bool Find2 ( vector< vector<int> > array, int target ) {
        int x = 0;
        int y = array.size();
        int upBound = 0;
        int leftBound = array[0].size();
        while ( x <= leftBound && y >= upBound ) {
            if ( target < array[x][y] )
                x++;
            else if ( target > array[x][y] )
                y--;
            else
                return true;
        }
        return false;
    }
private:
    bool find ( int beginX, int beginY, int endX, int endY, int target ) {

        // if the sub problem has only one element
        if ( beginX == endX && beginY == endY ) {
            if ( target == array[beginX][beginY] )
                return true;
            else
                return false;
        }

        //if the sub problem degenerates to a 1-dimension array
        else if ( beginX == endX || beginY == endY ) {
            /*if the array is a row vector*/
            if ( beginX == endX ) {
                int x = beginY;
                int y = endY;
                int mid = 0;
                while ( x <= y ) {
                    mid = ( x + y ) / 2;
                    if ( target < array[beginX][mid] )
                        y = mid - 1;
                    else if ( target > array[beginX][mid] )
                        x = mid + 1;
                    else
                        return true;
                }
                return false;
            }
            /*if the array is a column vector*/
            else {
                int x = beginX;
                int y = endX;
                int mid = 0;
                while ( x <= y ) {
                    mid = ( x + y ) / 2;
                    if ( target < array[mid][beginY] )
                        y = mid - 1;
                    else if ( target > array[mid][beginY] )
                        x = mid + 1;
                    else
                        return true;
                }
                return false;
            }
        }

        //if the sub problem still maintains the 2-dimension state
        else {
            int x1 = beginX;
            int y1 = beginY;
            int x2 = endX;
            int y2 = endY;
            int midx = 0;
            int midy = 0;
            //the following four vars marked the four bounds of two areas
            //in which the target number cound't exist
            int bottom = endX + 1;
            int right = endY + 1;
            int up = beginX - 1;
            int left = beginY - 1;
            while ( x2 >= x1 && y2 >= y1  ) {
                midx = ( x1 + x2 ) / 2;
                midy = ( y1 + y2 ) / 2;
                if ( target < array[midx][midy] ) {
                    x2 = midx - 1;
                    y2 = midy - 1;
                    bottom = midx;
                    right = midy;
                } else if ( target > array[midx][midy] ) {
                    x1 = midx + 1;
                    y1 = midy + 1;
                    up = midx;
                    left = midy;

                } else
                    return true;
            }
            if ( up < endX && right > beginY &&
                    find ( up + 1, beginY, endX, right - 1, target ) )
                return true;
            if ( left < endY && bottom > beginX &&
                    find ( beginX, left + 1, bottom - 1, endY, target ) )
                return true;
            else
                return false;
        }
    }
private:
    vector< vector<int> > array;
};

int main() {
    vector< vector<int> > array;
    int data[10][4] = {
        {1,  2,  3,   4},//0
        {2,  3,  5,   6},//1
        {3,  4,  7,   9},//2
        {5,  8,  9,   10},//3
        {7,  9,  11,  12},//4
        {8,  10, 12,  13},//5
        {9,  11, 14,  15},//6
        {10, 12, 15,  16},//7
        {11, 13, 17,  20},//8
        {13, 15, 20,  25},//9
    };
    for ( int i = 0; i < 10; i++ ) {
        vector<int> v ( data[i], data[i] + 4 );
        array.push_back ( v );
    }
    Solution3 s;
    cout << s.Find1 ( array, 13 );
    return 0;
}
