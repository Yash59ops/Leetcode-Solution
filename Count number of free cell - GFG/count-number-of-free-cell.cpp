//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
     unordered_set<long long int>row;
     unordered_set<long long int>col;
     vector<long long int>ans(k,0);
     long long int total_zero=n*n;
     long long int total_one;
     for(int i=0;i<k;i++){
         long long int x=arr[i][0];
         long long int y=arr[i][1];
         
         row.insert(x);
         col.insert(y);
         long long int r=row.size();
         long long int c=col.size();
         total_one=((r+c)*n)-(r*c);
         ans[i]=total_zero-total_one;
     }
     return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends