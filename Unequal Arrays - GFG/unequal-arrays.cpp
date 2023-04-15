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
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        int x=0,y=0,s1,s2;s1=s2=0;
        for(int i:A){if(i%2)x++;s1+=i;}
        for(int i:B){if(i%2)y++;s2+=i;}
        if(s1!=s2 || x!=y)return -1;
        vector<int>a,b,c,d;
        for(int i=0;i<N;i++){
            if(A[i]%2)a.push_back(A[i]);
            else b.push_back(A[i]);
            if(B[i]%2)c.push_back(B[i]);
            else d.push_back(B[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        long long z=0;
        for(int i=0;i<a.size();i++){
            z+=(abs(c[i]-a[i]));
        }
        for(int i=0;i<b.size();i++){
            z+=(abs(d[i]-b[i]));
        }
        return z/4;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends