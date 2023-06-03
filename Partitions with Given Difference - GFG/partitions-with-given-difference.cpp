//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod=1e9+7;
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(auto it:arr)
            sum+=it;
        int target=sum-d;
        if(target<0 || target%2!=0)
            return 0;
        target=(sum-d)/2;
        vector<int> dp(target+1,0);
        if(arr[0]==0)
            dp[0]=2;
        else
            dp[0]=1;
        if(arr[0]!=0&&arr[0]<=target)
            dp[arr[0]]=1;
        for(int i=1; i<n; i++) {
            vector<int> temp(target+1,0);
            for(int j=0; j<=target; j++) {
                int notake=dp[j];
                int take = 0;
                if(j>=arr[i])
                    take=dp[j-arr[i]];
                temp[j]=(take+notake)%mod;
            }
            dp=temp;
        }
        return dp[target];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends