//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
void dfs(vector<int>adj[],vector<int>&vis,int src,stack<int>&st){
	    vis[src]=true;
	    for(auto it:adj[src]){
	        if(!vis[it]){
	            dfs(adj,vis,it,st);
	        }
	    }
	    st.push(src);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    vector<int>vis(V,false);
	    /*
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(adj,vis,i,st);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    */
	    vector<int>indeg(V,0);
	    for(int i=0;i<V;i++){
	        for(auto u:adj[i]){
	            indeg[u]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	       if(indeg[i]==0){
	           q.push(i);
	       }
	        }
	        vector<int>ans;
	        while(!q.empty()){
	            int cur=q.front();
	            q.pop();
	            ans.push_back(cur);
	            for(auto it:adj[cur]){
	             if(!vis[it]){
	                 indeg[it]--;
	                 if(indeg[it]==0){
	                 q.push(it);
	                 }
	             }   
	            }
	        }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends