//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
     unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            string s=arr[i];
            reverse(s.begin(),s.end());
            if(m.find(s)!=m.end()&&m[s]>0){
                m[s]--;
            }
            else{
                m[arr[i]]++;
            }
        }
        for(auto i:m){
            if(i.second>0){
                string s=i.first;
                reverse(s.begin(),s.end());
                if(s!=i.first){
                    return 0;
                }
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends