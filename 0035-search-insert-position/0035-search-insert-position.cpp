class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1,mid,ans=nums.size();
        while(l<=r) {
            mid=(l+r)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else {
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};