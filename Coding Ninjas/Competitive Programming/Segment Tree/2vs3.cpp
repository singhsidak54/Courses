#include<bits/stdc++.h>
using namespace std;

/*
2 vs 3

The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.

Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.

Output:
For each query of Type 0 print the value modulo 3.

Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N
*/

class Query {
    public:
        char a;
        int  b,c;
};

struct node  {
    int A;
    int B;
    int index;
};

void buildTree(int *a,int *b,int start,int end,node *tree,int treeNode)
{
    if(start == end)
    {
        tree[treeNode].A = a[start];
        tree[treeNode].B = b[start];
        tree[treeNode].index = start;
        return;
    }
    
    int mid = (start + end)/2;
    buildTree(a,b,start,mid,tree,2*treeNode);
    buildTree(a,b,mid+1,end,tree,2*treeNode + 1);
    
    node left = tree[2*treeNode];
    node right = tree[2*treeNode + 1];
    
    if(left.A > right.A)
    {
        tree[treeNode] = left;
    }
    else if(left.A == right.A)
    {
        if(left.B < right.B)
            tree[treeNode] = left;
        else if(left.B > right.B)
            tree[treeNode] = right;
        else
        {
            if(left.index < right.index)
                tree[treeNode] =  left;
            else
                tree[treeNode] =  right;
        }
    }
    else
        tree[treeNode] = right;
}



node query(node *tree,int s,int e,int treeNode,int l,int r)
{
    if(s > r || e < l)
    {
        node nn;
        nn.A = INT_MIN;
        nn.B = INT_MAX;
        nn.index = -1;
        return nn;
        
    }
        
    else if(s >= l && e <= r)
        return tree[treeNode];
    
    else
    {
        int mid = (s + e)/2;
        node left = query(tree,s,mid,2*treeNode,l,r);
        node right = query(tree,mid+1,e,2*treeNode+1,l,r);
        
        node nn;
		if(left.A > right.A)
        {
            nn = left;
        }
        else if(left.A == right.A)
        {
            if(left.B < right.B)
                nn = left;
            else if(left.B > right.B)
                nn = right;
            else
            {
                if(left.index < right.index)
                    nn =  left;
                else
                    nn =  right;
            }    
        }
        else
            nn = right;
        
        return nn;
    }
}

int main() {
	
    int n;
    cin>>n;
        
    int a[n],b[n];
    
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }

    node tree[4*n];
    buildTree(a,b,0,n-1,tree,1);
    

    int q;
    cin>>q;
    
    int t = 0;
    while(t < q)
    {
        int l,r;
        cin>>l>>r;
    
        cout<<query(tree,0,n-1,1,l-1,r-1).index + 1<<endl;
        t++;
    }
    
    return 0;
}
