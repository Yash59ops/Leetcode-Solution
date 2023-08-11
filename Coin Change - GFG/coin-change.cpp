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
    long long int count(int a[], int n, int value) {
   vector<vector<long long int >> dp(n,vector<long long int >(value +1,0));
        vector<long long int> prev(value+1,0), curr(value+1,0);
        for(int t=0;t<=value;t++){
            // dp[0][t] = (t % a[0] ==0 );
            prev[t] = (t % a[0] ==0 );
        }
        
        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=value;T++){
                /*long long int notTake = dp[ind-1][T];
                long long int Take = 0; 
                
                if(a[ind]<=T) Take = dp[ind][T-a[ind]];
                
                dp[ind][T] = Take+notTake;*/
                
                //space optimization  
                
                long long int notTake = prev[T];
                long long int Take = 0; 
                
                if(a[ind]<=T) Take = curr[T-a[ind]];
                
                curr[T] = Take+notTake;
                
            }
            prev= curr;
        }
        
        return prev[value];
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