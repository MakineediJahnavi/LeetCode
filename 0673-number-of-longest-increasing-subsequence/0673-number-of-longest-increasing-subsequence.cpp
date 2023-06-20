class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> ct(n,1);
        int maxlen=1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]>nums[j]) {
                    if (dp[i]<1+dp[j]) {
                        dp[i]=1+dp[j];
                        ct[i]=ct[j];
                    }
                    else if (dp[i]==1+dp[j])
                        ct[i]+=ct[j];
                }
            }
            maxlen=max(maxlen,dp[i]);
        }
        int ans=0;
        for(int i=0; i<n; i++) {
            if(dp[i]==maxlen)
                ans+=ct[i];
        }
        return ans;
    }
};