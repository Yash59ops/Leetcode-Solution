//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
      vector<int>temp(26,-1);
       for (int i=0;i<s.size();i++)
      {
          if (temp[s[i]-'a']==-1)
          temp[s[i]-'a']=i;
          else temp[s[i]-'a']=-2;
      }
      int ans=s.size();
      for (int i=0;i<26;i++)
      {
          if (temp[i]>=0)
          ans=min(ans,temp[i]);
      }
      if (ans==s.size()) return '$';
      
      return s[ans];
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends