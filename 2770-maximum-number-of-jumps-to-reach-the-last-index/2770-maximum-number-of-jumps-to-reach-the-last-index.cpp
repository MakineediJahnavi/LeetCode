class Solution {
private:
    int maxj(int i,vector<int> &nums,vector<int> &dp,int &w) {
        if(i==nums.size()-1) {
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MIN;
        for(int ind=i+1; ind<nums.size(); ind++) {
            if(abs(nums[i]-nums[ind])<=w) {
                ans = max(ans,1+maxj(ind,nums,dp,w));
            }
        }
        return dp[i]=ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        int jumps=maxj(0,nums,dp,target); 
        if(jumps<0)
            return -1;
        return jumps;
    }
};