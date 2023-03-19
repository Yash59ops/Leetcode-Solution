//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
 queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(N,vector<int>(M,0));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]=='X')
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        int ans=INT_MAX;
        int xx[]={-1,0,1,0};
        int yy[]={0,1,0,-1};
        while(!q.empty())
        {
            int dis=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            
            if(grid[x][y]=='Y')
            {
                ans=min(ans,dis);
            }
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newx=x+xx[i];
                int newy=y+yy[i];
                
                if(newx>=0 && newx<N && newy>=0 && newy<M && !vis[newx][newy])
                {
                    q.push({(abs(newx-x)+abs(newy-y)+dis),{newx,newy}});
                    vis[newx][newy]=1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends