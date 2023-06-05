//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int f(int arr[], int i, int k,vector<vector<int>> &dp){

        if(i<0){

            if(k>0) return 1;

            else return  0;

        }

        if(dp[i][k]!=-1) return dp[i][k];

        int nt=f(arr,i-1,k,dp);

        int t=0;

        if(arr[i]<=k) t=f(arr,i-1,k/arr[i],dp);

        return dp[i][k]=(t+nt);

    }

    int numOfSubsets(int arr[], int n, int k) {

        // code here

        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));

        return f(arr,n-1,k,dp)-1;

        

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends