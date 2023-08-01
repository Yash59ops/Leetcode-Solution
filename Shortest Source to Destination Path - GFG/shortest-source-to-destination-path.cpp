//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> v, int x1, int y1) {
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},0});
        vis[0][0]=1;
        if(x1==0 && y1==0)
        {
            return 0;
        }
        if(v[0][0]==0)
        {
            return -1;
        }
        vis[0][0]=1;
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            
            int x[]={1,0,-1,0};
            int y[]={0,-1,0,1};
            for(int i=0;i<4;i++)
            {
                int nrow=row+x[i];
                int ncol=col+y[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && v[nrow][ncol]==1)
                {
                    if( nrow == x1 && ncol == y1 )
                    {
                        return t+1;
                    }
                    vis[nrow][ncol]=1;
                    
                    q.push({{nrow,ncol},t+1});
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends