//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long>next_small(long long arr[],int n){
        vector<long long>ans(n);
        stack<long long>st;
        st.push(-1);
        for(long long i=n-1;i>=0;i--){
            long long cur=arr[i];
        while(st.top()!=-1 && arr[st.top()]>=cur){
                st.pop();
            }
        ans[i]=st.top();
        st.push(i);
        }
        return ans;
    }
    vector<long long>prev_small(long long arr[],int n){
        vector<long long>ans(n);
        stack<long long>s;
        s.push(-1);
        for(long long i=0;i<n;i++){
            long long cur=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=cur){
                s.pop();
            }
        ans[i]=s.top();
        s.push(i);
        }
        return ans;
    }
    long long getMaxArea(long long arr[], int n)
    {
        long long area=INT_MIN;
        vector<long long>prev(n);
        prev=prev_small(arr,n);
        vector<long long>next(n);
        next=next_small(arr,n);
        
        for(int i=0;i<n;i++){
            long long l,b;
            l=arr[i];
           if(next[i]==-1){
               next[i]=n;
           }
            b=next[i]-prev[i]-1;
            long long g=l*b;
            area=max(area,g);
        
            area=max(area,g);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends