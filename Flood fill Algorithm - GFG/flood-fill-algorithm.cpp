//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&arr,int new_color,vector<vector<int>>&vis,int old_color){
        if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size() || vis[i][j] || arr[i][j]!=old_color){
            return;
        }
        vis[i][j]=1;
        arr[i][j]=new_color;
        dfs(i+1,j,arr,new_color,vis,old_color);
        dfs(i-1,j,arr,new_color,vis,old_color);
        dfs(i,j+1,arr,new_color,vis,old_color);
        dfs(i,j-1,arr,new_color,vis,old_color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
     int row=image.size();
     int col=image[0].size();
     int oldcolor=image[sr][sc];
     vector<vector<int>>vis(row,vector<int>(col,0));
     dfs(sr,sc,image,newColor,vis,oldcolor);
     return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends