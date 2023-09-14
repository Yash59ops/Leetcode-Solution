//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int rec1(int i,int arr[],int n,int sum,vector<vector<int>>&dp){
	    if(i==n)
    {
        if(sum==0)
        return 1;
        return 0;
    }
    if(dp[i][sum]!=-1)
    return dp[i][sum];
    int take=0;
    if(arr[i]<=sum)
    take=rec1(i+1,arr,n,sum-arr[i],dp);
    int notTake=rec1(i+1,arr,n,sum,dp);
    return dp[i][sum]=(take+notTake)%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
           vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
         return rec1(0,arr,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends