class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0)
            return 0;
        int ans=1,count=1;
        int prev=nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]==prev+1){
                count++;
                prev=nums[i];
            }
            else if(nums[i]==prev)
                continue;
            else {
                count=1;
                prev=nums[i];
            }
            ans=max(ans,count);
        }
        return ans;
    }
};