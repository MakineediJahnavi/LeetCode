class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        for(int i=n-1; i>=0; i--) {
            vector<int> temp(n+1,0);
            for(int prev=n; prev>=0; prev--) {
                int notake = dp[prev];
                int take = INT_MIN;
                if(prev==0||nums[prev-1]<nums[i])
                    take = 1+dp[i+1];
                temp[prev]=max(take,notake);
            }
            dp=temp;
        }
        return dp[0];
    }
};