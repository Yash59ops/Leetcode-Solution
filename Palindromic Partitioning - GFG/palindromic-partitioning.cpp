//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
      bool isPalindrome(int i, int j, string str)

    {

        while(i<j)

        {

            if(str[i] != str[j]) return false;

            i++;

            j--;

        }

        return true;

    }

    int f(int i, int n, string str, vector<int> &dp)

    {

        if(i==n) return 0;

        int minCost = 1e9;

        if(dp[i] != -1) return dp[i];

        for(int j=i; j<n; j++)

        {

            if(isPalindrome(i,j,str))

            {

                int cost  = 1 + f(j+1,n,str,dp);

                minCost = min(minCost,cost);

            }

        }

        return dp[i] = minCost;

    }

    int palindromicPartition(string str)

    {

        int n = str.length();

        vector<int> dp(n,-1);

        return f(0,n,str,dp)-1;

    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends