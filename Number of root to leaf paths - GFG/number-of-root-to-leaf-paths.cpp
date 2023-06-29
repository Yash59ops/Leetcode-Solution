//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 


void pathCounts( Node* node);

/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
    string treeString;
	getline(cin,treeString);
	Node* root = buildTree(treeString);
    pathCounts(root);
    cout<< endl;
  }
  return 0;
}


// } Driver Code Ends


/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*You are required to complete below method */
void code(Node* root,int c,vector<int>&v){
    if(root==NULL)return;
    c=c+1;
    if(root->left==NULL and root->right==NULL){
        v.push_back(c);
    }
    code(root->left,c,v);
    code(root->right,c,v);
}
void pathCounts(Node *root)
{
    //Your code here
    int c=0;
    vector<int>v;
    code(root,c,v);
    int cnt=1;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v[i]==v[i+1])cnt++;
        else{
            cout<<v[i]<<" ";
            cout<<cnt<<" ";
            cout<<"$";
            cnt=1;
            
        }
    }
}