//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int mini=INT_MAX;
        int maxi=INT_MIN;
       int price=0;
       int free=N-1;
       int buy=0;
       while(price<=free){
           int v=candies[price];
           buy+=v;
           price++;
           free-=K;
       }
       mini=buy;
       buy=0;
       price=N-1;
       free=0;
        while(price>=free){
            int v=candies[price];
            buy+=v;
            price--;
            free+=K;
        }
        maxi=buy;
        vector<int>ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends