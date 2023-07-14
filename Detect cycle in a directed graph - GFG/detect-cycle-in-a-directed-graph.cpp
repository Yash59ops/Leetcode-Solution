//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int>adj[],int u,vector<bool>&vis,vector<bool>&inrecur)
    {
        vis[u]=true;
        inrecur[u]=true;
        for(auto v:adj[u]){
            if(vis[v]==true && inrecur[v]==true){
                return true;
            }else if(!vis[v]){
                if(dfs(adj,v,vis,inrecur)==true){
                    return true;
                }
            }
        }
        inrecur[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
     vector<bool>vis(V,false);
     vector<bool>inrecur(V,false);
     for(int i=0;i<V;i++)
     {
         if(dfs(adj,i,vis,inrecur)==true){
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