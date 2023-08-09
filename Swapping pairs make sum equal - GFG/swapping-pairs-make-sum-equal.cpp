//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++){
            sum1+=A[i];
        }
        for(int i=0;i<m;i++){
            sum2+=B[i];
        }
        int req=(sum1-sum2);
     if(req%2!=0){
         return -1;
     }   
     req=req/2;
     unordered_map<int,int>mp;
     for(int i=0;i<n;i++){
         mp[A[i]]++;
     }
     for(int i=0;i<m;i++){
         if(mp[req+B[i]]>0){
             return 1;
         }
     }
     return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends