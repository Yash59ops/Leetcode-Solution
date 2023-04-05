//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void solve(string &s,int index,set<string>&st){
        if(index==s.size()){
            st.insert(s);
            return;
        }
        
        for(int i=index;i<s.size();i++){
            
            swap(s[index],s[i]);
            solve(s,index+1,st);
            swap(s[index],s[i]);
        }
    }
		vector<string>find_permutation(string S)
		{
		   int n=S.size();
            set<string>st;
            
            solve(S,0,st);
            vector<string>ans;
            for(auto i:st){
                ans.push_back(i);
            }
            sort(ans.begin(),ans.end());
            return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends