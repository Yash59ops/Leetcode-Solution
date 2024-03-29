//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
const int mod=1e9+7;
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    int ans=INT_MIN;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
    
    
    }
};


//{ Driver Code Starts.


// } Driver Code Ends

//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends