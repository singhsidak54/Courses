#include <cmath>

/*
Number Of Balanced BTs

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.

Input Format :
Integer h

Output Format :
Count % 10^9 + 7

Input Constraints :
1 <= h <= 40
*/

int balancedBTs(int h) {
    
    long m = pow(10,9) + 7;
    
    int ans[h+1];
    ans[0] = 1;
    ans[1] = 1;
    
    for(int i=2; i<=h; i++)
    {
        int a = ans[i-1];
        int b = ans[i-2];
        
        long one = (long) a * a;
        long two = (long) 2 * a * b;
        
        ans[i] = ((one % m) + (two % m)) % m;
    }
    
    return ans[h];
}

