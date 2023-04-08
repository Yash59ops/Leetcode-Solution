//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
  bool allZero(vector<int>& count) {
        return count==vector<int>(26, 0);
    }
	int search(string pat, string txt) {
	   vector<int>counter(26,0);
	   int k=pat.size();
	   for(char &ch:pat){
	       counter[ch-'a']++;
	   }
	   int n=txt.size();
	   int l=0,r=0,ans=0;
	   while(r<n){
	       counter[txt[r]-'a']--;
	       if(r-l+1==k){
	           if(allZero(counter)){
	               ans++;
	           }   
	           
	           counter[txt[l]-'a']++;
	           l++;
	       }
	       r++;
	       
	   }
	   return ans;
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