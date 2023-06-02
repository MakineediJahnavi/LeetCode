//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=arr[i];
        vector<bool> dp(sum+1,0);
        dp[0]=true;
        if(arr[0]<=sum)
            dp[arr[0]]=true;
        for(int i=1; i<n; i++) {
            vector<bool> temp(sum+1,0);
            temp[0]=true;
            for(int j=1; j<=sum; j++) {
                bool notake=dp[j];
                bool take=false;
                if(j>=arr[i])
                    take=dp[j-arr[i]];
                temp[j]=take|notake;
            }
        dp=temp;
        }
    int min_dif=INT_MAX;
    for(int i=0; i<=sum; i++) {
        if(dp[i])
            min_dif=min(min_dif,abs(sum-2*i));
    }
    return min_dif;
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
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends