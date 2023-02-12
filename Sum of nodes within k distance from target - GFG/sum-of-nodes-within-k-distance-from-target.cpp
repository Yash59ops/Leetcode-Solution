//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
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
    Node* root = newNode(stoi(ip[0]));
        
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
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:
void makeparentmap(Node*root,unordered_map<Node*,Node*>&parent_track){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*cur=q.front();
        q.pop();
        if(cur->left){
            parent_track[cur->left]=cur;
            q.push(cur->left);
        }
        if(cur->right){
            parent_track[cur->right]=cur;
            q.push(cur->right);
        }
    }
}
Node*findtarget(Node*root,int target){
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
     Node*cur=q.front();
        q.pop();
        if(cur->data==target){
           return cur;
        }
        if(cur->left){
            q.push(cur->left);
        }
        if(cur->right){
            q.push(cur->right);
        }
    }
    return NULL;
}
    int sum_at_distK(Node* root, int target, int K)
    {
       unordered_map<Node*,Node*>parent;
       Node*Target=findtarget(root,target);
       makeparentmap(root,parent);
       unordered_map<Node*,bool>visited;
      int sum=0,level=0;
       queue<Node*>q;
         queue<Node*>queue;
       q.push(Target);
       visited[Target]=true;
       while(!q.empty()){
           int sq=q.size();
           if(level++ == K){
               break;
           }
           for(int i=0;i<sq;i++){
               Node*cur=q.front();
               q.pop();
               queue.push(cur);
               if(cur->left && !visited[cur->left]){
                   q.push(cur->left);
                   visited[cur->left]=true;
               }
               if(cur->right && !visited[cur->right]){
                   q.push(cur->right);
                   visited[cur->right]=true;
               }
               if(parent[cur] && !visited[parent[cur]]){
                   q.push(parent[cur]);
                   visited[parent[cur]]=true;
               }
           }
       }
        
           while(!q.empty()){
           sum+=q.front()->data;
           q.pop();
       }
        while(!queue.empty()){
           sum+=queue.front()->data;
           queue.pop();
       }
       return sum;
       
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}


// } Driver Code Ends