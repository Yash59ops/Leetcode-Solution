//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int help(int coins[],int n,int tar,int ind,vector<vector<int>>&dp){
	 if(ind==n-1){
	     if(tar%coins[n-1]==0){
	         return dp[ind][tar]=tar/coins[n-1];
	     }else{
	         return  1e9;
	     }
	 }
	     if(dp[ind][tar]!=-1){
	         return dp[ind][tar];
	     }
	    int pick=1e9;
	    if(coins[ind]<=tar)
	    pick=1+help(coins,n,tar-coins[ind],ind,dp);
	    int not_pick=help(coins,n,tar,ind+1,dp);
	    return dp[ind][tar]=min(pick,not_pick);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    int n=M;
	    vector<vector<int>>dp(n+1,vector<int>(V+1,0));
	 //  int ans=help(coins,M,V,0,dp);
	    
        //if(ans>=1e9)
    //    return -1;
      //  else
        //return ans;
 for(int target=0;target<=V;target++){
            if(target%coins[n-1]==0)  dp[n-1][target]=target/coins[n-1];
            else dp[n-1][target]=1e9;
        }
        for(int ind=n-2;ind>=0;ind--){
            for(int target=0;target<=V;target++){
                int notTake = 0+dp[ind+1][target];
                int take=INT_MAX;
                if(coins[ind]<=target){
                    take=1+dp[ind][target-coins[ind]];
                }
                dp[ind][target]=min(take,notTake);
            }
        }
        if(dp[0][V]>=1e9){return -1;}
        else return dp[0][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends