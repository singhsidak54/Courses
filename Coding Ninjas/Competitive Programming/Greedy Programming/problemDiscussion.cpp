#include<bits/stdc++.h>
using namespace std;

/*
Problem discussion

Harshit gave Aahad an array of size N and asked to minimize the difference between the maximum value and minimum value by modifying the array under the condition that each array element either increase or decrease by k(only once).
It seems difficult for Aahad so he asked for your help

Input Format
The First line contains two space-separated integers: N,K
Next lines contain N space-separated integers denoting elements of the array

Output Format
The output contains a single integer denoting the minimum difference between maximum value and the minimum value in the array

Constraints
1 =< N <= 10^5 
1 <= Ai,K <= 10^9
*/

int maxDiff(int *a,int n,int k)
{
    sort(a,a+n);
    int diff = a[n - 1] - a[0];
    
    int big = a[n-1] - k;
    int small = a[0] + k;
    
    if(small > big)
    {
        int temp = small;
        small = big;
        big = temp;
    }
    
    for(int i=1; i<n-1; i++)
    {
        int subt = a[i] - k;
        int add = a[i] + k;
        
        if(subt >= small || add <= big)
            continue;
        else if(big - subt <= add - small)
            small = subt;
        else
            big = add;
    }
    
    return min(diff,big - small);
}

int main() {

    int n,k;
    cin>>n>>k;
    
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    cout<<maxDiff(a,n,k);
}
