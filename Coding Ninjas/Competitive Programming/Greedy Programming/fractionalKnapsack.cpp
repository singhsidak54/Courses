#include<bits/stdc++.h>
using namespace std;

/*
Fractional Knapsack

You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point of time. However, no more than 1 worker can be painting the house at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
Note: You can hire a previously hired worker without paying him again.

Input
The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", described in the statement.

Output
Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.

Constraints
1 = N, T, X, Y = 10^5
1 = D = 10^11


*/

class Item
{
    public:
        int ti,xi,yi;
};

bool compare(Item a, Item b)
{
    if(a.ti == b.ti)
    {
        if(a.yi == b.yi)
            return a.xi < b.xi;
        
        return a.yi > b.yi;
    }
    return a.ti < b.ti;
}

int minCost(Item a[],int n,long d)
{
    sort(a,a+n, compare);
    
    int maxTi = a[n-1].ti;
    int currTi = a[0].ti + 1;
    int cost = a[0].xi;
    d = d - a[0].yi;
    int currW = 0;
    for(int i=1; i<n && currTi <= maxTi && d > 0; i++)
    {
        
        if(a[i].ti > currTi)
        {
            d = d - a[currW].yi*(a[i].ti - currTi);
            currTi = a[i].ti;
        }
        
        if(d < 0)
        	break;
        
        if(a[i].ti <= currTi && a[i].yi > a[currW].yi)
        {
            cost += a[i].xi;
            currW = i;
        }
        
        d = d - a[currW].yi;
        currTi++;
    }
    
    return cost;
}
int main()
{
    int n;
    long d;
    
    cin>>n>>d;
    
    Item a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i].ti>>a[i].xi>>a[i].yi;
    }
    
    cout<<minCost(a,n,d);
    return 0;
}
