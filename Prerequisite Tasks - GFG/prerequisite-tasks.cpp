//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 bool dfs(unordered_map<int,list<int>>&adj,int src,vector<int>&vis,vector<bool>&inrecur){
        vis[src]=true;
        inrecur[src]=1;
        for(auto it:adj[src]){
          if(!vis[it] && dfs(adj,it,vis,inrecur)==true){
                return true;
            }else if(inrecur[it]==true){
                return true;
            }
        }
        inrecur[src]=false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	   unordered_map<int,list<int>>mp;
	   for(auto it:prerequisites){
	       mp[it.second].push_back(it.first);
	   }
	   int n=N;
	   vector<bool>inrecur(n,false);
	   vector<int>vis(n,0);
	   for(int i=0;i<n;i++){
	       if(!vis[i] && dfs(mp,i,vis,inrecur)==true)
	       {
	           return false;
	       }
	   }
	   return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends