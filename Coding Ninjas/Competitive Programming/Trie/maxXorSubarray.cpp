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

int findMaxXor(int n,trieNode *head)
{
    int max_xor = 0;
    trieNode *curr = head;
    
    for(int i=31; i>=0; i--)
    {
        int b = (n>>i) & 1;
        
        if(b==0)
        {
            if(curr->right)
            {
                curr = curr->right;
                max_xor += pow(2,i);
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
                max_xor += pow(2,i);
            }
            else
            {
                curr = curr->right;
            }
        }
        
    }
    
    return max_xor;
}

int maxXorSubarray(int *a,int n)
{
    int pre_xor = 0;
    
    trieNode* head = new trieNode();
    
    int max = INT_MIN;
    
    for(int i=0; i<n; i++)
    {
        pre_xor = pre_xor ^ a[i];
        
        insert(pre_xor,head);
        
        int res = findMaxXor(pre_xor,head);
        
        if(res > max)
            max = res;
    }
    
    return max;
}
int main() {

    int n;
    cin>>n;
    int a[n];
    
    for (int i=0; i<n; i++)
        cin>>a[i];
    
    
    cout<<maxXorSubarray(a,n);
}
