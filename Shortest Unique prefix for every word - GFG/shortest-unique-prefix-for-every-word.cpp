//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class trie{
  public:
  int freq;
  trie*child[26];
  trie(){
      for(int i=0;i<26;i++){
          child[i]=0;
      }
      freq=0;
  }
  void insert(string s,trie*root){
      trie*cur=root;
      int index;
      for(int i=0;i<s.size();i++){
          index=s[i]-'a';
          if(cur->child[index]==0){
              cur->child[index]=new trie();
          }
          cur=cur->child[index];
          cur->freq+=1;
      }
  }
  string uniqueprefix(string key,trie*root){
      string ans;
      trie*cur=root;
      int index;
      for(int i=0;i<key.size();i++){
          index=key[i]-'a';
          if(cur->child[index]->freq==1){
              ans.push_back(index+'a');
              return ans;
          }else{
              ans.push_back(index+'a');
              cur=cur->child[index];
          }
      }
      return ans;
  }
};
class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        trie*root=new trie();
        vector<string>ans;
        trie tr;
        for(int i=0;i<n;i++){
            tr.insert(arr[i],root);
        }
        for(int i=0;i<n;i++){
            ans.push_back(tr.uniqueprefix(arr[i],root));
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends