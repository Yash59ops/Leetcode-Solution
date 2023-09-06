//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	void dfs(vector<int>adj[],int V,vector<bool>&vis,int i,int &cnt){
	    vis[i]=true;
	    cnt++;
	    for(const auto &it:adj[i]){
	        if(!vis[it]){
	            dfs(adj,V,vis,it,cnt);
	        }
	    }
	}
	int findMotherVertex(int V, vector<int>adj[])
	{
	   vector<bool>vis(V,false);
	   int ans;
	   int cnt=0;
	   for(int i=0;i<V;i++){
	       if(!vis[i]){
	           dfs(adj,V,vis,i,cnt);
	           ans=i;
	           cnt=0;
	       }
	   }
	   vis.assign(V,false);
	   dfs(adj,V,vis,ans,cnt);
	   if(cnt==V){
	       return ans;
	   }
	   return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends