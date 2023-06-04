//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
bool all_zero(vector<int>&count){
  return count==vector<int>(26, 0);
}
	int search(string pat, string txt) {
	  vector<int>mp(26,0);
	   for(auto &ch:pat){
	       mp[ch-'a']++;
	   }
	   int count=0;
	   int i=0,j=0;
	   int k=pat.size();
	   int n=txt.size();
	   while(j<n){
	          mp[txt[j]-'a']--;
	       if(j-i+1==k){
	           if(all_zero(mp)){
	             
	               count++;
	           }
	           mp[txt[i]-'a']++;
	           i++;
	       }
	       j++;
	   }
	   return count;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends