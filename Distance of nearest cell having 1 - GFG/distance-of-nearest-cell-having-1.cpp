//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int row=grid.size();
	    int col=grid[0].size();
	   vector<vector<int>>ans(row,vector<int>(col,0));
	   vector<vector<int>>vis(row,vector<int>(col,0));
      queue<pair<pair<int,int>,int>>q;
	   for(int i=0;i<row;i++){
	       for(int j=0;j<col;j++){
	           if(grid[i][j]==1){
	               q.push({{i,j},0});
	               vis[i][j]=1;
	           }
	       }
	   }
	   vector<pair<int,int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};
	   while(!q.empty()){
	       int x=q.front().first.first;
	       int y=q.front().first.second;
	       int d=q.front().second;
	       q.pop();
	       ans[x][y]=d;
	       for(auto it:dirs){
	           int x_=x+it.first;
	           int y_=y+it.second;
	           if(x_>=0 && y_>=0 && x_<row && y_<col && !vis[x_][y_] && grid[x_][y_]==0){
	               q.push({{x_,y_},d+1});
	               vis[x_][y_]=1;
	           }
	       }
	   }
	   
	   
	   
	   return ans;
	   
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends