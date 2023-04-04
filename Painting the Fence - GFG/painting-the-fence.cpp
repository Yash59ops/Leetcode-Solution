//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
 
const int mod =1e9+7;
    long long countWays(int n, int k){
        // code here
        
        vector<long long >same;
        vector<long long >diff;
        if(n==1)return k;
        same.push_back(k);
        long long x=(k*(k-1))%mod;
        diff.push_back(x);
        for(int i=3;i<=n;i++)
        {
            long long curr=(same.back()*(k-1))%mod;
            
            long long temp=diff.back()%mod;
            curr+=(temp*(k-1)%mod);
            diff.push_back(curr);
            same.push_back(temp);
            
        }
        long long ans=same.back()%mod;
        ans+=(diff.back()%mod);
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends