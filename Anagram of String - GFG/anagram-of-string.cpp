//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
// Your code goes here
unordered_map<char,int> mp;
 for(int i=0;i<str1.size();i++)
 mp[str1[i]]++;
 int count=0;
 for(int i=0;i<str2.size();i++)
 {
     if(mp.find(str2[i])!=mp.end())
     {
         mp[str2[i]]--;
         if(mp[str2[i]]==0)
         mp.erase(str2[i]);
     }
     else
     count++;
 }
 for(auto it:mp)
 count+=it.second;
 return count;
}