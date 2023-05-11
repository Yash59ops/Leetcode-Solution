//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPal(string &s){
        int l=0,h=s.size()-1;
        while(l<h){
            if(s[l]=='?')s[l]=s[h];
            else if(s[h]=='?')s[h]=s[l];
            if(s[l]!=s[h])return 0;
            l++,h--;
        }return 1;
    }
    int solve(string &s){
        int ans=0,i=0;
        while(i<s.size() && s[i]=='?')i++;
        if(i==s.size())return 0;
        char prev=s[i];
        for(;i<s.size();i++){
            if(s[i]=='?' || s[i]==prev)continue;
            ans+=abs(s[i]-prev);
            prev=s[i];
        }return ans;
    }
    int minimumSum(string s) {
        return isPal(s)?solve(s):-1;
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
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends