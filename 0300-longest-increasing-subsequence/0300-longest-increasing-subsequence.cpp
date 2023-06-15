class Solution {
private:
    int fun(int i,int prev,vector<int> &nums,vector<vector<int>> &dp) {
        if(i==nums.size())
            return 0;
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        int notake = fun(i+1,prev,nums,dp);
        int take = INT_MIN;
        if(prev==0||nums[prev-1]<nums[i])
            take = 1+fun(i+1,i+1,nums,dp);
        return dp[i][prev]=max(take,notake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        fun(0,0,nums,dp);
        return dp[0][0];
    }
};