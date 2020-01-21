#include<bits/stdc++.h>
using namespace std;

/*
Counting Even/Odd

Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.

Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.

Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9

Note:-
indexing starts from 1.
*/

class Query {
    public:
        int  a,b,c;
};

void buildTree(int *a,int start,int end,int *tree,int treeNode)
{
    if(start == end)
    {
        if(a[start] % 2 == 0)
            tree[treeNode] = 1;
        else
            tree[treeNode] = 0;
        return;
    }
    
    int mid = (start + end)/2;
    buildTree(a,start,mid,tree,2*treeNode);
    buildTree(a,mid+1,end,tree,2*treeNode + 1);
    
    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

void update(int *a,int start,int end,int *tree,int treeNode,int idx,int value)
{
    if(start == end)
    {
        a[idx] = value;
        if(a[idx] % 2 == 0)
            tree[treeNode] = 1;
        else
            tree[treeNode] = 0;
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
    
    tree[treeNode] = tree[2*treeNode] +  tree[2*treeNode + 1];
}

int query(int *tree,int s,int e,int treeNode,int l,int r)
{
    if(s > r || e < l)
        return 0;
    
    else if(s >= l && e <= r)
        return tree[treeNode];
    
    else
    {
        int mid = (s + e)/2;
        int ans1 = query(tree,s,mid,2*treeNode,l,r);
        int ans2 = query(tree,mid+1,e,2*treeNode+1,l,r);
        
		return ans1 + ans2;
    }
}

int main() {
	
    int n,q;
    cin>>n;
        
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cin>>q;
    Query queries[q];
    
    
    for(int i=0; i<q; i++)
        cin>>queries[i].a>>queries[i].b>>queries[i].c;
    
    int tree[4*n];
    buildTree(arr,0,n-1,tree,1);

    
    int t = 0;
    while(t < q)
    {
        if(queries[t].a == 1)
            cout<<query(tree,0,n-1,1,queries[t].b - 1,queries[t].c - 1)<<endl;
        else if(queries[t].a == 2)
        {
            int even = query(tree,0,n-1,1,queries[t].b - 1,queries[t].c - 1);
            int total = queries[t].c - queries[t].b + 1;
            cout<<total - even<<endl;
        }
        else
            update(arr,0,n-1,tree,1,queries[t].b - 1,queries[t].c);
        
        t++;
    }
    
    return 0;
}
