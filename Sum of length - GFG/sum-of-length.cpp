//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int sumoflength(int arr[], int n) {
     unordered_set<int> s;
 /* for dry run of this question take n=11 and arr[]={5,2,1,3,3,3,3,3,5,4,4}*/
    // Initialize ending point and result
    int j = 0, ans = 0;
 
    // Fix starting point
    for (int i=0; i<n; i++)
    {
        // Find ending point for current subarray with
        // distinct elements.
        while (j < n && s.find(arr[j]) == s.end())
        {
            s.insert(arr[j]);
            j++;
        }
 
        // Calculating and adding all possible length
        // subarrays in arr[i..j]
        ans += ((j - i) * (j - i + 1))/2;
 
        // Remove arr[i] as we pick new starting point
        // from next
       s.erase(arr[i]);
    }
 
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.sumoflength(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends