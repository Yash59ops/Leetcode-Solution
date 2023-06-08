//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
 void nextPermutation(vector<int>& nums) {
   int n=nums.size();
        int index1,index2,i;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index1=i;
                break;
            }
        }
        if(i<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(i=nums.size()-1;i>=0;i--){
            if(nums[index1]<nums[i]){
                index2=i;
                break;
            }
        }
        swap(nums[index1],nums[index2]);
        reverse(nums.begin()+index1+1,nums.end());
    }
    string kthPermutation(int n, int k)
    {
     vector<int>a;
     int l=n;
     int i=1;
     while(l--){
         a.push_back(i);
         i++;
    }
   
 
i=0;
     while(i<k-1){
         nextPermutation(a);
       i++;
     }
    int num=0;
    for(auto it:a){
       num=num*10+it;
    }
    
    string stri = to_string(num);
     return stri;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends