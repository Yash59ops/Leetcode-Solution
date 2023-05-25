//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void dfs(vector<vector<int>>&arr,vector<vector<int>>&vis,int i,int j,int new_,int old){
    if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size() || vis[i][j] || arr[i][j]!=old){
        return;
    }
    
    vis[i][j]=1;
    arr[i][j]=new_;
    dfs(arr,vis,i+1,j,new_,old);
    dfs(arr,vis,i,j+1,new_,old);
    dfs(arr,vis,i-1,j,new_,old);
    dfs(arr,vis,i,j-1,new_,old);
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       int oldimage=image[sr][sc];
       int row=image.size();
       int col=image[0].size();
       vector<vector<int>>vis(row,vector<int>(col,0));
       dfs(image,vis,sr,sc,newColor,oldimage);
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