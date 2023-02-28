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
    
    bool find(string &s, TrieNode *node, int i) {
        if(s.size() == i and node == root) return true;
        if(!node->child[s[i]-'a']) return false;
            node = node->child[s[i]-'a'];
        if(node->end and find(s,root,i+1))
            return true;
        return find(s,node, i+1);
    }
    
    int wordBreak(string A, vector<string> &B) {
        for(auto &a :B)
            insert(a);
        TrieNode *tmp = root;
        return find(A, tmp, 0);
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