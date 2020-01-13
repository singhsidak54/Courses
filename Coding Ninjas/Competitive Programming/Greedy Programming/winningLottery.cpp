#include<bits/stdc++.h>
using namespace std;

/*
Winning Lottery

Harshit knows by his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.

Input Format
The Input line contains two space-separated integers: S,D

Output Format
The output contains a single integer denoting the winning lottery number

Constraints
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
*/

int lottery(int sum,int digits)
{
    if(digits == 1)
        return sum;
    
    int a[digits];
    
    a[0] = 1;
    sum = sum - 1;
    
    for(int i=digits-1;  i>=1; i--)
    {
        if(sum == 0)
            a[i] = 0;
        
        else if(sum >= 9)
        {
            sum = sum - 9;
            a[i] = 9;
        }
        else
        {
            a[i] = sum;
            sum = 0;
        }
        
    }
    
    for(int i=0; i<digits; i++)
    {
        cout<<a[i];
    }
}
int main() {

    int n,d;
    cin>>n>>d;
    
    lottery(n,d);
}
