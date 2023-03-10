//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int recur(int wt[],int val[],int w,int n,int index){
        //bc
        if(index==0){
             if(wt[index]<=w){
                 return val[index];
             }
             return 0;
        }
        int include=0;
        if(w>=wt[index]){
            include=val[index]+recur(wt,val,w-wt[index],n,index-1);
        }
        int exclude=0+recur(wt,val,w,n,index-1);
        return max(include,exclude);
    }
    int recur_memo(int wt[],int val[],int w,int n,int index,vector<vector<int>>&dp){
        //bc
        if(index==0){
            if(wt[index]<=w)return val[index];
            return 0;
        }
        if(dp[index][w]!=-1)return dp[index][w];
        int include=0;
        if(w>=wt[index]){
            include=val[index]+recur(wt,val,w-wt[index],n,index-1);
        }
        int exclude=0+recur(wt,val,w,n,index-1);
        return dp[index][w]=max(include,exclude);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
  //    return recur(wt,val,W,n,n-1);
    vector<vector<int>>dp(n,vector<int>(W+1,0));
//    return recur_memo(wt,val,W,n,n-1,dp);    
      for(int i =wt[0]; i<= W; i++)
       {
           if(wt[0] <= W)
           {
               dp[0][i] = val[0];
           }
           else
           {
               dp[0][i] = 0;
           }
       }
       for(int index=1;index<n;index++){
           for(int cap=0;cap<=W;cap++){
               int include=0;
        if(cap>=wt[index]){
            include=val[index]+dp[index-1][cap-wt[index]];
        }
        int exclude=0+dp[index-1][cap];
        dp[index][cap]=max(include,exclude);
           }
       }
    
        return dp[n-1][W];
  
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