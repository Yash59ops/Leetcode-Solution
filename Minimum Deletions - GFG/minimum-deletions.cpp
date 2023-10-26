//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[1001][1001];
    
    int minimumNumberOfDeletions(string s) { 
        
        memset(dp,0,sizeof(dp));
        int n = s.size();
        
        for(int i = n-1; i>=0 ; i--){
            for(int j = i; j<n ;j++ ){
                if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
            }
        }
        
        return dp[0][s.size()-1];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends