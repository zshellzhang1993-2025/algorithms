#include <iostream>

void merge(int a[], int start1, int start2, int end)
{
    int *temp = new int[end - start1 + 1];
    int i = 0;
    int s1 = start1, s2 = start2, e1 = start2 - 1, e2 = end;
    while(s1 < e1 && s2 < e2) {
	if(a[s1] < a[s2])
	    temp[i++] = a[s1++];
	else
	    temp[i++] = a[s2++];
    }
    while(s1 < e1)
	temp[i++] = a[s1++];
    while(s2 < e2)
	temp[i++] = a[s2++];
    for(int i = start1; i < end; i++)
	a[i] = temp[i];
    delete temp;
}

void mergeSort(int a[], int start1, int end2)
{
    if(end2 - start1 == 0)
		return;
    else {
		int end1 = (end2 - start1) / 2 + start1;
		int start2 = end1 + 1;
		mergeSort(a, start1, end1);
		mergeSort(a, start2, end2);
		merge(a, start1, start2, end2);
    }
}

int main()
{

    return 0;
}