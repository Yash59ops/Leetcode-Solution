//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
         vector<string>vec;
        int j=0;
        string a="";
        for(int i=0;i<S.length();i++){
           if(S[i]=='.'){
               vec.push_back(a);
               vec.push_back(".");
               a.clear();
           }
           else{
               a=a+S[i];
           }
        }
        vec.push_back(a);
        string a1="";
        for(int i=vec.size()-1;i>=0;i--){
            a1=a1+vec[i];
        }
        return a1;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends