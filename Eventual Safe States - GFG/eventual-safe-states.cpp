//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool checkCycleDFS(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,vector<int> adj[],
  int check[]){
    visited[node]=true;
    dfsvisited[node]=true;
    check[node]=0;
for(auto it:adj[node]){
    if(!visited[it]){
        
        bool a=checkCycleDFS(it,visited,dfsvisited,adj,check);
        if(a==true){
            return true;
        }
    }else if(dfsvisited[it]==true){
        return true;
    }
    
}
check[node]=1;
dfsvisited[node]=false;
return false;

}
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsvisited;
    int check[V]={0};
	 for(int i=0;i<V;i++){
        if(!visited[i]){
            checkCycleDFS(i,visited,dfsvisited,adj,check);
        }
    }
    vector<int>safe;
    for(int i=0;i<V;i++){
        if(check[i]==1){
            safe.push_back(i);
        }
    }
    return safe;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends