//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>q;
vector<vector<int>>vis(row,vector<int>(col,0));
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        if(grid[i][j]==1){
            q.push({i,j});
            vis[i][j]=1;
            break;
        }
    }
}
 vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
while(!q.empty()){
     auto p = q.front(); q.pop();
            for(auto d: dir) {
                int x=d[0]+p.first, y= d[1]+p.second;
                if(x >=row || x < 0|| y >= col || y < 0 || grid[x][y]==0 || vis[x][y]) 
                    continue;
                if(grid[x][y] == 2) return 1;
                q.push({x, y});
                vis[x][y] = 1;
}
}
return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends