//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
           unordered_map<int,vector<int>>graph;
           for(auto it:edges){
               int u=it[0];
               int v=it[1];
               graph[u].push_back(v);
           }
           vector<int>indegree(n+1,0);
          for(int i=1;i<=n;i++){
              for(auto it:graph[i]){
                  indegree[it]++;
              }
          }
             vector<int> mintime(n, 0);
            queue<pair<int, int>> q;
            for(int i=1; i<=n; i++){
                if(indegree[i] == 0){
                    q.push({i, 1});
                }
            }
            while(!q.empty()){
                int node=q.front().first;;
                int time=q.front().second;
                mintime[node-1]=time;
                q.pop();
                for(auto v:graph[node]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        q.push({v,time+1});
                    }
                }
            }
            return mintime;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends