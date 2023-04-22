//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        
        
        
        
        stack<int>s1,s2;
        for(int i=0;i<N;i++){
            if(s1.size()==0 || s2.size()==0){
                s1.push(color[i]);
                s2.push(radius[i]);
            }else if(s1.top()==color[i] && s2.top()==radius[i]){
                s1.pop();
                s2.pop();
            }else{
                s1.push(color[i]);
                s2.push(radius[i]);
            }
        }
        return s1.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends