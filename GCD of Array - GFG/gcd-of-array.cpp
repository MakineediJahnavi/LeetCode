//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    int fun(int a,int b) {
        if(a==0)
            return b;
        return fun(b%a,a);
    }
    int gcd(int N, int arr[])
    {
        int ans=arr[0];
    	for(int i=1; i<N; i++) {
    	    ans=fun(arr[i],ans);
    	    if(ans==1)
    	        return 1;
    	}
    	return ans;
    }
};


//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int arr[N];
        for(int i = 0; i < N; i++)
        	cin >> arr[i];
        Solution ob;
       	cout <<  ob.gcd(N, arr) << "\n";
   
    }
    return 0;
}
// } Driver Code Ends