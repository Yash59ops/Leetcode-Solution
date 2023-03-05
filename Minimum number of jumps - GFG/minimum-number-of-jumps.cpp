//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
     int v=0,max_j=INT_MIN,ans=0;
     for(int i=0;i<n-1;i++){
         max_j=max(arr[i]+i,max_j);
         if(i==v){
             ans++;
             v=max_j;
         }
         if(arr[i]==0 && i==v)return -1;
     }
     return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends