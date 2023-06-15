//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int check(string &s, int L, int R)
    {
        while(L>=0 and R<s.length() and s[L]==s[R])
        {
            L--;
            R++;
        }
        return R-L-1;
    }
    
    string longestPalin (string S) {
        int ans=0,st=0;
       for(int i=0;i<S.length();i++){
           int len1=check(S,i,i);
           int len2=check(S,i,i+1);
           int len=max(len1,len2);
           if(len>ans){
               ans=len;
               st=i-(len-1)/2;
           }
       }
       return S.substr(st,ans);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends