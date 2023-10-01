//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void minself(int &a, int b) { a = min(a, b); }
public:
    int solveWordWrap(vector<int>nums, int k) 
    {
        int n = nums.size();
        int dp[n]; // minimum cost if last line ends at word i
        const int inf = 1e9;
        fill(&dp[0], &dp[0] + n, inf);
        for (int i = 0; i < n; i++) {
            int lettercnt = 0, spaces = 0;
            // words on the current line
            for (int j = i; j >= 0; j--) {
                if (lettercnt + nums[j] + spaces > k) break;
                lettercnt += nums[j];
                int remspace = k - lettercnt - spaces;
                minself(dp[i], ((j - 1) >= 0 ? dp[j - 1] : 0) + (i != n - 1) * remspace * remspace);
                spaces++;
            }
        }
        return dp[n - 1];
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends