//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int help(int coins[],int n,int tar,int ind,vector<vector<int>>&dp){
	 if(ind==n-1){
	     if(tar%coins[n-1]==0){
	         return tar/coins[n-1];
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
	    vector<vector<int>>dp(n+1,vector<int>(V+1,-1));
	   int ans=help(coins,M,V,0,dp);
        if(ans>=1e9)
        return -1;
        else
        return ans;
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