//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  string ans="";
  int count = 1;
  int i=1;
  for( i=1; i<(int)src.size(); i++)
  {   
      if(src[i-1] == src[i])
      {
          count++;
      }
      else if(src[i] != src[i-1])
      {
          ans += src[i-1];
          ans += count + '0';
          count = 1;
      }
     
  }
      ans += src[i-1];
      ans += count + '0';
      
  return ans; 
}     
 
