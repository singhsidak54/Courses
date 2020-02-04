#include<bits/stdc++.h>
using namespace std;

class trieNode {
  public:
    trieNode *left;
    trieNode *right;
};

void insert(int n,trieNode *head)
{
    trieNode *curr = head;
    for(int i=31; i>=0; i--)
    {
        int b = (n>>i)&1;
        
        if(b == 0)
        {
            if(!curr->left)
            {
                curr->left = new trieNode();
            }
            
            curr = curr->left;
        }
        else
        {
            if(!curr->right)
                curr->right = new trieNode();
            
            curr = curr->right;
        }
    }
}

int findMaxXorPair(int *a, int n,trieNode *head)
{
    int max_xor = INT_MIN;

    for(int i=0; i<n; i++)
    {
        int curr_xor = 0;
        int val = a[i];
        trieNode *curr = head;
        for(int j=31; j>=0; j--)
        {
            int b = (val>>j)&1;
            
            if(b==0)
            {
                if(curr->right)
                {
                    curr = curr->right;
                    curr_xor += pow(2,j);
                }  
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if(curr->left)
                {
                    curr = curr->left;
                    curr_xor += pow(2,j);
                }
                else
                {
                    curr = curr->right;   
                }
            }
        }
        
        if(curr_xor > max_xor)
            max_xor = curr_xor;
    }
    
    return max_xor;
}
int main() {

    int n;
    cin>>n;
    
    int *a = new int[n];
    
    for (int i=0; i<n; i++)
        cin>>a[i];
    
    trieNode *head = new trieNode();
    for(int i=0; i<n; i++)
         insert(a[i],head);
    
    cout<<findMaxXorPair(a,n,head);
}
