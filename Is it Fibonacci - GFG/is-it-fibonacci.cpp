//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
     long long sum=0;
        
        for(int i=K;i<N;i++)
        {
            
            sum=0;
            
            for(int j=i-1;j>=i-K;j--)
            {
                sum+=GeekNum[j];
            }
            GeekNum.push_back(sum);
        }
        
        return GeekNum[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends