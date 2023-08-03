//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insert(stack<int>& St, int item) {
    if (St.empty()) {
        St.push(item);
    } else {
        int temp = St.top();
        St.pop();
        insert(St, item);
        St.push(temp);
    }
}
    void f(stack<int>&St){
        if(!St.empty()){
            int x=St.top();
            St.pop();
            f(St);
            insert(St,x);
        }
    }
    void Reverse(stack<int> &St){
        f(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends