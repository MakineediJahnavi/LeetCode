class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum-target<0 || (sum-target)%2)
            return 0;
        int d=(sum-target)/2;
        vector<int> dp(d+1,0);
        if(nums[0]==0)
            dp[0]=2;
        else
            dp[0]=1;
        if(nums[0]!=0 && nums[0]<=d)
            dp[nums[0]]=1;
        for(int i=1; i<n; i++) {
            vector<int> temp(d+1,0);
            for(int j=0; j<=d; j++) {
                int notake=dp[j];
                int take=0;
                if(nums[i]<=j)
                    take=dp[j-nums[i]];
                temp[j]=take+notake;
            }
            dp=temp;
        }
        return dp[d];
    }
};