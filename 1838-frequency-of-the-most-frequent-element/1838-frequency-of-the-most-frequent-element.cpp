class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int max_freq=0;
        int i=0,j=0;
        long long sum=0;
        int ans=0;
        while(i<nums.size()) {
            sum+=nums[i];
            if((1ll*nums[i]*(i-j+1))-sum<=k)
                i++;
            else{
                while((1ll*nums[i]*(i-j+1))-sum>k) {
                    sum-=nums[j];
                    j++;
                }
                i++;
            }
            ans=max(ans,i-j);
        }
        return ans;
    }
};