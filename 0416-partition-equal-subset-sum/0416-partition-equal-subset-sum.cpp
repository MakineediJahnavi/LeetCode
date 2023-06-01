class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)
            sum+=it;
        if(sum%2!=0)
            return false;
        int target=sum/2;
        vector<bool> dp(target+1,0);
        dp[0]=true;
        if(nums[0]<target)
            dp[nums[0]]=true;
        for(int i=1; i<nums.size(); i++){
            vector<bool> temp(target+1,0);
            temp[0]=true;
            for(int j=1; j<=target; j++) {
                bool notake=dp[j];
                bool take=false;
                if(j>=nums[i])
                    take=dp[j-nums[i]];
                temp[j]=take|notake;
            }
            dp=temp;
        }
        return dp[target];
    }
};