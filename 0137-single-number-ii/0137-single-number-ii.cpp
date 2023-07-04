class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]==nums[i-1])
                i=i+2;
            else 
                return nums[i-1];
        }
        return -1;
    }
};