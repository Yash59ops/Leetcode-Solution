//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>>&grid,int i,int j,vector<pair<int,int>>&res,int x,int y){
      if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
          return;
      }
      grid[i][j]=0;
      res.push_back({i-x,j-y});
      dfs(grid,i+1,j,res,x,y);
      dfs(grid,i-1,j,res,x,y);
      dfs(grid,i,j+1,res,x,y);
      dfs(grid,i,j-1,res,x,y);
  }
    int countDistinctIslands(vector<vector<int>>& grid){
        int row=grid.size();
        int col=grid[0].size();
        set<vector<pair<int,int>>>s;
      
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>>res;
                    dfs(grid,i,j,res,i,j);
                    s.insert(res);
                }
            }
        }
        return s.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends