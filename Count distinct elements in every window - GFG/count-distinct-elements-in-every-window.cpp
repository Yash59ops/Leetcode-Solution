//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
     unordered_map<int,int>mp;
     for(int i=0;i<k;i++){
         mp[A[i]]++;
     }
     vector<int>ans;
     ans.push_back(mp.size());
     int j=0;
     for(int i=k;i<n;i++){
         mp[A[i]]++;
         mp[A[j]]--;
         if(mp[A[j]]==0){
             mp.erase(A[j]);
         }
         ans.push_back(mp.size());
         j++;
     }
     return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends