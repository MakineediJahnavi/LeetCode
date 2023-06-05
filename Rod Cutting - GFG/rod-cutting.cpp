//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++) {
            dp[i]=price[0]*i;
        }
        for(int i=1; i<n; i++) {
            vector<int> cur(n+1,0);
            for(int j=0; j<=n; j++) {
                int notake=dp[j];
                int take=0;
                if(i+1<=j)
                    take=price[i]+cur[j-i-1];
                cur[j]=max(take,notake);
            }
            dp=cur;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends