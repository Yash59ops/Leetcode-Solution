//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool janta_hai_kya(vector<vector<int>>&A,int a,int b){
        if(A[a][b]==1){
            return true;
        }else
        {
            return false;
        }
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int>st;
       for(int i=0;i<n;i++){
           st.push(i);
       }
       while(st.size()>1){
           int a=st.top();
           st.pop();
           int b=st.top();
           st.pop();
           if(janta_hai_kya(M,a,b)){
               st.push(b);
           }else{
               st.push(a);
           }
       }
       int ans=st.top();
       int count=0;
       for(int i=0;i<n;i++){
           if(M[ans][i]==0){
               count++;
           }
       }
       if(count!=n){
           return -1;
       }
       count=0;
       for(int i=0;i<n;i++){
           if(M[i][ans]==1){
               count++;
           }
       }
       if(count!=n-1){
           return -1;
       }
       st.pop();
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
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends