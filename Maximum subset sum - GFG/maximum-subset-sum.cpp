//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
   // long long solveRec(int n, vector<int> &a){
    //     if(n<0) return 0;
    //     if(n==0) return a[n];
        
    //     long long one = solveRec(n-1, a);
    //     long long two = solveRec(n-2, a);
        
    //     return  a[n] + max(one, two);
    // }  
    
    
    // long long solveMem(int n, vector<int> &a, vector<int> &dp){
    //     if(n<0) return 0;
    //     if(n==0) return a[n];
    //     if(dp[n])
    //         return dp[n];
    //     long long one = solveMem(n-1, a, dp);
    //     long long two = solveMem(n-2, a, dp);
        
    //     dp[n] = a[n] + max(one, two);
    //     return dp[n];
    // }  
    
    
    // long long solveTab(int n, vector<int> &a){
    //     vector<long long> dp(n+1, 0);
    //     dp[0] = 0;
    //     dp[1] = a[0];
        // for(int i=2; i<=n; i++){
        //     long long one = dp[i-1];
        //     long long two = dp[i-2];
        //     dp[i] = a[i-1] + max(one, two);
        // }
        // return dp[n];
    // }
    
    long long solveOPT(int n, vector<int> &a){
        long long prev1 = a[0];
        long long prev2 = 0;
        long long ans;
        for(int i=1; i<n; i++){
            ans = a[i] + max(prev1, prev2);
            prev2 = prev1;
            prev1 = ans;
        }
        if(n==1){
            return prev1;
        }
        return ans;
    }
    
    
    long long findMaxSubsetSum(int N, vector<int> &A) {
        vector<int> first;
        
        for(int i=0; i<N-1; i++){
            first.push_back(A[i]);
        }
        
        // return max(solveRec(N-2, first), solveRec(N-1, A));
        
        // vector<int> dp(N+1, 0);
        // return max(solveMem(N-2, first, dp), solveMem(N-1, A, dp));
        // return max(solveTab(N-1, first), solveTab(N, A));
        return max(solveOPT(N-1, first), solveOPT(N, A));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends