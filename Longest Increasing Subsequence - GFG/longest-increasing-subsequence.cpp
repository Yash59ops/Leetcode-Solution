//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int solve(int n,int a[],int index,int prev){
        //bc
        if(index==n){
            return 0;
        }
        int not_pick=solve(n,a,index+1,prev);
        int pick=0;
        if(prev==-1 || prev<a[index]){
            pick=1+solve(n,a,index+1,a[index]);
        }
        return max(pick,not_pick);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // int prev=-1;
     // return solve(n,a,0,prev);
     vector<int>ans;
     if(n==0){
         return 0;
     }
     ans.push_back(a[0]);
     for(int i=1;i<n;i++){
         if(a[i]>ans.back()){
             ans.push_back(a[i]);
         }else{
             int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
             ans[index]=a[i];
         }
     }
      return ans.size();
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends