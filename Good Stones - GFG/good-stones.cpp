//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    bool checkNode(vector<int> &arr, vector<int> &isSafe, int n, int i)
    {
        if (i < 0 || i >= n)
        {
            return true;
        }

        // looping
        if(isSafe[i] == 2)
        {
            return false;
        }

        // already determined
        if (isSafe[i] != -1)
        {
            return isSafe[i];
        }

        // case 1 : arr[i] = 0
        if (arr[i] == 0)
        {
            isSafe[i] = 0;
            return false;
        }

        // case 2 : move karo

        // inhinit looping
        isSafe[i] = 2;
        bool canMove = checkNode(arr, isSafe, n, i + arr[i]);

        if (canMove)
        {
            isSafe[i] = 1;
            return true;
        }

        isSafe[i] = 0;
        return false;
    }

public:
    int goodStones(int n, vector<int> &arr)
    {
        vector<int> isSafe(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (isSafe[i] == -1)
            {
                checkNode(arr, isSafe, n, i);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (isSafe[i] == 1)
            {
                ans++;
            }
        }

        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends