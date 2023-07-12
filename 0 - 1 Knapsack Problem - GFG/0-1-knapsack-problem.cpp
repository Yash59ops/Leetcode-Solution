//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    //Function to return max value that can be put in knapsack of capacity W.
    int help(int total,int wt[],int val[],int n,int index,vector<vector<int>>&dp){
        //bc
        if(index==0){
            if(wt[index]<=total){
                return dp[index][total]=val[index];
            }
            return dp[index][total]=0;
        }
        if(dp[index][total]!=-1){
            return dp[index][total];
        }
        int include=0;
        if(wt[index]<=total){
            include=val[index]+help(total-wt[index],wt,val,n,index-1,dp);
        }
        int exclude=help(total,wt,val,n,index-1,dp);
        return dp[index][total]=max(include,exclude);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
     return help(W,wt,val,n,n-1,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends