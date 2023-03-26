//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
      vector<bool>visited(leaves+1,false);
      for(int i=0;i<N;i++){
          int num=frogs[i];
          int k=num;
          if(num<=leaves && !visited[num]){
          while(num<=leaves){
              visited[num]=true;
              num+=k;
          }
          }
      }
      int ans=0;
      for(int i=1;i<=leaves;i++){
          if(!visited[i]){
              ans++; 
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
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends