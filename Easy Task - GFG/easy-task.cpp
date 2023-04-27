//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> seg;
    void build(int ind,int l,int r,string &s){
        if(l==r) {seg[ind][s[l]-'a'] = 1;}
        if(l>=r) return;
        int m = (l+r)/2;
        build(2*ind+1,l,m,s);
        build(2*ind+2,m+1,r,s);
        for(int i=0;i<26;i++) seg[ind][i] = seg[2*ind+1][i] + seg[2*ind+2][i];
    }
    void update(int ind,int l,int r,int pos,char c,string &s){
        if(l>r) return;
        if(l==r && l==pos){
            seg[ind][s[l]-'a']--;
            s[l]=c;
            seg[ind][c-'a']++;
            return;
        }
        if(pos<l || pos>r) return;
        int m = (l+r)/2;
        update(2*ind+1,l,m,pos,c,s);
        update(2*ind+2,m+1,r,pos,c,s);
        for(int i=0;i<26;i++) seg[ind][i] = seg[2*ind+1][i] + seg[2*ind+2][i];
    }
    vector<int> query(int ind,int l,int r,int low,int high){
        if(l>high || r<low){
            vector<int> arr(26,0);
            return arr;
        }
        if(l>=low && r<=high) return seg[ind];
        int m = (l+r)/2;
        vector<int> left = query(2*ind+1,l,m,low,high);
        vector<int> right = query(2*ind+2,m+1,r,low,high);
        vector<int> ans(26,0);
        for(int i=0;i<26;i++) ans[i] = left[i]+right[i];
        return ans;
    }
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        seg = vector<vector<int>>(4*(n+1),vector<int>(26,0));
        build(0,0,n-1,s);
        vector<char> ans;
        for(auto &i:queries){
            if(i[0]=="1"){
                int ind = stoi(i[1]);
                char c = i[2][0];
                update(0,0,n-1,ind,c,s);
            }
            else{
                int low = stoi(i[1]);
                int high = stoi(i[2]);
                int k = stoi(i[3]);
                vector<int> arr = query(0,0,n-1,low,high);
                
                int sum =0;
                for(int j=25;j>=0;j--){
                    if(sum+arr[j]<k) sum+=arr[j];
                    else{
                        ans.push_back(j+'a');
                        break;
                    }
                }
            }
        }
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
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends