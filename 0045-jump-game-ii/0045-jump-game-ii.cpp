class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return 0;
        vector<int> dp(n,0);
        for(int i=n-2; i>=0; i--) {
            int ans=1e9;
            for(int j=1; j<=nums[i]; j++) {
                if((i+j)>=nums.size())
                    break;
                ans=min(ans,1+dp[i+j]);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};