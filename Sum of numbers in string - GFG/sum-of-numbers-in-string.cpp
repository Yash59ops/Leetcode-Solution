//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	  int sum=0;
        string num="";
        for(int i=0;i<str.length();i++){
            if(str[i]>='0' && str[i]<='9'){
                num+=str[i];
            }
            else{
                if(num!=""){
                sum+=stoi(num);
                }
                num="";
            }
        }
         if(num!=""){
           sum+=stoi(num);
         }
        return sum;
    	// Your code here
    	
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}

// } Driver Code Ends