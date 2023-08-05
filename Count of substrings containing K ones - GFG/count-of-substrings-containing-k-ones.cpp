//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    
    long long int countOfSubstringWithKOnes(string s, int k){
     int n = s.size();
        unordered_map<int ,int> p;
        int count = 0 , sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            sum += (s[i]-'0');
            if(sum == k) count++;
            if(p.find(sum-k) !=p.end())
            {
                   count += p[sum-k]; 
            }
            p[sum]++;
        }
        return count;
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