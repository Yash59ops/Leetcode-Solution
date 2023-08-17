//{ Driver Code Starts
// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends


class Solution
{
    public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) 
    { 
        unordered_set<char> s1Set(s1.begin(), s1.end());
        unordered_set<char> s2Set(s2.begin(), s2.end());

        string result = "";

        for (char c : s1) {
            if (s2Set.find(c) == s2Set.end()) {
                result += c;
            }
        }

        for (char c : s2) {
            if (s1Set.find(c) == s1Set.end()) {
                result += c;
            }
        }

        return (result.empty() ? "-1" : result);
    }

};

//{ Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	Solution obj;
    	string res = obj.concatenatedString(s1, s2);
    	cout<<res<<endl;
	}
	return 0; 
}

// } Driver Code Ends