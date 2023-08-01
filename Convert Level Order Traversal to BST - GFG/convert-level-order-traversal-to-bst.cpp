//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}
// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.
Node*insert(Node*root, int K)
{
    if(root == NULL)
     return new Node(K);
    else if(root->data < K)
     root->right = insert(root->right, K);
    else if(root->data > K)
     root->left = insert(root->left, K);
    return root; 
}
Node* constructBst(int arr[], int n)
{
      Node*root = new Node(arr[0]);
    for(int i=1; i<n; i++)
    {
        insert(root, arr[i]);
    }
    return root;
}
