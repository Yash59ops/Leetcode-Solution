//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(vector<vector<int>>&arr,int row,int col,vector<string>&ans,string a,int i,int j,vector<vector<int>>&vis){
        if(i<0 || j<0 || i>=row || j>=col || vis[i][j]==true || arr[i][j]==0){
            return;
        }
        if(i==row-1 && j==col-1){
            ans.push_back(a);
            return;
        }
        vis[i][j]=true;
        dfs(arr,row,col,ans,a+'U',i-1,j,vis);
        dfs(arr,row,col,ans,a+'D',i+1,j,vis);
        dfs(arr,row,col,ans,a+'L',i,j-1,vis);
        dfs(arr,row,col,ans,a+'R',i,j+1,vis);
        vis[i][j]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        if((m[0][0]==0)){
            return ans;
            }
        if(m[n-1][n-1]==0){
            return ans;
        }
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        int i=0;
        int j=0;
      dfs(m,n,n,ans,"",i,j,vis);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends