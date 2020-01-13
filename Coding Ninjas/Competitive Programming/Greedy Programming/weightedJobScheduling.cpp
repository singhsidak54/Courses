#include<bits/stdc++.h>
using namespace std;

/*
Weighted Job Scheduling

You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 

Output
Output one integer, the maximum profit that can be achieved.

Constraints
1 = N = 10^6
1 = ai, di, p = 10^6

*/


class Job {
   public:
    int start,finish,profit;
    
};
bool compare(Job a, Job b)
{
    return a.finish < b.finish;
}

int maxProfit(Job *a, int n)
{
    sort(a,a+n,compare);
    int *dp = new int[n];
    
    dp[0] = a[0].profit;
    
    for(int i=1; i<n; i++)
    {
        dp[i] = a[i].profit;
        
        int lNConflict = -1;
        
        int high = i - 1;
        int low = 0;
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(a[mid].finish <= a[i].start)
            {
                lNConflict = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        if(lNConflict != -1)
            dp[i] += dp[lNConflict];
        
        dp[i] = max(dp[i],dp[i-1]);
    }
    
    int ans = dp[n-1];
    delete [] dp;
    return ans;
    
}
int main()
{
    int n;
    cin>>n;
    
    Job *a = new Job[n];
    
    for(int i=0; i<n; i++)
    {
        cin>>a[i].start>>a[i].finish>>a[i].profit;
    }
    
    cout<<maxProfit(a,n);
    return 0;
}
