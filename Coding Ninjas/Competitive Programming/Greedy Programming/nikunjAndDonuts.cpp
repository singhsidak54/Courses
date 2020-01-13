#include<bits/stdc++.h>
using namespace std;

/*
Nikunj and Donuts

Nikunj loves donuts, but he also likes to stay fit. He eats n donuts in one sitting, and each donut has a calorie count, ci. After eating a donut with k calories, he must walk at least 2^j x k(where j is the number donuts he has already eaten) miles to maintain his weight.
Given the individual calorie counts for each of the n donuts, find and print a long integer denoting the minimum number of miles Nikunj must walk to maintain his weight. Note that he can eat the donuts in any order.

Input
The first line contains an integer, n, denoting the number of donuts. 
The second line contains n space-separated integers describing the respective calorie counts of each donut I, i.e ci.

Output
Print a long integer denoting the minimum number of miles Nikunj must walk to maintain his weight.

Constraints
1 = n = 40
1 = ci = 1000

*/

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
    
    for(int j=low; j<high; j++)
    {
        if(a[j] > pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    
    swap(&a[i + 1],&a[high]);
    return i+1;
}

void quicksort(int *a, int low, int high)
{
    if(low < high)
    {
        int pi = partition(a,low,high);
        
        quicksort(a,low,pi - 1);
        quicksort(a,pi + 1,high);
    }
}

long totalCalorieCount(int *a, int n)
{
    quicksort(a,0,n-1);
    
    long mul_factor = 1;
    long ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += a[i] * mul_factor;
        mul_factor *= 2;
    }
    
    return ans;
}

int main()
{
    int n;
    cin>>n;
    
    int *a = new int[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    cout<<totalCalorieCount(a,n);
    
    return 0;
}
