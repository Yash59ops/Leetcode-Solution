//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
Node*solve(string s,int &i){
    string str="";
    if(i>=s.length()){
        return NULL;
    }
    int ele=0;
     Node*ans=NULL;
    while(s[i]>='0' && s[i]<='9'){
        ele=ele*10+s[i]-'0';
         ans= new Node(ele);
        i++;
    }
    
      if(s[i]=='('){
        i++;
        ans->left=solve(s,i);
    }
      
      if(s[i]=='('){
        i++;
        ans->right=solve(s,i);
    }
    
    if(s[i]==')'){
        i++;
        return ans;
    }
    
   
   i++;
   return ans;
 
}
    
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        int ind=0;
        return solve(str,ind);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends