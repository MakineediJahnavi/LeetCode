class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1; i>=0; i--) {
            for(int prev=n; prev>=0; prev--) {
                int notake = dp[i+1][prev];
                int take = INT_MIN;
                if(prev==0||nums[prev-1]<nums[i])
                    take = 1+dp[i+1][i+1];
                dp[i][prev]=max(take,notake);
            }
        }
        return dp[0][0];
    }
};