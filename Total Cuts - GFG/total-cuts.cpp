//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int>small(N),large(N);
        large[0]=A[0],small[N-1]=A[N-1];
        for(int i=1;i<N;i++){
            large[i]=max(A[i],large[i-1]);
            small[N-i-1]=min(A[N-i-1],small[N-i]);
        }
        int ans=0;
        for(int i=1;i<N;i++)
            if(large[i-1]+small[i]>=K)ans++;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends