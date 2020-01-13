/*
Min. Absolute Difference In Array

Given an integer array A of size N, find and return the minimum absolute difference between any two elements in the array.
We define the absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|.

Input format :
Line 1 : Integer N, Array Size
Line 2 : Array elements (separated by space)

Output Format :
Minimum difference

Constraints :
1 <= N <= 10^6


*/

#include <climits>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;    
    
    for(int j=low; j<=high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    
    swap(&a[i + 1], &a[high]);
    
    return i+1;
}

void quicksort(int * a, int low, int high)
{
    if(low < high)
    {
        int pi = partition(a,low,high);
        
        quicksort(a,low,pi - 1);
        quicksort(a,pi + 1, high);
    }
}

int minAbsoluteDiff(int a[], int n) {
    
    quicksort(a,0,n-1);
    
    int min = INT_MAX;
    for(int i=0; i<n-1; i++)
    {
        int curr = a[i + 1] - a[i];
        if(curr < min)
            min = curr;
    }
    
    return min;
}

