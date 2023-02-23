//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int mod=1e9+7;
  int recur(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
      //bc
      if(i<0 || j<0 || i>=n || j>=m){
          return 0;
      }
      if(i==n-1 && j==m-1)
      return 1;
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
       long long down=0;
       long long right=0;   
            if(i+1 < n && grid[i+1][j]==1){
                down=recur(i+1, j, n, m, grid,dp);
            }
            if(j+1 < m && grid[i][j+1]==1){
                right=recur(i, j+1, n, m, grid,dp);
            }
            return dp[i][j]=(down+right)%mod;
      
  }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
       if(grid[0][0]==0){
       return 0;
       }
       vector<vector<int>>dp(n,vector<int>(m,-1));
       return recur(0,0,n,m,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends