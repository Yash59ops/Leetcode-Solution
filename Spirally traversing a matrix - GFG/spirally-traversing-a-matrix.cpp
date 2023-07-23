//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
  vector<int> spirallyTraverse(vector<vector<int>>& matrix, int rows, int cols) 
    {
vector<int> result;
        int counter = 0;
        while (true) 
        {
            // Traverse the top row from left to right.
            for (int i = counter; i < cols - counter; i++)
                result.push_back(matrix[counter][i]);
            if (result.size() == rows * cols)
                break;

            // Traverse the rightmost column from top to bottom.
            for (int i = counter + 1; i < rows - counter; i++)
                result.push_back(matrix[i][cols - 1 - counter]);
            if (result.size() == rows * cols)
                break;

            // Traverse the bottom row from right to left.
            for (int i = cols - 2 - counter; i >= counter; i--)
                result.push_back(matrix[rows - 1 - counter][i]);
            if (result.size() == rows * cols)
                break;

            // Traverse the leftmost column from bottom to top.
            for (int i = rows - 2 - counter; i > counter; i--)
                result.push_back(matrix[i][counter]);
            if (result.size() == rows * cols)
                break;

            counter++;
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends