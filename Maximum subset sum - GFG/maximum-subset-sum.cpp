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
   long long solve(int n, vector<int> &a,int index ,vector<int>&dp ){
        //base condition
        if(index>=n){
            return 0;
        }
        
        if(dp[index]!=-1){
            return dp[index];
        }
        long long include = a[index]+solve(n,a,index+1,dp);
        
        long long exclude = 0;
        if(index+1 < n){
            exclude = a[index+1]+solve(n,a,index+2,dp);
        }
        return dp[index] = max(exclude,include);
        
    } 
    long long findMaxSubsetSum(int N, vector<int> &A) {
       
        vector<int>dp(N+1,-1);
        return solve(N,A,0,dp);
        
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