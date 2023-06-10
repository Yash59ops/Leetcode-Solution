//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            vector<int>v1;
            vector<int>v2;


            for(int i=0;i<n;i++)
            {
                if(arr[i]>=0) v1.push_back(arr[i]);
                else v2.push_back(arr[i]);
            }


            for(int i=0;i<v2.size();i++)
            {
                arr[i]=v2.at(i);
            }


            for(int i=v2.size(),j=0;i<n;i++,j++)
            {
                arr[i]=v1.at(j);
            }


        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends