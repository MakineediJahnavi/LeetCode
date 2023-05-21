class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ind;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==target || nums[i]>target) {
                ind=i;
                break;
            }
        }
        return ind;
    }
};