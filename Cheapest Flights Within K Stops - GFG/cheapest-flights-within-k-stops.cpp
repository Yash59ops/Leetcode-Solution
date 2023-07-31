//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  typedef pair<int,pair<int,int>>p;
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>>adj[n];
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!pq.empty()){
            
            int  stops=pq.top().first;
            int node=pq.top().second.first;
            int weight=pq.top().second.second;
            pq.pop();

           for(auto it:adj[node]){
               int u=it.first;
               int price=it.second;
               if(price+weight<dist[u] && stops<=K){
                   dist[u]=price+weight;
                   pq.push({stops+1,{u,dist[u]}});
               }
           }
        }
       
         if(dist[dst]!=1e9){
            return dist[dst];
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends