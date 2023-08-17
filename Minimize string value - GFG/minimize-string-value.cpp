//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int minValue(string S, int K)
	{
	    unordered_map<char,int>map;
	    priority_queue<int>q;
	    int ans=0;
	    for(auto i:S)map[i]++;
	    for(auto i:map)q.push(i.second);
	    while(K--){
	        int num=q.top();
	        if(num==0)return 0;
	        q.pop();q.push(num-1);
	    }
	    while(q.size()>0){
	        int num=q.top();
	        ans+=(num*num);
	        q.pop();
	    }
	    return ans;
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