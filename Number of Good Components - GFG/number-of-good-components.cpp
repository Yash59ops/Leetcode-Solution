//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


   class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int find(int node) {
        return node==parent[node]?node:parent[node]=find(parent[node]);
    }

    void unite(int u, int v) {
        int ulp_u = find(u); 
        int ulp_v = find(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

class Solution {
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        int n=adj.size()-1;
        DisjointSet dsu(n);
        for(int i=0;i<adj.size();i++){
            for(auto dest:adj[i]){
                dsu.unite(i,dest);
            }
        }
        // for(auto src:adj){
        //     for(auto dest:src)dsu.unite(src,dest);
        // }
        map <int,vector<int>> mp;
        for(int i=1;i<=n;i++){
            mp[dsu.find(i)].push_back(i);
        }
        // set <int> s;
        int count=0;
        for(auto it:mp){
            
            int src=it.first;
            int temp=mp[src].size();
            bool flag=true;
            for(auto dest:mp[src]){
                if((adj[dest].size()+1)!=temp){
                    flag=false;
                    break;
                }
            }
            if(flag)++count;
        }
        return count;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends