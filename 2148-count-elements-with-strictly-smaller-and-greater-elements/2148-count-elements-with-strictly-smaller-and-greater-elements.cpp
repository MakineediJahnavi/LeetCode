class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=nums[0];
        int r=nums[nums.size()-1];
        int count =0;
        for(auto it: nums) {
            if(it>l && it<r)
                count++;
        }
        return count;
    }
};