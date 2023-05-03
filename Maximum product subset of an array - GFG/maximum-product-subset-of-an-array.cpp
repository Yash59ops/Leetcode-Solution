//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here    long long mod=1e9+7;
long long mod=1e9+7;
        long long mn=-1e8;

        long long count_pos=0,count_neg=0,count_zero=0;

        long long prod=1;

       

        for(int i=0;i<n;i++)

        {   if(a[i]<0) 

          { mn=max(mn,(long long )a[i]);

           count_neg++;

          }

            if(a[i]==0) count_zero++;

            if(a[i]>0) count_pos++;

            if(a[i]!=0)

            prod=(prod*(long long )a[i])%mod;

        }

        if(count_zero!=0&&count_neg==0&&count_pos==0) return 0;//corner case {0,0}

        if(count_neg==1&&count_zero!=0&&count_pos==0) return 0; //corner cases {-1,0}

        if(count_neg==1&&count_zero==0&&count_pos==0) return prod;//corner case {-1}

        if(prod>0)

        return prod;

        long long ans=prod/mn;

        return ans; 
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends