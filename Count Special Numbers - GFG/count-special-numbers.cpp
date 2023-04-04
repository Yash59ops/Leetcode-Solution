//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
        int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
         int count = 0;
         map<int,int>m;
         for(int i=0;i<N;i++)m[arr[i]]++;
 
 
    // loop to traverse through array elements
    // and check for its factors
    for (int i = 0; i < N; i++) {
        m[arr[i]]--;  //because a number divides itself,so we nullify this
        if(m[arr[i]]==0)m.erase(arr[i]);
 
        // generate factors of elements
        // of the array
        for (int j = 1; j  <= sqrt(arr[i]); j++) {
 
            // Check if j is a factor
            if (arr[i] % j == 0) {
 
                // check if the factor is present in
                // rest of the array using the map
                if ((m.find(j) != m.end()) ||
                        (m.find(arr[i] / j) != m.end())) {
                    count++;
                    break;
                }
            }
        }
        m[arr[i]]++;
    }

 
    return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends