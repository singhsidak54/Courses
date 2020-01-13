#include<bits/stdc++.h>
using namespace std;

/*
Maximum Sum In Subarray

You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| = 15007 , 1 = N = 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x = i = j = y }.
Given M queries, your program must output the results of these queries.

Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.

Output
Your program should output the results of the M queries, one 
query per line.

*/
struct node {
    int maxPrefixSum;
    int maxSuffixSum;
    int totalSum;
    int maxSubarraySum;
};

void  buildTree(int *a,int s,int e,node *tree,int treeNode)
{
    if(s == e)
    {
        tree[treeNode].maxPrefixSum = a[s];
        tree[treeNode].maxSuffixSum = a[s];
        tree[treeNode].totalSum = a[s];
        tree[treeNode].maxSubarraySum = a[s];
        return;
    }
    
    
    int mid = (s + e)/2;
    
    buildTree(a,s,mid,tree,2*treeNode);
    buildTree(a,mid+1,e,tree,2*treeNode + 1);
    
    node left = tree[2 * treeNode];
    node right = tree[2 * treeNode + 1];
    
    tree[treeNode].maxPrefixSum = max(left.maxPrefixSum,left.totalSum + right.maxPrefixSum);
    tree[treeNode].maxSuffixSum = max(right.maxSuffixSum,right.totalSum + left.maxSuffixSum);
    tree[treeNode].totalSum = left.totalSum + right.totalSum;
    tree[treeNode].maxSubarraySum = max(left.maxSubarraySum,max(right.maxSubarraySum,left.maxSuffixSum + right.maxPrefixSum));

}

node query(node *tree,int s,int e,int x,int y,int treeNode)
{
    if(x > e || y < s)
    {
        node nn;
        nn.maxPrefixSum = nn.maxSuffixSum = nn.totalSum = nn.maxSubarraySum = -15007;
        return nn;
    }
    
    else if(s >= x && e <= y)
        return tree[treeNode];
    
    else
    {
        int mid = (s + e)/2;
        node left = query(tree,s,mid,x,y,2 * treeNode);
        node right = query(tree,mid+1,e,x,y,2 * treeNode + 1);
        
        node nn;
        nn.maxPrefixSum = max(left.maxPrefixSum,left.totalSum + right.maxPrefixSum);
        nn.maxSuffixSum = max(right.maxSuffixSum,right.totalSum + left.maxSuffixSum);
        nn.totalSum = left.totalSum + right.totalSum;
        nn.maxSubarraySum = max(left.maxSubarraySum,max(right.maxSubarraySum,left.maxSuffixSum + right.maxPrefixSum));
    	
    	return nn;
    }
}

int main() {
    int  n;
    cin>>n;
    
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    node *tree = new node[4*n];
    buildTree(a,0,n-1,tree,1);
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        
        node ans = query(tree,0,n-1,x-1,y-1,1);
        cout<<ans.maxSubarraySum<<endl;
    }
	
}
