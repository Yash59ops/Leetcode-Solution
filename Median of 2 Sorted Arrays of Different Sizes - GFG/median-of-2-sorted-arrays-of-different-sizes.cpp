//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
           vector<int>A;
        int n=array1.size();
        int m=array2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(array1[i]<array2[j])A.push_back(array1[i++]);
            else A.push_back(array2[j++]);
        }
        while(i<n) A.push_back(array1[i++]);
        while(j<m) A.push_back(array2[j++]);
        
        int size=(n+m);
        if(size%2 == 1){
            return A[size/2];
        }
        
        return (double)((double)(A[size/2]) + (double)(A[(size/2) - 1])) / 2.0;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends