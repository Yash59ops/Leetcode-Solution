//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int n,string s, vector<int> &P) {
      unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[P[i]]=i;
        int i=0;
        int ans=-1;
        while(i<n-1)
        {
            if(s[i]==s[i+1])
            {
                if(mp[i]<mp[i+1])
                {
                    s[i]='?';
                }
                else
                {
                    s[i+1]='?';
                }
                ans=max(ans,min(mp[i],mp[i+1]));
            }
            i++ ;
        }
        return ans+1 ;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends