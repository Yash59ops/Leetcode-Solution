//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>>q;
        vector<int>dist(100000,1e9);
        dist[start]=0;
        q.push({0,start});
        while(!q.empty()){
            int node=q.front().second;
            int step=q.front().first;
            q.pop();
            if(node==end){
                return step;
            }
            for(auto it:arr){
                int num=(node*it)%100000;
                if(dist[num]>1+step){
                    dist[num]=1+step;
                    q.push({step+1,num});
                }
            }
            
        }
        return -1;
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
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends