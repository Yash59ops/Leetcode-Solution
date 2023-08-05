//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
   int count=0;

        map<pair<int,int>,int>mp;

        int c0=0,c1=0,c2=0;

        

        mp[{0,0}]=1;

        

        for(int i=0;i<str.size();i++)

        {

            if(str[i]=='0')

            c0++;

            else if(str[i]=='1')

            c1++;

            else

            c2++;

            

            pair<int,int> currkey={c1-c0,c2-c1};

            

            if(mp.find(currkey)!=mp.end())

            {

                count+=mp[currkey];

            }

            mp[currkey]++;

        }

        return count;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends