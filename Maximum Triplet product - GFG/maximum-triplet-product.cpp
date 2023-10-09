//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
        long long first_max=INT_MIN;
        long long second_max=INT_MIN;
        long long third_max=INT_MIN;
        long long first_min=INT_MAX;
        long long second_min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=first_max)
            {
                third_max=second_max;
                second_max=first_max;
                first_max=arr[i];
            }
            
            else if(arr[i]>=second_max)
            {
                third_max=second_max;
                second_max=arr[i];
            }
            else if(arr[i]>=third_max)
            {
                third_max=arr[i];
                }
            if(arr[i]<=first_min)
            {
                second_min=first_min;
                first_min=arr[i];
            }
            else if(arr[i]<=second_min)
            {
                second_min=arr[i];
            }
        }
        return (max(first_max*second_max*third_max ,first_max*second_min*first_min));
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends