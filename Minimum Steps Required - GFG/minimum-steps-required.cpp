//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
   char a='a';
   int cnt_a=0;
   bool strike=false;
   for(int i=0;i<str.length();i++){
       if(str[i]=='a' && !strike){
           cnt_a++;
           strike=true;
       }else if(str[i]!=a &&  strike){
           strike=false;
       }
   }
   char b='b';
   int cnt_b=0;
   strike=false;
   for(int i=0;i<str.length();i++){
       if(str[i]==b && !strike){
           cnt_b++;
           strike=true;
       }else if(str[i]!=b &&  strike){
           strike=false;
       }
   }
   return cnt_a==cnt_b?cnt_a+1:max(cnt_a,cnt_b);
   
   
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends