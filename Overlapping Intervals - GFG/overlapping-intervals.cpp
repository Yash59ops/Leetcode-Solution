//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
       vector<vector<int>>ans;
       int i=1;
       sort(intervals.begin(),intervals.end());
       ans.push_back(intervals[0]);
       while(i<intervals.size()){
           vector<int>&last=ans.back();
          
    
           if(last[1]<intervals[i][0]){
               ans.push_back(intervals[i]);
           }else{
               last[1]=max(last[1],intervals[i][1]);
           }
           i++;
           
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends