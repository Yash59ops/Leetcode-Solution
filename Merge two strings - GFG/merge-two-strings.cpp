//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends



string merge (string S1, string S2)
{
      int i=0;
    int j=0;
    string ans="";
    
    while(i<S1.length() && j<S2.length()){
        ans.push_back(S1[i]);
        ans.push_back(S2[j]);
        i++;
        j++;
        
    }
    while(i<S1.length()){  // for reamaining characters in string 1
        ans.push_back(S1[i]);
        i++;
    }
    while(j<S2.length()){// __________||________________in string 2;
        ans.push_back(S2[j]);
        j++;
    }
    return ans;
}