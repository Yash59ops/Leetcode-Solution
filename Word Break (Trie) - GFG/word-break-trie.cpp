//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class TrieNode{
public:
    bool end = false;
    TrieNode *child[26];
    TrieNode(){
        for(int i = 0; i <26; i++)
            child[i] = NULL;
    }
};

class Solution{
    TrieNode *root = new TrieNode();
    public:
    void insert(string &A) {
        TrieNode * node = root;
        for(char c: A) {
            if(!node->child[c-'a'])
                node->child[c-'a'] = new TrieNode();
            node = node->child[c-'a'];
        }
        node->end = true;
    }
    bool search(string s){
        TrieNode*node=root;
        for(char c:s){
            if(!node->child[c-'a']){
                return false;
            }
            node=node->child[c-'a'];
        }
        return node->end;
    }
    bool find(string s, TrieNode *node) {
        if(s.size()==0){
            return true;
        }
        for(int i=1;i<=s.size();i++){
            if(search(s.substr(0,i)) && find(s.substr(i,s.size()-i),node))
            return true;
        }
        return false;
    }
    
    int wordBreak(string A, vector<string> &B) {
        for(auto &a :B)
            insert(a);
        TrieNode *tmp = root;
        return find(A, tmp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends