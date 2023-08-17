//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int minValue(string S, int K)
	{
	    if(K>S.length()){
            return 0;
        }
        unordered_map<char,int>m;
        for(int i=0;i<S.length();i++){
            m[S[i]]++;
        }
         while(K){
           int maxi=INT_MIN;
           char ch;
           for(auto i:m){
               if(i.second>maxi){
                   ch=i.first;
                   maxi=i.second;
               }
           }
           m[ch]--;
           K--;
       }
          int count=0;
       
       for(auto i:m){
           count=count+i.second*i.second;
       }
       return count;
	}
};

//{ Driver Code Starts.

int main() 
{
   
   
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		int k;
   		cin >> k;
        Solution ob;

   		cout << ob.minValue(s, k);

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends