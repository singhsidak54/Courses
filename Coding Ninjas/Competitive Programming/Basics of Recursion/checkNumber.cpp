/*
Check Number

Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
Do this recursively.

Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
true or false

Constraints :
1 <= N <= 10^3
*/

bool checkNumber(int a[], int size, int x) {

    if(size == 0)
        return false;
    
    if(a[0] == x)
        return true;
    
    else
        return checkNumber(a + 1, size - 1,x);
}
