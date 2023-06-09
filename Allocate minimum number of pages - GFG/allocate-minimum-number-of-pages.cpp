//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool ispossible(int a[],int size,int total_stu,int mid){
        int stu=1;
        int sum=0;
        for(int i=0;i<size;i++){
            if(sum+a[i]<=mid){
                sum+=a[i];
            }else{
                stu++;
                if(stu>total_stu || a[i]>mid){
                    return false;
                }
                sum=a[i];
            }
            if(stu>total_stu){
                return false;
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        if(N<M)return -1;
        int low=0;
        int high=0;
        for(int i=0;i<N;i++){
            low = max(low,A[i]);
            high+=A[i];
        }
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(ispossible(A,N,M,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends