//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int recur(int n,int x,int y,int z,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MIN;
        }
        if(dp[n]!=-1)return dp[n];
        int op1=recur(n-x,x,y,z,dp);
        int op2=recur(n-y,x,y,z,dp);
        int op3=recur(n-z,x,y,z,dp);
        return dp[n]=1+max(op1,max(op2,op3));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,-1);
       int ans=recur(n,x,y,z,dp);
    
        return ans<0?0:ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends