//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int minRemove(int a[], int b[], int n, int m) {
          int ans=0;
       unordered_map<int,int>um1;
       unordered_map<int,int>um2;
       for(int i=0;i<n;i++){
           um1[a[i]]++;
       }
       for(int i=0;i<m;i++){
           um2[b[i]]++;
       }
      for(auto i:um1){
          if(um2.find(i.first)!=um2.end()){
              ans=ans+min(i.second,um2[i.first]);
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
        int n, m, i;
        cin >> n >> m;
        int a[n], b[m];
        for (i = 0; i < n; i++) cin >> a[i];
        for (i = 0; i < m; i++) cin >> b[i];
        Solution obj;
        cout << obj.minRemove(a, b, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends