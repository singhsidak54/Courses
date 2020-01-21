/*
Power

Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.

Input format :
Two integers x and n (separated by space)

Output Format :
x^n (i.e. x raise to the power n)

Constraints :
1 <= x <= 30
0 <= n <= 30
*/

int power(int x, int n) {
    
    if(n == 0)
        return 1;
    
    if(n == 1)
        return x;
    
    int smallAns = power(x,n/2);
    
    if(n % 2 == 0)
        return smallAns * smallAns;
    
    else 
        return x * smallAns * smallAns;
}

