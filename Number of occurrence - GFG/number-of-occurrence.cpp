//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
int FO(int arr[], int n , int x)

{

    int s=0;

    int e=n-1;

    int ans=-1;

    

    while(s<=e)

    {

        int mid=s+(e-s)/2;

        if(arr[mid]==x)

        {

            ans=mid;

            e=mid-1;

        }

        else if(x>arr[mid])

        {

            s=mid+1;

        }

        else

        {

            e=mid-1;

        }

    }

     return ans;

}

 

int LO(int arr[], int n , int x)

{

    

    int s=0;

    int e=n-1;

    int ans1=-1;

    

    while(s<=e)

    {

        int mid=s+(e-s)/2;

        if(arr[mid]==x)

        {

            ans1=mid;

            s=mid+1;

        }

        else if(x>arr[mid])

        {

            s=mid+1;

        }

        else

        {

            e=mid-1;

        }

    }

     return ans1;

}

 

int count(int arr[], int n, int x) {

    int a = FO(arr,n,x);

    int b=  LO(arr,n,x);

    

    if(a==-1 && b==-1)

    return 0;

    

    int c=b-a+1;

    return c;

 }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends