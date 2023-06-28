class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1; i>=0; i--) {
            int ans=INT_MIN;
            int maxi=0,l=0;
            for(int ind=i; ind<i+k; ind++) {
                if(ind>=arr.size())
                    break;
                l++;
                maxi=max(maxi,arr[ind]);
                ans=max(ans,maxi*l+dp[ind+1]);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};