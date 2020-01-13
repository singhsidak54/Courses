#include<bits/stdc++.h>
using namespace std;

/*
Maximum Pair Sum

You are given a sequence A[1], A[2], ..., A[N], ( 0 = A[i] = 10^8 , 2 = N = 10^5 ). There are two types of operations and they are defined as follows:

Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 = i = N, and x, 0 = x = 10^8.
This operation sets the value of A[i] to x.

Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 = x < y = N.
You must find i and j such that x = i, j = y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q = 10^5, representing the number of operations. Next Q lines contain the operations.

Output
Output the maximum sum mentioned above, in a separate line, for each Query.
 */
 
class Query {
    public:
        char a;
        int  b,c;
};

struct node  {
    int max;
    int smax;
};

void buildTree(int *a,int start,int end,node *tree,int treeNode)
{
    if(start == end)
    {
        tree[treeNode].max = a[start];
        tree[treeNode].smax = INT_MIN;
        return;
    }
    
    int mid = (start + end)/2;
    buildTree(a,start,mid,tree,2*treeNode);
    buildTree(a,mid+1,end,tree,2*treeNode + 1);
    
    node left = tree[2*treeNode];
    node right = tree[2*treeNode + 1];
    
    tree[treeNode].max = max(left.max,right.max);
    tree[treeNode].smax = min(max(left.max,right.smax),max(left.smax,right.max));
}

void update(int *a,int start,int end,node *tree,int treeNode,int idx,int value)
{
    if(start == end)
    {
        a[idx] = value;
        tree[treeNode].max = value;
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
    
    node left = tree[2*treeNode];
    node right = tree[2*treeNode + 1];
    
    tree[treeNode].max = max(left.max,right.max);
    tree[treeNode].smax = min(max(left.max,right.smax),max(left.smax,right.max));
}

node* query(node *tree,int s,int e,int treeNode,int l,int r)
{
    if(s > r || e < l)
    {
        node *nn = new node;
        nn->max = nn->smax == INT_MIN;
        
    }
        
    else if(s >= l && e <= r)
        return &tree[treeNode];
    
    else
    {
        int mid = (s + e)/2;
        node *ans1 = query(tree,s,mid,2*treeNode,l,r);
        node *ans2 = query(tree,mid+1,e,2*treeNode+1,l,r);
        
		node *nn = new node;
        
        nn->max = max(ans1->max,ans2->max);
        nn->smax = min(max(ans1->max,ans2->smax),max(ans1->smax,ans2->max));
        
        return nn;
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
    
    node tree[3*n];
    buildTree(arr,0,n-1,tree,1);
    
    	
    int t = 0;
    while(t < q)
    {
        if(queries[t].a == 'Q')
        {
            node *nn = query(tree,0,n-1,1,queries[t].b - 1,queries[t].c - 1);
            cout<<(nn->max + nn->smax)<<endl;
        }
            
        else
            update(arr,0,n-1,tree,1,queries[t].b - 1,queries[t].c);
        
        t++;
    }
    
    return 0;
}
