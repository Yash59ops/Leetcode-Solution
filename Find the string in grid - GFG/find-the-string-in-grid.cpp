//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool f(int ind,int i,int j,vector<vector<char>>grid, string word, int dir_x , int dir_y){
    if(ind>=word.size())return true ;
    int n= grid.size() ;
    int m=grid[0].size() ;
    int row =i+dir_x ;
    int col=j+dir_y ;
    if(row>=0 and row<n and col>=0 and col<m and grid[row][col]==word[ind]){
        return f(ind+1,row,col,grid,word,dir_x,dir_y) ;
    }
    return false ;
}
    vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
        // Code here
        int di[]={1,1,1,0,0,-1,-1,-1} ;
        int dj[]={1,0,-1,-1,1,0,1,-1} ;
        set<vector<int>>s ;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==word[0]){
                    for(int k=0;k<8;k++){
                    if(f(1,i,j,grid,word,di[k],dj[k])){
                        s.insert({i,j}) ;
                    }
                    }
                }
            }
        }
        vector<vector<int>>ans ;
        for(auto it:s){
            ans.push_back(it) ;
        }
        return ans ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends