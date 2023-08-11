//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    class node{
      public:
      int data;
      int apos,vpos;
      node(int v,int i,int j){
          this->data=v;
          this->apos=i;
          this->vpos=j;
      }
    };
    class compare{
        public:
        bool operator()(node*a,node*b){
            return a->data>b->data;
        }
        
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>ans;
        priority_queue<node*,vector<node*>,compare>pq;
        for(int i=0;i<K;i++){
            node*temp=new node(arr[i][0],i,0);
            pq.push(temp);
        }
        while(!pq.empty()){
            node*cur=pq.top();
            ans.push_back(cur->data);
            pq.pop();
            int arr_pos=cur->apos;
            int index=cur->vpos;
            if(index+1<arr[arr_pos].size()){
                node*n=new node(arr[arr_pos][index+1],arr_pos,index+1);
                pq.push(n);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends