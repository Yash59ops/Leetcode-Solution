//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int>dp(n+1,0);
   vector<int>dp1(n+1,0);
   int ans=INT_MIN;
   for(int i=0;i<n;i++){
       dp1[i]=arr[i];
       for(int j=0;j<i;j++){
           if(arr[i]>arr[j]){
               dp[i]=max(dp[i],dp[j]+1);
               dp1[i]=max(dp1[i],dp1[j]+arr[i]);
           }
          
       }
   }
for(int i=0;i<n;i++){
     ans=max(ans,dp1[i]);
}
return ans;
	}  
};

//{ Driver Code Starts.


// } Driver Code Ends

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends