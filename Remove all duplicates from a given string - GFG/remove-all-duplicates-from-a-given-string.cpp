//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	 unordered_map<char,int>mp;
	 for(int i=0;i<str.length();i++){
	     char ch=str[i];
	     if(mp[ch]>0){
	         str[i]='$';
	     }
	     mp[ch]++;
	 }
	 string ans="";
	 for(int i=0;i<str.length();i++){
	     if(str[i]!='$'){
	         ans+=str[i];
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
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends