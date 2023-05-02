//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
  int minimumDays(int S, int N, int M){
        int sunday= S/7;
        int buyingDay = S-sunday;
        int ans =0;
        int total = S*M; // itna food to chhahie use jinda rhne ke //lie
        if(total%N==0)
        ans = total/N;
        else
        ans = total/N +1;
        
          // agar N=1 M=1 S=10  means sunday ko hm nhi buy kr skte to 1 din 
        // km ho gya or 1 din men 1 din ka bojan hi buy kr skte hen to fir to mr jaega vo
       
        if(ans<=buyingDay)   return ans;
        else
        return -1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends