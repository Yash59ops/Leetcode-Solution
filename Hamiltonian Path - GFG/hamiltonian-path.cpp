//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
  bool visit(int i,int cnt,vector<bool>&vis,vector<int>m[],int N){
      if(cnt==N){
          return true;
      }
      vis[i]=true;
      for(auto x:m[i]){
          if(!vis[x] && visit(x,cnt+1,vis,m,N)){
              return true;
          }
          
      }
      vis[i]=false;
      return false;
  }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<bool>vis(N+1,false);
        vector<int>m[N+1];
        for(int i=0;i<Edges.size();i++){
            m[Edges[i][0]].push_back(Edges[i][1]);
            m[Edges[i][1]].push_back(Edges[i][0]);
        }
        for(int i=1;i<=N;i++){
            if(visit(i,1,vis,m,N)){
                return true;
            }
        }
        return false;
    }
};
 



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends