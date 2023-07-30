//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    typedef pair<int,int> p;
  public:
  
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
       vector<int>ans;
       unordered_map<int,vector<p>>graph;
       for(auto &i:edges){
           int u=i[0];
           int v=i[1];
           int wt=i[2];
           graph[v].push_back({u,wt});
           graph[u].push_back({v,wt});
       }
       vector<int>parent(n+1);
       for(int i=1;i<=n;i++){
           parent[i]=i;
       }
       priority_queue<p,vector<p>,greater<p>>pq;
       pq.push({0,1});
       vector<int>dist(n+1,1e9);
       dist[1]=0;
       while(!pq.empty()){
           int wt=pq.top().first;
           int u=pq.top().second;
           pq.pop();
          for(auto &it:graph[u]){
              int v=it.first;
              int v_wt=it.second;
              if(wt+v_wt<dist[v]){
                  dist[v]=wt+v_wt;
                  pq.push({dist[v],v});
                  parent[v]=u;
              }
          }
           
       }
       if(dist[n]==1e9){
           return {-1};
       }
       int node=n;
       while(parent[node]!=node){
           ans.push_back(node);
           node=parent[node];
           
       }
       ans.push_back(1);
       reverse(ans.begin(),ans.end());
       
       
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends