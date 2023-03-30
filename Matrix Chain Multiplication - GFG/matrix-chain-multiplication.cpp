//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int i,int j,int arr[],vector<vector<int>>&dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int s=arr[i-1]*arr[j]*arr[k]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
        ans=min(ans,s);
    }
    return dp[i][j]=ans;
}
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N+1,vector<int>(N+1,0));
       // return solve(1,N-1,arr,dp);
       for(int i=0;i<N;i++)
       dp[i][i]=0;
       for(int i=N-1;i>=1;i--){
          for(int j=i+1;j<=N-1;j++){//kyunki j hamesha i ke right me hoga isiliye i+1 se start kiya he
              int mini=INT_MAX;
            for(int k=i;k<=j-1;k++){
                int cost=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                mini=min(mini,cost);
            }
            dp[i][j]=mini;
          } 
       }
       return dp[1][N-1];
       }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends