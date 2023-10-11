//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
  int ans=INT_MIN;
  int i=0,j=0;
  unordered_map<char,int>mp;
  while(j<S.length()){
      mp[S[j]]++;
      while(mp[S[j]]>1){
          mp[S[i]]--;
          i++;
      }
      ans=max(ans,j-i+1);
      j++;
  }
  return ans;
}