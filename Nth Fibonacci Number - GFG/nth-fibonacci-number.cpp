//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  long long m = 1000000007;
  int solve(int n,vector<int>&dp){
      if(n==0){
          return 0;
      }
      if(n==1 || n==2){
          return 1;
      }
      if(dp[n]!=-1){
          return dp[n]%m;
      }
      return dp[n]=(solve(n-1,dp)+solve(n-2,dp))%m;
  }
    long long int nthFibonacci(int n){
        vector<long long int>dp(n+1,0);
       dp[0]=0;
       dp[1]=1;
       dp[2]=1;
       for(long long int i=3;i<=n;i++){
           dp[i]=(dp[i-1]+dp[i-2])%m;
       }
       return dp[n];
     // return solve(n,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends