#include <iostream>

int maxSum(int v[], int n, int &left, int &right)
{
    int start = 0;  	// the start index of a probably sequence
    int now = 0;        // the current sequence which has been selected
    int max = 0;    	// the max sequence
    for(int i = 0; i < n; i++) {
		now += v[i];
		if(now > max) {
			max = now;
			if(now == v[i])
				start = i;
			left = start;
			right = i;
		} else if(now <= 0) {
			now = 0;
		} else if(now == v[i]) {
			start = i;
		}
    }
	return max;
}

int main()
{
	int left = 0;
	int right = 0;
	int v[10] = {5,15,-30,10,-5,40,10};
	int max = maxSum(v,7,left,right);
	std::cout << "maxSum=" << max << "\tfrom "
			  << left << " to " << right << std::endl;
    return 0;
}