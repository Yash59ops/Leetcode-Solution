//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
         int r = matrix.size(), c = matrix[0].size();
        bool firstRow = false, firstCol = false; // to check whether first row or first col has cell with value 1
        for(int j=0;j<c;j++){
            if(matrix[0][j]==1) firstRow = true;
        }
        for(int i=0;i<r;i++){
            if(matrix[i][0]==1) firstCol = true;
        }

        // update first row and first col with 1 if corresponding row or col has any cell with value 1
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j]==1){
                    matrix[i][0] = 1;
                    matrix[0][j] = 1;
                }
            }
        }

      // finally update the row and col cell value with 1
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][0]==1 || matrix[0][j]==1) matrix[i][j] = 1;
            }
        }
        // if first col has any cell with value 1
        if(firstCol){
            for(int i=0;i<r;i++){
                matrix[i][0] = 1;
            }
        }
        // if first row has any cell with value 1
        if(firstRow){
            for(int j=0;j<c;j++){
                matrix[0][j] = 1;
                
            }
    }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends