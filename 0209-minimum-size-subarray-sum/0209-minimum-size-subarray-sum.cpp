class Solution {
private:
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int i=0,j=0,sum=0;
        while(i<n) {
            sum+=nums[i];
            while(sum>=target){
                ans=min(i-j+1,ans);
                sum-=nums[j];
                j++;
            }
            i++;
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};