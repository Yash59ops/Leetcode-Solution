//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int arr[],int n,int target,vector<int>&dp){
	    if(target==0)
	    return 0;
	    if(target<0)
	    return INT_MAX;
	    if(dp[target]!=-1)
	    return dp[target];
	    int ans=INT_MAX;
	    for(int i=0;i<n;i++){
	        int m=solve(arr,n,target-arr[i],dp);
	        if(m!=INT_MAX){
	            ans=min(ans,1+m);
	        }
	    }
	    return dp[target]=ans;
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	   vector<int>dp(V+1,-1);
	   int ans=solve(coins,M,V,dp);
	   if(ans==INT_MAX){
	       return -1;
	   }
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