//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    int low=0;
	    int high=N-1;
	  int mid;
	    while(low<high){
	        mid=low+(high-low)/2;
	        if(mid%2==1){
	            mid--;
	        }
	        if(A[mid]!=A[mid+1]){
	            high=mid;
	        }else
	        {
	            low=mid+2;
	        }
	    }
	    return A[low];
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends