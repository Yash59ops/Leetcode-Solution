//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
         unordered_map<int,int>mp;
        vector<int>res;
        int i=0,j=0;
         
        while(j<n){
            if(j-i<k){
                  mp[a[j]]++;
            }
            if(j-i+1==k){
                res.push_back(mp.size());
                mp[a[i]]--;
                if(mp[a[i]]==0) mp.erase(a[i]);
                i++;
            }
            j++;
        }
        return res;
        
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