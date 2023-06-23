class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<int,int>> dp(n);
        int ans=0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dif=nums[j]-nums[i];
                if(dp[i].count(dif))
                    dp[j][dif]=dp[i][dif]+1;
                else
                    dp[j][dif]=2;
                ans=max(ans,dp[j][dif]);
            }
        }
        return ans;
    }
};