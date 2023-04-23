//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
     int n=arr.size();
        vector<int>left(n,-1),right(n,-1);
        vector<int>v;
        for(int i=0;i<n;i++)
        {
        while(v.size()>0 && arr[v.back()]>=arr[i]) v.pop_back();
        if(v.size()>0) left[i]=v.back();
        v.push_back(i);
        }
        v.clear();
        
        for(int i=n-1;i>=0;i--)
        {
        while(v.size()>0 && arr[v.back()]>=arr[i])v.pop_back();
        if(v.size()>0) right[i]=v.back();
        v.push_back(i);
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(left[i]!=-1 && right[i]!=-1)
            {
                int l=i-left[i];
                int r=right[i]-i;
                if(l<r)      ans.push_back(left[i]);
                else if(l>r) ans.push_back(right[i]);
                else
                {
                    if(arr[left[i]]<arr[right[i]])  ans.push_back(left[i]); 
                    else if(arr[left[i]]>arr[right[i]]) ans.push_back(right[i]);
                    else
                    {
                        if(left[i]<right[i])ans.push_back(left[i]); 
                        else ans.push_back(right[i]);
                    }
                }
            }
            else if(left[i]==-1)ans.push_back(right[i]);
            else ans.push_back(left[i]);
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends