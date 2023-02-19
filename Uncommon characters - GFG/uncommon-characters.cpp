//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
           vector<int> freq1(26,0);

            vector<int> freq2(26,0);

            set<char>s;

            

            for(auto ch:A){

                

                freq1[ch-'a'] = 1;

                

            }

            

            for(auto ch:B){

                

                freq2[ch-'a'] = 1;

                

            }

            string ans ="";

            

            

            for(int i=0;i<26;i++){

                

                if(freq1[i]^freq2[i]!=0){

                    

                    ans+= ('a'+i);

                    

                }

                

                

            }

            

            if(ans.size()==0){

                

                return "-1";

            }

            else

            

            return ans;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends