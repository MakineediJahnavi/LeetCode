class Solution {
private:
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1; i<n; i++) {
            int take;
            if(i>=2)
                take = nums[i]+dp[i-2];
            else
                take=nums[i];
            int noTake=dp[i-1];
            dp[i]=max(take,noTake);
        }
        return dp[n-1];
    }
};