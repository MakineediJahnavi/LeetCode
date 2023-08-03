class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1; i>0; i--) {
            if(nums[i-1]<nums[i]) {
                for(int j=n-1; j>=i; j--){
                    if(nums[j]>nums[i-1]) {
                        swap(nums[i-1],nums[j]);
                        break;
                    }
                }
                reverse(nums.begin()+i, nums.end());
                return ;
            }
        }
        sort(nums.begin(),nums.end());
    }
};