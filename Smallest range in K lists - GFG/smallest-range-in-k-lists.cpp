//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
         vector<pair<int,int>>vec;
         unordered_map<int,int>mp;
         for(int i=0;i<k;i++){
             for(int j=0;j<n;j++){
                 vec.push_back({KSortedArray[i][j],i});
             }
         }
         sort(vec.begin(),vec.end());
         int i=0,j=0,mini=INT_MAX,e1=0,e2=0;
         while(j<vec.size()){
             mp[vec[j].second]++;
             while(i<=j && mp.size()==k){
                  if(vec[j].first - vec[i].first<mini)
                {
                    e1=vec[i].first;
                    e2=vec[j].first;
                    mini=e2-e1;
                }
                mp[vec[i].second]--;
                if(mp[vec[i].second]==0)
                    mp.erase(vec[i].second);  
                i++;      
             }
             j++;
         }
         pair<int,int>v;
         v=make_pair(e1,e2);
         return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends