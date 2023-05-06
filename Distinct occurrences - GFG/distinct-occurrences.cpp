//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string S, string T)
    {
     vector<vector<long long >> dp(S.length()+1,vector<long long>(T.length()+1,0));

        for(int i = 0;i<=T.length();i++)

        {

            dp[S.size()][i] = 0;

        }

        for(int j = 0;j<=S.length();j++)

        {

            dp[j][T.size()] = 1;

        }

        for(int i = S.length()-1;i>=0;i--)

        {

            for(int j = T.length()-1;j>=0;j--)

            {

                if(S[i]==T[j])

                {

                    dp[i][j] = (dp[i+1][j+1]%1000000007 + dp[i+1][j]%1000000007)%1000000007;

                }

                else

                {

                    dp[i][j] = dp[i+1][j]%1000000007;

                }

            }

        }

        return dp[0][0];

        
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends