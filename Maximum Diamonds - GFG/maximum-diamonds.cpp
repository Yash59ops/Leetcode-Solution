//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
       long long ans = 0;
        priority_queue<int, vector<int>> pq;
        for(int i=0;i<N;i++)
        {
            pq.push(A[i]);
        }
        for(int i=0;i<K;i++)
        {
            int mxval = pq.top();
            pq.pop();
            ans += mxval;
            pq.push(mxval/2);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends