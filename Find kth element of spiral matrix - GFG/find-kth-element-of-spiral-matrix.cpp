//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 	    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    int direction = 0; // 0: left to right, 1: top to bottom, 2: right to left, 3: bottom to top

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            for (int i = left; i <= right; i++) {
                k--;
                if (k == 0)
                    return a[top][i];
            }
            top++;
            direction = 1;
        } else if (direction == 1) {
            for (int i = top; i <= bottom; i++) {
                k--;
                if (k == 0)
                    return a[i][right];
            }
            right--;
            direction = 2;
        } else if (direction == 2) {
            for (int i = right; i >= left; i--) {
                k--;
                if (k == 0)
                    return a[bottom][i];
            }
            bottom--;
            direction = 3;
        } else if (direction == 3) {
            for (int i = bottom; i >= top; i--) {
                k--;
                if (k == 0)
                    return a[i][left];
            }
            left++;
            direction = 0;
        }
    }

    return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends