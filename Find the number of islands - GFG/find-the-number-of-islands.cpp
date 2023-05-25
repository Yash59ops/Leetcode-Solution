//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void bfs(vector<vector<char>>&grid,int row,int col,vector<vector<bool>>&visited){
      queue<pair<int,int>>q;
      q.push({row,col});
      visited[row][col]=true;
      while(!q.empty()){
      
      int x=q.front().first;
      int y=q.front().second;
      q.pop();
      for(int i=-1;i<=1;i++){
          for(int j=-1;j<=1;j++){
              int nrow=x+i;
              int ncol=y+j;
               if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && visited[nrow][ncol] == 0 && grid[nrow][ncol]=='1'){
               q.push({nrow,ncol});
                   visited[nrow][ncol]=true;
               }
          }
      }
          
          
      }
      
      
      
      
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
       int ans=0,row=grid.size(),col=grid[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(grid[i][j]=='1' && !visited[i][j]){
                   bfs(grid,i,j,visited);
                   ans++;
               }
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends