//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string>ans;
        for(auto i:Dictionary){
            string temp;
            for(int j=0;j<i.length();j++){
                if(i[j]>='A' && i[j]<='Z'){
                    temp.push_back(i[j]);
                }
            }
            int l=temp.find(Pattern);
            if(l==0){
                ans.push_back(i);
            }
        }
        if(ans.empty()){
            ans.push_back("-1");
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends