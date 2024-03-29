//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int get(Node*root,int &c){
    
    if(!root)return 0;
    
    c++;
    
    int l = get(root->left,c);
    int r = get(root->right,c);
    
    return root->data+l+r;
}
void isBSTUtil(Node* node,vector<int>&v)
{
    
    if(!node)return;
    isBSTUtil(node->left,v);
    v.push_back(node->data);
    isBSTUtil(node->right,v);
    
  
}
bool check(vector<int>v){
    
    for(int i = 1;i<v.size();i++){
        
        if(v[i-1]>=v[i])return 0;
    }
    return 1;
}
void solve(Node*root,int t,int &res){
    
    if(!root)return;
    int c = 0;
  
    
   int s =  get(root,c);
   
   if(s==t){
       vector<int>v;
       
    isBSTUtil(root,v);
    bool f = check(v);
    if(f){
        
        res = min(res,c);
    }
    
   }
   solve(root->left,t,res);
   solve(root->right,t,res);
   
   
}
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        int res = 1e9;
        solve(root,target,res);
        if(res==1e9)return -1;
        return res;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends