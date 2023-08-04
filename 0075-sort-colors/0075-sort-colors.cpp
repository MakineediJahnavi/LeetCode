class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,k=nums.size()-1,i=0;
        while(i<=k) {
            switch(nums[i]) {
                case 0:
                    swap(nums[l++],nums[i++]);
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    swap(nums[i],nums[k--]);
                    break;
            }
        }
    }
};