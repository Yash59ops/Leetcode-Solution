//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int>adj[],int u,vector<bool>&vis,int parent){
        vis[u]=true;
        for(auto &v:adj[u]){
            if(v==parent){
                continue;
            }
            if(vis[v]==true){
                return true;
            }
            if(dfs(adj,v,vis,u)==true){
                return true;
            }
        }
        return false;
        
    }
    bool isCycleBFS(int src, vector<int>* adj, vector<bool>& visited) {
        unordered_map<int, int> parent;
        parent[src] = -1;
        visited[src] = true;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            for(auto neighbour : adj[front]) {
                if(visited[neighbour] == true && neighbour != parent[front]) {
                    return true;
                }
                else if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
    vector<bool>vis(V,false);
/*
    for(int i=0;i<V;i++){
        if(!vis[i] && dfs(adj,i,vis,-1)){
            return true;
        }
    }
    return false;
    */
    for(int i=0;i<V;i++){
        if(!vis[i] && isCycleBFS(i,adj,vis)){
            return true;
        }
    }
    return false;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends