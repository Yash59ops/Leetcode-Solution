//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
       void help(vector<vector<int>>&m,int n,int i,int j,vector<vector<bool>>&vis,vector<string>&ans,string a){
           //bc
           if(i<0 || j<0 || i>=n || j>=n || vis[i][j]==true || m[i][j]==0)
           return;
           if(i==n-1 && j==n-1)
           {
               ans.push_back(a);
               return;
           }
           vis[i][j]=true;
           help(m,n,i-1,j,vis,ans,a+'U');
           help(m,n,i+1,j,vis,ans,a+'D');
           help(m,n,i,j+1,vis,ans,a+'R');
           help(m,n,i,j-1,vis,ans,a+'L');
           vis[i][j]=false;
       }                       
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string a="";
        vector<string>ans;
        if(m[0][0]==0){
      return ans;
  }
  if(m[n-1][n-1]==0){
      return ans;
  }
        int row=m.size();
        int col=m[0].size();
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        help(m,n,0,0,vis,ans,a);
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