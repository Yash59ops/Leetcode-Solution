//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int>adj[],int src,vector<bool>&vis,vector<int>&inrecur){
        vis[src]=true;
        inrecur[src]=1;
        for(auto it:adj[src]){
            if(!vis[it] && dfs(adj,it,vis,inrecur)==true){
                return true;
            }else if(inrecur[it]==true){
                return true;
            }
        }
        inrecur[src]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
      vector<bool>vis(V,false);
      vector<int>inrecur(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i] && dfs(adj,i,vis,inrecur)){
            return true;
        }
    }
    return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends