class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini=INT_MAX,maxi=INT_MIN;
        int l,r;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i]>nums[i+1])
                mini=min(nums[i+1],mini);
        }
        for(int i=nums.size()-2; i>=0; i--) {
            if(nums[i]>nums[i+1])
                maxi=max(maxi,nums[i]);
        }
        if(mini==INT_MAX && maxi==INT_MIN)
            return 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>mini) {
                l=i;
                break;
            }
        }
        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i]<maxi) {
                r=i;
                break;
            }
        }
        return r-l+1;
    }
};