//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    int n=N;
	    int x=TargetPos[0]-1;
	    int y=TargetPos[1]-1;
	    int sr=KnightPos[0]-1;
	    int sc=KnightPos[1]-1;
	    if(x==sr && y==sc){
	        return 0;
	    }
	    vector<vector<int>>vis(n,vector<int>(n,0));
	    queue<pair<int,int>>q;
	    q.push({sr,sc});
	    vis[sr][sc]=1;
	    int ans=0;
	    while(!q.empty()){
	        int num=q.size();
	        ans++;
	        while(num--){
	            int xx=q.front().first;
	            int yy=q.front().second;
	            q.pop();
	             int ax[8] = {1, 1, -1, -1, 2, -2, 2, -2};
	            int ay[8] = {2, -2, 2, -2, 1, 1, -1, -1};
	            for(int i=0;i<8;i++){
	                int x_=xx+ax[i];
	                int y_=yy+ay[i];
	                if(x_==x && y_==y){
	                    return ans;
	                }
	                if(x_>=0 && x_<n && y_>=0 && y_<n && !vis[x_][y_]){
	                    q.push({x_,y_});
	                    vis[x_][y_]=1;
	                }
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
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends