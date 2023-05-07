//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        string ans="";
        ans+=str[0];
        ans+=str[0];
        string check="";
        check+=str[0];
        
        string pld="";
        
        for(int i=1;i<str.length();i++){
            
            if(check.back()>=str[i]){
            check+=str[i];
            string rev=check;
        
            reverse(rev.begin(),rev.end());
            pld=check+rev;
            ans=min(ans,pld);}else{
                break;
            }
            // cout<<ans<<" ";
            
            
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends