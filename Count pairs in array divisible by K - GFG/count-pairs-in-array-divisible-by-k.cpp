//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
           long long count=0;
       unordered_map<int,int> mp;
       for(int i=0;i<n;i++)
       A[i]=A[i]%K;
       for(int i=0;i<n;i++)
       {
           if(A[i]==0)
           count+=mp[A[i]];
           else
           count+=mp[K-A[i]];
          mp[A[i]]++;
       }
       return count;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends