#include <iostream>
using namespace std;

const int maxsize = 120;

struct Step {
    int x;
    int y;
    Step ( int xs, int ys ) : x ( xs ), y ( ys ) {}
    Step() {}
};

int Count ( int *data, int *after, int needed, int left, int max ) {
    if ( needed == 0 )
        return 1;
    int count = 0;
    int index = 1;
    if ( needed <= *after + index ) {
        //needed is less than rested
        if ( needed < *after + index ) {
            while ( *data < max ) {
                data++;
                index++;
            }
            //do not select the current num
            count += Count ( data + index, after + index, needed, left - index, max );
            //select the current num
            count += Count ( data + index, after + index, needed - 1, left - index, * data );
        }
        //needed is equal to rested
        else {
            //if only one needed then any number larger than max will be ok
            if ( needed == 1 ) {
                for ( int i = 0; i < left; i++ ) {
                    if ( * ( data + i ) > max )
                        count++;
                }
            }
            //if more than one needed then the following numbers must be in growing order
            else {
                for ( int i = 0; i < left && needed > 0; i++ ) {
                    if ( * ( data + i ) > max ) {
                        max = * ( data + i );
                        needed--;
                    }
                }
                if ( needed == 0 )
                    count = 1;
            }
        }
    }
    return count;
}

int countIncreaseSubSequence ( int *path, int n, int k ) {
    int *after = new int[n];
    for ( int i = 0; i < n; i++ )
        after[i] = 0;
    for ( int i = n - 1; i >= 0; i++ )
        for ( int j = i; j < n; j++ ) {
            if ( path[i] < path[j] )
                after[i]++;
        }
    int count = Count ( path, after, k, n, 0 );
    delete after;
    return count;
}

int getCount ( int **data, int m, int n, int k ) {
    Step stack[maxsize];
    int top = 0;
    Step tmp ( 0, 0 );
    Step tmp2;
    stack[0] = tmp;
    int count = 0;
    int *path = new int[m + n - 1];
    path[0] = data[0][0];

    while ( top != -1 ) {
        tmp = stack[top--];
        if ( tmp.x == n - 1 && tmp.y == m - 1 )
            count += countIncreaseSubSequence ( path, m + n - 1, k );
        else {
            if ( tmp.x + 1 < n ) {
                tmp2.x = tmp.x + 1;
                tmp2.y = tmp.y;
                stack[++top] = tmp2;
            }
            if ( tmp.y + 1 < m ) {
                tmp.y = tmp.y + 1;
                path[top] = data[tmp.x][tmp.y];
            }
        }
    }
    return count;
}

int main () {
    int n, m, k;
    cin >> n >> m >> k;

    int **data = new int*[n];
    for ( int i = 0; i < n; i++ )
        data[i] = new int[m];
    for ( int i = 0; i < m; i++ )
        for ( int j = 0; j < n; j++ )
            cin >> data[i][j];

    if ( n >= k )
        cout << getCount ( data, m, n, k );

    for ( int i = 0; i < m; i++ )
        delete data[i];
    delete[] data;

    return 0;
}
