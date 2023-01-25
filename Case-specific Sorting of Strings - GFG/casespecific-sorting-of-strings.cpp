//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string small="";
        string big="";
        for(int i=0;i<n;i++){
            if(str[i]>='a' && str[i]<='z'){
                small+=str[i];
            }else{
                big+=str[i];
            }
        }
        sort(small.begin(),small.end());
        sort(big.begin(),big.end());
        string ans="";
        int count_small=0;
        int count_big=0;
        for(int i=0;i<n;i++){
            if(str[i]>='a' && str[i]<='z'){
                ans+=small[count_small];
                count_small++;
            }else{
                ans+=big[count_big];
                count_big++;
            }
        }
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
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends