//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
 bool isPalindrome(string s)
 {
     for(int i=0;i<s.length();i++)
     {
         if(s[i]!=s[s.length()-1-i])
         return 0;
     }
     return 1;
 }
    int addMinChar(string str){
        for(int i=str.length();i>=0;i--)
        {
            if(isPalindrome(str.substr(0,i)))
            {
                return str.length()-i;
            }
        }
        return str.length()-1;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends