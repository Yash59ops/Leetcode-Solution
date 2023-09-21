//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
         int m;

    int count=0,flag=-1;

    

    for(int i=0;i<n;i++)

    {

        if(arr[i]==x)

        {

            count++;

            if(arr[i]!=arr[i-1] || i==0)

            {

               m=i; 

            }

        }

        if(arr[i]!=x)

        {

            flag++;

            if(flag==n-1)

            {

                return {-1,-1};

            }

        }

    }

    return {m,m+count-1};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends