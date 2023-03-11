//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int recur(int coins[],int n,int sum,int index,vector<vector<long long int>>&dp){
      //bc
      if(index==n){
          if(sum==0)
          return 1;
          return 0;
      }
      if(dp[index][sum]!=-1)return dp[index][sum];
      long long int pick=0;
      long long int not_pick=0;
      if(sum>=coins[index])
       pick=recur(coins,n,sum-coins[index],index,dp);
       not_pick=recur(coins,n,sum,index+1,dp);
       return dp[index][sum]=pick+not_pick;
  }
    long long int count(int coins[], int N, int sum) {
vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-1));
        return recur(coins,N,sum,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends