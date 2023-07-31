//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool minimumPlatform2(vector<int> &arr,vector<int> &dep,vector<int> &days,int platforms){
       int n=arr.size();
        if(n==1)return true;
    
    int maxDays=*max_element(days.begin(),days.end());
    int maxDep=*max_element(dep.begin(),dep.end());
    
    int a[maxDays][maxDep+1];
    for(int i=0;i<maxDays;i++)
    for(int j=0;j<=maxDep;j++)
    a[i][j]=0;
    
    for(int i=0;i<n;i++)
    {
        int l=arr[i];
        int h=dep[i];
        
        // Note: If 2 trains arrive and depart on the same time on the same day on
        // the same platform then depart the train first then second train arrives.
        while(l<h)
        {
         a[days[i]-1][l++]++;
        }
        
    }
    int mx=INT_MIN;
    for(int i=0;i<maxDays;i++)
    {
        mx=max(mx,*max_element(a[i],a[i]+maxDep+1));
    }
    
   if(mx<=platforms)
   return true;
   else
   return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string p;
        getline(cin,p);
        string s;
        getline(cin,s);
        stringstream str(s);
        string ele;
        vector<int> arr;
        while(str >> ele){
            arr.push_back(stoi(ele));
        }
        int n=arr.size();
        vector<int> dep(n),days(n);
        for(int i=0;i<n;i++){
            cin>>dep[i];
        }
        for(int i=0;i<n;i++){
            cin>>days[i];
        }
        int platforms;
        cin>>platforms;
        Solution ob;
        if(ob.minimumPlatform2(arr,dep,days,platforms)){
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
    }
}
// } Driver Code Ends