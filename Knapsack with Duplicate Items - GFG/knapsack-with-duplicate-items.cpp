//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1001][1001];
int solve(int w,int n,int val[],int wt[]){
if(n==-1 or w==-1){
return 0;
}
if(dp[w][n]!=-1)
return dp[w][n];

if(wt[n]>w)
return dp[w][n]=solve(w,n-1,val,wt);

int a=val[n]+solve(w-wt[n],n,val,wt);
int b=solve(w,n-1,val,wt);
return dp[w][n]=max(a,b);
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        dp[W][N];
memset(dp,-1,sizeof(dp));
return solve(W,N-1,val,wt);
        // code here
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends