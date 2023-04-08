//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool sign(int n){
        if (n>=0)
            return true;
        return false;
    }
    vector<int> makeBeautiful(vector<int> arr) {
        int i = 1;
        while(i<arr.size()){
            if (sign(arr[i]) != sign(arr[i-1])){
                arr.erase(arr.begin()+i-1);
                arr.erase(arr.begin()+i-1);
                i = max(1,i-1);
            }
            else
                i++;
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends