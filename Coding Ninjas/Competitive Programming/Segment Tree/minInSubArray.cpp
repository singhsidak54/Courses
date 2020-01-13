#include<bits/stdc++.h>
using namespace std;

/*
Minimum In SubArray

Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.

Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.

Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].

Contraints:
1=N,Q,y=10^5
1=l,r,x=N

*/

class Query {
    public:
        char a;
        int  b,c;
};

void buildTree(int *a,int start,int end,int *tree,int treeNode)
{
    if(start == end)
    {
        tree[treeNode] = a[start];
        return;
    }
    
    int mid = (start + end)/2;
    buildTree(a,start,mid,tree,2*treeNode);
    buildTree(a,mid+1,end,tree,2*treeNode + 1);
    
    tree[treeNode] = min(tree[2 * treeNode],tree[2 * treeNode + 1]);
}

void update(int *a,int start,int end,int *tree,int treeNode,int idx,int value)
{
    if(start == end)
    {
        a[idx] = value;
        tree[treeNode] = value;
        return;
    }
    
    int mid = (start + end)/2;
    if(idx > mid)
    {
        update(a,mid+1,end,tree,2*treeNode + 1,idx,value);
    }
    else
    {
        update(a,start,mid,tree,2*treeNode,idx,value);
    }
    
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode + 1]);
}

int query(int *tree,int s,int e,int treeNode,int l,int r)
{
    if(s > r || e < l)
        return INT_MAX;
    
    else if(s >= l && e <= r)
        return tree[treeNode];
    
    else
    {
        int mid = (s + e)/2;
        int ans1 = query(tree,s,mid,2*treeNode,l,r);
        int ans2 = query(tree,mid+1,e,2*treeNode+1,l,r);
        
		return min(ans1,ans2);
    }
}

int main() {
	
    int n,q;
    cin>>n>>q;
        
    int arr[n];
    Query queries[q];
    
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    for(int i=0; i<q; i++)
        cin>>queries[i].a>>queries[i].b>>queries[i].c;
    
    int tree[4*n];
    buildTree(arr,0,n-1,tree,1);
    
    int t = 0;
    while(t < q)
    {
        if(queries[t].a == 'q')
            cout<<query(tree,0,n-1,1,queries[t].b - 1,queries[t].c - 1)<<endl;
        else
            update(arr,0,n-1,tree,1,queries[t].b - 1,queries[t].c);
        
        t++;
    }
    
    return 0;
}
