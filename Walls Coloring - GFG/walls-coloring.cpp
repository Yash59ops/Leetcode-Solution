//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
   int minCost(vector<vector<int>> &c, int N) {
         vector<vector<int>> dp(3,vector<int>(N));
          dp[0][0]=c[0][0];
       dp[1][0]=c[0][1];
       dp[2][0]=c[0][2];
       for(int i=1;i<N;i++){
            dp[0][i]=c[i][0]+min(dp[1][i-1],dp[2][i-1]);
            dp[1][i]=c[i][1]+min(dp[0][i-1],dp[2][i-1]);
            dp[2][i]=c[i][2]+min(dp[0][i-1],dp[1][i-1]);
       }
       return min(dp[0][N-1],min(dp[1][N-1],dp[2][N-1]));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends