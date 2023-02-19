//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> mat) {

        // code here

        int startRow = 0 ;

        int endRow = M-1 ;

        int startCol = 0 ;

        int endCol = N - 1;

        

        while(startRow<endRow && startCol < endCol){

           int prev=mat[startRow+1][startCol];

           //first row

           for(int i=startCol;i<=endCol;i++) swap(prev,mat[startRow][i]);

           startRow++;

           //last col

           for(int i=startRow;i<=endRow;i++) swap(prev,mat[i][endCol]);

           endCol--;

           //last row

           for(int i=endCol;i>=startCol;i--) swap(prev,mat[endRow][i]);

           endRow--;

           //first col;

           for(int i=endRow;i>=startRow;i--) swap(prev,mat[i][startCol]);

           startCol++;

           

        }

        

        return mat ;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends