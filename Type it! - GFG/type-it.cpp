//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
   int ans=0;

        int n=s.size();

        for(int i=0;i<=(s.size()/2);i++){

            if(s.substr(0,i+1)==s.substr(i+1,i+1))ans=max(ans,i+1);

        }

        if(ans>0)n++;

        return n-ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends