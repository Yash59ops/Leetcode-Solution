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
unordered_map<char,int>mp;
int i=0,j=0,ans=0;
while(j<S.length()){
    mp[S[j]]++;
    while(mp[S[j]]>1){
    mp[S[i]]--;
        if(mp[S[i]]==0)
        {
            mp.erase(S[i]);
        }
        i++;
    }
    ans=max(ans,j-i+1);
    j++;
}
return ans;
}