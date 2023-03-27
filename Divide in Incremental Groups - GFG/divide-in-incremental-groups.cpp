//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int solve(int num,int n,int k,vector<vector<vector<int>>>&dp){
      //bc
      if(k==0){
          if(n==0)return 1;
          return 0;
      }
      
   if(dp[num][n][k]!=-1)return dp[num][n][k];
   int ways=0;
   for(int i=num;i<=n;i++){
       ways+=solve(i,n-i,k-1,dp);
   }
      return dp[num][n][k]=ways;
  }
    int countWaystoDivide(int N, int K) {
       vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(N+1,vector<int>(K+1,-1)));
       return solve(1,N,K,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends