//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int time_nekal(unordered_map<Node*,Node*>&mp,Node*target){
      int time=0;
      queue<Node*>q;
      q.push(target);
      unordered_map<Node*,int>vis;
      vis[target]=1;
      while(!q.empty()){
          int n=q.size();
              bool flag=false;
          while(n--){
              Node*cur=q.front();
              q.pop();
              if(cur->left && !vis[cur->left]){
                  vis[cur->left]=1;
                  q.push(cur->left);
                  flag=true;
              }
              if(cur->right && !vis[cur->right]){
                  vis[cur->right]=1;
                  q.push(cur->right);
                  flag=true;
              }
              if(mp[cur] && !vis[mp[cur]]){
                  vis[mp[cur]]=1;
                  q.push(mp[cur]);
                  flag=true;
              }
          }
              if(flag==true){
                  time++;
              }
      }
      return time;
  }
  Node*par_mapping(Node*root,int target,unordered_map<Node*,Node*>&mp){
      mp[root]=NULL;
      queue<Node*>q;
      q.push(root);
      Node*t;
      while(!q.empty()){
          int n=q.size();
          while(n--){
              Node*cur=q.front();
              q.pop();
              if(cur->data==target){
             t=cur;     
              }
              if(cur->left){
                  mp[cur->left]=cur;
                  q.push(cur->left);
              }
              if(cur->right){
                  mp[cur->right]=cur;
                  q.push(cur->right);
              }
          }
      }
      return t;
  }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*>par;
        Node*new_t=par_mapping(root,target,par);
        int time=time_nekal(par,new_t);
        return time;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends