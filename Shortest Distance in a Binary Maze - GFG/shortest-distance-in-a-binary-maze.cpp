//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   typedef pair<int,pair<int, int>>p;
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        vector<pair<int,int>>dirs={{-1,0},{0,-1},{0,1},{1,0}};
        priority_queue<p,vector<p>,greater<p>>pq;
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>dist(row,vector<int>(col,1e9));
                pq.push({0,{source.first,source.second}});
        dist[source.first][source.second]=0;
        while(!pq.empty()){
            int weight=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(auto it:dirs){
                int x_=x+it.first;
                int y_=y+it.second;
                if(x_>=0 && y_>=0 && x_<row && y_<col && grid[x_][y_]==1 && weight+1<dist[x_][y_]){
                    dist[x_][y_]=weight+1;
                    pq.push({dist[x_][y_],{x_,y_}});
                }
            }

        }
    
        
        if(dist[destination.first][destination.second]==1e9){
            return -1;
        }
        return dist[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends