//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
   void dfs(int i, vector<int>adj[], vector<int>&ans){
        ans[i]++;
        for(auto x:adj[i]){
           dfs(x,adj,ans);
        }
    }
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        vector<int>ans(V,0);
        dfs(source,adj,ans);
        return ans[destination];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends