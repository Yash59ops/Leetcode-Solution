//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
   public:

    static bool cmp(vector<int>& a, vector<int>& b){

        if(a[0] == b[0] && a[1]==b[1]) return a[2] > b[2];

        else if(a[0] == b[0]) return a[1]>b[1];// this is done for decreasing order

        else

            return a[0]<b[0];

    }

    

    int func(int ind, int prev, vector<vector<int>>& boxes,vector<vector<int>>&dp){

        

       

        if(ind == boxes.size()) return 0;



        if(dp[ind][prev+1]!=-1)   return dp[ind][prev+1];

        

        int notTake = func(ind+1,prev,boxes,dp);

        int take = -1;

        

        if(prev == -1 || (boxes[ind][0] > boxes[prev][0] && boxes[ind][1] > boxes[prev][1]))

            take = boxes[ind][2] + func(ind+1,ind,boxes,dp);

            

        return dp[ind][prev+1] = max(take,notTake);

        

    }

    

    int maxHeight(int height[],int width[],int length[],int n)

    {

       // W * L * H

       vector<vector<int>> boxes;

       

       for(int i=0;i<n;i++){

           boxes.push_back({height[i],width[i],length[i]});

           boxes.push_back({height[i],length[i],width[i]});

           boxes.push_back({width[i],length[i],height[i]});

           boxes.push_back({width[i],height[i],length[i]});

           boxes.push_back({length[i],height[i],width[i]});

           boxes.push_back({length[i],width[i],height[i]});

       }

       

       sort(boxes.begin(),boxes.end(),cmp);

       

       int s = boxes.size();

       //Now I guess applying LSI on heights will work, the memonization way

       

       vector<vector<int>> dp(s,vector<int>(s+1,-1));

       

       return func(0,-1,boxes,dp);

       

    }

};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	
// } Driver Code Ends