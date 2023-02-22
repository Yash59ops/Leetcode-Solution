//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
      int func(int n, vector<int>& dp){

        if(n % 2 != 0){

            return 0;

        }

        if(dp[n] != -1) return dp[n];

        if(n == 0) return 1; 

        if(n == 2) return 1;

        if(n == 4) return 2;

        int sum = 0;

        for(int i=2;i<=n;i++){

            sum += func(i-2, dp) * func(n-i, dp);

        }

        return dp[n] = sum;

    }

    int count(int N){

        

        vector<int> dp(N+1, -1);

        return func(N, dp);

    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends