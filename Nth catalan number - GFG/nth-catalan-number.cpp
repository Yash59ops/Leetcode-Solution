//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int mod=1e9+7;
  int f(int n, vector<int> &dp) {
        if(n == 0 || n == 1) 
            return 1; 
        
        if(dp[n] != -1) return dp[n]; 
        
        int ans = 0; 
        for(int ind = 0; ind < n; ind++) {
            ans = (ans + ((f(ind, dp) % mod) *1LL* 
            (f(n-1-ind, dp))) % mod) % mod; 
        }
        return dp[n] = ans; 
    }
    int findCatalan(int n) 
    {
        vector<int> dp(n+1, -1); 
        return f(n, dp); 
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends