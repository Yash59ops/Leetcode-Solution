//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
          queue<pair< int  , int >>q ;

        

        q.push({ x-1 , y-1 }) ;

        

        vector<vector<bool>>vis( N , vector<bool>( M , false )) ;

        

        vis[x-1][y-1] = false ;

        

        int count = 0 ;

        

        int row[4] = { -1 , 1  , 0 , 0 } ;

        int col[4] = { 0 , 0 , -1  , 1 } ;

        

        while(!q.empty())

        {

            int n = q.size() ;

            

            for( int i = 0 ; i < n ; i++ )

            {

                auto it = q.front() ;

                q.pop() ;

                

                for( int k = 0 ; k < 4 ; k++ )

                {

                    int nx = it.first + row[k] ;

                    int ny = it.second + col[k] ;

                    

                    if( nx >= 0 && nx < N && ny >= 0 && ny < M )

                    {

                        if(!vis[nx][ny])

                        {

                            vis[nx][ny] = true ;

                            q.push({ nx , ny }) ;

                        }

                    }

                }

            }

            

            count++ ;

        }

        

        return count-1 ;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends