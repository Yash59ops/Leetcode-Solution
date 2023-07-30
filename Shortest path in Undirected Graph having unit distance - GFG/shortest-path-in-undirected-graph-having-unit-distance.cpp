//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       vector<int>dist(N,1e9);
       unordered_map<int,vector<int>>adj;
       for(auto &it:edges){
           int u=it[0];
           int v=it[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       queue<int>q;
       q.push(src);
       dist[src]=0;
       while(!q.empty()){
           int u=q.front();
           q.pop();
           for(auto &v:adj[u]){
               if(dist[u]+1<dist[v]){
                   dist[v]=1+dist[u];
                   q.push(v);
               }
           }
           
       }
        vector<int>ans(N,-1);
      for(int i=0;i<N;i++){
          if(dist[i]!=1e9){
              ans[i]=dist[i];
          }
      }
      return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends