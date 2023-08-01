//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(unordered_map<int,vector<int>> adj, vector<int>&ans,int i,int d){
        ans[i]++;
        for(int j=0;j<adj[i].size();j++){
            
            dfs(adj,ans,adj[i][j],d);
        }
        
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	     if(n==1 || s==d)return 1;
   unordered_map<int,vector<int>> adj;
   
   for(int i=0;i<edges.size();i++){
       adj[edges[i][0]].push_back(edges[i][1]);
   }
   
 vector<int>ans(n,0);
  
   dfs(adj,ans,s,d);
   return ans[d];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends