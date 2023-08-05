//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    
    long long int countOfSubstringWithKOnes(string s, int k){
      unordered_map<int,int> mp;
        int res=0;
        int num=0;
        int n = s.length();
        mp[0]++;
        for(int i=0;i<n;i++)
        {
             num+=(int)(s[i]-'0');
             if(num>=k)
             {
                 res+=mp[num-k];
             }
             mp[num]++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
       string s;
       int k;
       cin >> s >> k;
       Solution ob;
       cout << ob.countOfSubstringWithKOnes(s, k) << endl;
    }
return 0;
}


// } Driver Code Ends