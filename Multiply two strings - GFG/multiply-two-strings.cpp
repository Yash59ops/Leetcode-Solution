//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string a, string b) {
      if (a=="0" || b=="0"){
          return "0";
       }
       
        //check negative a or not ;
        bool a_neg =  a[0] =='-'?true:false;
        
        //if negative erase first character '-'
        if(a[0] == '-')a.erase(a.begin());
        
        //check negative b or not ;
        bool b_neg = b[0] =='-'?true:false;
        
        //if negative erase first character '-'
        if(b[0] == '-') b.erase(b.begin());
        
        //finding the product
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        string product;
        for (int i=0; i<=m+n || carry; ++i) {
            for (int j=max(0, i-n); j<=min(i, m); ++j)
                carry += (a[m-j] - '0') * (b[n-i+j] - '0');
            product += carry % 10 + '0';
            carry /= 10;
        }
        
        //removing leading zeroes before reversing
        while(product.size() > 0 && product.back()=='0') product.pop_back();
        
        //append neg sign if any one of them is negative but not both
        //xor can be used to check if they have different sign
        if(a_neg ^ b_neg) product += '-';
        
        //reverse the  string 
        reverse(product.begin() , product.end());
        
        //return the ans
         return product;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends