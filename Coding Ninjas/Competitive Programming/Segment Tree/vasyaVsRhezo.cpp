#include<bits/stdc++.h>
using namespace std;

/*
Vasya vs Rhezo

Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.

Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.

Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.

Constraints:
1= N,Q =10^6
1= Ai,Bi =10^9
1=Li=Ri

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
