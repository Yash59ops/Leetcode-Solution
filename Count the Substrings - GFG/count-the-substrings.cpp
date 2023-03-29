//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        int ans=0;
       for(int i=0;i<S.length();i++){
           int count_lower=0;
           int count_upper=0;
           for(int j=i;j<S.length();j++){
               if(isupper(S[j])){
                   count_upper++;
               }
               if(islower(S[j])){
                   count_lower++;
               }
               if(count_upper==count_lower){
                   ans++;
               }
           }
       }
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends