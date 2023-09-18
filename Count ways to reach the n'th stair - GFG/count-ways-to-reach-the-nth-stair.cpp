//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    long long int m = 1e9 + 7;
    int count(int n,vector<int>&dp){
        if(n==1 || n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=(count(n-1,dp)%m+count(n-2,dp)%m)%m;
    }
    int countWays(int n){
        vector<int>dp(n+1,-1);
       return count(n,dp)%m;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends