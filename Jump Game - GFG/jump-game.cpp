//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int help(int A[],int n,int i){
      if(i>=n-1){
          return 1;
      }
      if(A[i]==0){
          return 0;
      }
      for(int j=i+1;j<=A[i]+i;j++){
         if(j<n && help(A,n,j)){
             return true;
         }
      }
      return false;
  }
    int canReach(int A[], int N) {
     int i=0;
     return help(A,N,i);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends