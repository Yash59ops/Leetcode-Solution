//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool isPossible(int arr[], int N, int D,int mid){
      int cnt=1;
      int sum=0;
      for(int i=0;i<N;i++){
          if(arr[i]+sum<=mid){
              sum+=arr[i];
          }
          else{
              cnt++;
              if(cnt>D or arr[i]>mid){
                  return false;
              }
              sum=arr[i];
          }
      }
      return true;
  }
    int leastWeightCapacity(int arr[], int N, int D) {
    int low=1;
    int high=0;
    for(int i=0;i<N;i++){
        high+=arr[i];
    }
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossible(arr,N,D,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends