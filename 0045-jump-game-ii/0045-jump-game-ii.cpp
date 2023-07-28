class Solution {
private: 
    int min_jumps(int i,vector<int> &nums,vector<int> &dp) {
        if(i==nums.size()-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=1e9;
        for(int j=1; j<=nums[i]; j++) {
            if((i+j)>=nums.size())
                break;
            ans=min(ans,1+min_jumps(i+j,nums,dp));
        }
        return dp[i]=ans;
    }
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return 0;
        vector<int> dp(n,-1);
        return min_jumps(0,nums,dp);
    }
};