//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string string1, string string2) {
         string s="";
        
        map<char,int>mp;
        
        for(int i=0;i<string2.size();i++)
        {
            mp[string2[i]]=1;
        }
        
        for(int i=0;i<string1.length();i++)
        {
            if(mp[string1[i]]!=1)
            {
                s.push_back(string1[i]);
            }
        }
        
  return s;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}

// } Driver Code Ends