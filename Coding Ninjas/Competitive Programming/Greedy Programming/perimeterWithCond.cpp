#include<bits/stdc++.h>
using namespace std;

/*
Perimeter with conditions

Aahad gives an array of integers and asks Harshit to find which three elements form a triangle (non-degenerate). The task seems easy to Harshit.
So, Aahad adds some conditions to this task -
1. Find the triangle with maximum perimeter
2. If there are two or more combinations with same value of maximum perimeter, then find the one with the longest side.
3.If there are more than one combinations which satisfy all the above conditions the find with maximum longest minimum side.

Input Format
The First line contains no of elements of array: N
Each T lines contains N space-separated integers: A [i]

Output Format
The output contains three space-separated elements that denote the length of the sides of triangle. If no such triangle is possible, then print -1.

Constraints
1 =< N <= 10^5 
1 <= A[i] <= 10^9
Time Limit: 1 second
*/


bool compare(int a, int b)
{
    return a < b;
}

void maxPerimeter(int *arr, int n)
{
    int lIndex = n - 1;
    
    while(lIndex > 2)
    {
        int a = arr[lIndex - 2];
        int b = arr[lIndex - 1];
        int c = arr[lIndex];
        
        if(a + b <= c)
            lIndex--;
        else
        {
            cout<<a<<" "<<b<<" "<<c<<endl;
            return;
        }
    }
    
    cout<<-1;
}
int main() {

	int n;
    cin>>n;
    int a[n];
    
    for(int i=0;  i<n;  i++)
        cin>>a[i];
    
    sort(a,a+n,compare);
    
    maxPerimeter(a,n);
}
