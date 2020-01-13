#include<bits/stdc++.h>
using namespace std;
/*
Activity Selection

You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed

Constraints
1 = N = 10^6
1 = ai, di = 10^9

*/

void swap(int *a, int *b,int *c,int *d)
{
    int t = *a;
    *a = *b;
    *b = t;
    
    t = *c;
    *c = *d;
    *d = t;
}

int partition(int *a, int low, int high, int* b)
{
    int pivot = a[high];
    
    int i = low - 1;
    for(int j=low; j<high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(&a[i],&a[j],&b[i],&b[j]);
        }
    }
    
    swap(&a[i + 1],&a[high],&b[i + 1], &b[high]);
    return (i + 1);
}

void quicksort(int *a,int low, int high, int *b)
{
    if(low < high)
    {
        int pi = partition(a,low,high,b);
        
        quicksort(a,low,pi - 1,b);
        quicksort(a,pi + 1,high,b);
    }
}

int activitySelection(int *start, int *end, int n)
{
    if(n == 0)
        return 0;
    
    quicksort(end,0,n-1,start);

    int count = 1;
    int curr_end = end[0];
    for(int i=1; i<n; i++)
    {
        if(start[i] >= curr_end)
        {
            count++;
            curr_end = end[i];
        }
    }
    
    return count;
}
int main()
{
    int n;
    cin>>n;
    
    int *start = new int[n];
    int *end = new int[n];
    
    for(int i=0; i<n; i++)
    {
        cin>>start[i]>>end[i];
    }
    
    cout<<activitySelection(start,end,n);
    return 0;
}
