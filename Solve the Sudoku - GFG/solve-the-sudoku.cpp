//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
  bool isSafe(int val,int grid[9][9],int row,int col){

        for(int i=0;i<9;i++)if(grid[row][i]==val || grid[i][col]==val || grid[3*(row/3)+i/3][3*(col/3)+i%3]==val)return 0;return 1;

    }

    bool SolveSudoku(int grid[N][N])  

    { 

        for(int i=0;i<9;i++){

            for(int j=0;j<9;j++){

                if(grid[i][j]==0){

                    for(int val=1;val<10;val++){

                        if(isSafe(val,grid,i,j)){

                            grid[i][j]=val;

                            if(SolveSudoku(grid))return 1;

                            else grid[i][j]=0;

                        }

                    }return 0;

                }

            }

        }return 1;

    }

    

    //Function to print grids of the Sudoku.

    void printGrid (int grid[N][N]) 

    {

       for(int i=0;i<9;i++){

           for(int j=0;j<9;j++){

               cout<<grid[i][j]<<" ";

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
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends