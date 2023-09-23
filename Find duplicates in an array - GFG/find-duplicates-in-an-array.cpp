//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
      vector<int>ans;
        int brr[n]={0};
        for(int i=0;i<n;i++)
        {
            brr[arr[i]]++;
        }
        
        for(int j=0;j<n;j++)
        {
            if(brr[j] > 1)
            {
              ans.push_back(j);   
            }
            
           
        }
        if(ans.size() == 0)
        {
            ans.push_back(-1);
        }
        return ans;
    }    
};      


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends