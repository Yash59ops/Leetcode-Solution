//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    bool check(int n,vector<int>&arr,vector<int>&issafe,int i){
    if(i<0 || i>=n){
        return true;
    }
    
    if(issafe[i]==2){
        return false;
    }
    if(issafe[i]!=-1){
        return issafe[i];
    }
    if(arr[i]==0){
        issafe[i]=0;
        return false;
    }
    issafe[i]=2;
    bool canmove=check(n,arr,issafe,i+arr[i]);
    if(canmove){
        issafe[i]=1;
        return true;
    }
    issafe[i]=0;
    return false;
}
    int goodStones(int n,vector<int> &arr){
   vector<int>issafe(n,-1);
   for(int i=0;i<n;i++){
       if(issafe[i]==-1){
           check(n,arr,issafe,i);
       }
   }
   int ans=0;
   for(int i=0;i<n;i++){
       if(issafe[i]==1){
           ans++;
       }
   }
   return ans;
    }    
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends