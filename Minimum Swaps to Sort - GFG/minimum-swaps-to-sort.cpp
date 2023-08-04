//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	  vector<pair<int,int>>vec;
	  for(int i=0;i<nums.size();i++){
	      vec.push_back({nums[i],i});
	  }
	  sort(vec.begin(),vec.end());
	  int cnt=0;
	  for(int i=0;i<vec.size();i++){
	      if(vec[i].second!=i){
	          swap(vec[i],vec[vec[i].second]);
	          cnt++;
	          i--;
	      }
	  }
	  return cnt;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends