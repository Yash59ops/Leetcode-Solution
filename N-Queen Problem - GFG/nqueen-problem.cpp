//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isSafe(int row,int col,vector<vector<int>>board,int n){
    //now for same row check if any queen is present
    int x=row,y=col;
    while(y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
    }
    //for left upper diagonal
    x=row,y=col;
    while(x>=0 &&y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    x=row,y=col;
    while(x<n &&y>=0){
        if(board[x][y]==1){
            return false;
        }
        x++;
        y--;
    }
    return true;
}
void solve(int col,vector<vector<int>>&ans,vector<int>&ds,vector<vector<int>>&board,int n){
    if(col==n){
        ans.push_back(ds);
        return ;
    }
    //now check if placing a queen is safe in each row of every column??
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            ds.push_back(row+1);
            board[row][col]=1;
            solve(col+1,ans,ds,board,n);
            //backtrack or remove the queen from ds
            board[row][col]=0;
            ds.pop_back();
        }
    }
    
    
}
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int>ds;
        vector<vector<int>>board(n,vector<int>(n,0));
        solve(0,ans,ds,board,n);
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
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends