//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
 bool helper(int i, int k, int t, vector<int> &coins, 
  vector<vector<int>>& dp)
  {
      if(i == coins.size())
      {
          return (k == 0 and t == 0);
      }
      
      if(dp[k][t] != -1) 
      {
          return dp[k][t] == 1;
      }
      
      bool pick = false, npick = false;
      if(t >= coins[i] and k > 0) 
      {
          pick = helper(i, k-1, t-coins[i], coins, dp);
      }
      
      npick = helper(i+1, k, t, coins, dp);
      
      return dp[k][t] = (pick or npick);
  }  
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) 
    {
        vector<vector<int>> dp(K+1, vector<int> (target+1, -1));
        return helper(0, K, target, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends