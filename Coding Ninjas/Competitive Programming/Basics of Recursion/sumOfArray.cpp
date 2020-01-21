/*
Sum of Array

Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.

Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format :
Sum

Constraints :
1 <= N <= 10^3
*/

int sum(int a[], int n) {
    if(n == 0)
        return 0;
    
    if(n == 1)
        return a[0];
    
    else 
        return a[0] + sum(a + 1, n - 1);
}

