class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n);
        int maxlen=1,ind=0;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]) {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(maxlen<dp[i]){
                maxlen=dp[i];
                ind=i;
            }
        }
        vector<int> ans(maxlen);
        while(maxlen>0) {
            ans[maxlen-1]=nums[ind];
            maxlen--;
            ind=hash[ind];
        }
        return ans;
    }
};