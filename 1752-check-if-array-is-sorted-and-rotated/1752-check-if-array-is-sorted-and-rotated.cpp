class Solution {
public:
    bool check(vector<int>& nums) {
        int numsSize=nums.size();
        if(nums[0]<nums[numsSize-1]) {
            for(int i=0; i<numsSize-1; i++) {
                if(nums[i]>nums[i+1])
                    return false;
            }
        }
        else {
            int i=0;
            while(i<numsSize-1 && nums[i]<=nums[i+1]) {
                i++;
            }
            i++;
            for(int k=i; k<numsSize-1; k++) {
                if(nums[k]>nums[k+1])
                    return false;
            }
        }
        return true;
    }
};