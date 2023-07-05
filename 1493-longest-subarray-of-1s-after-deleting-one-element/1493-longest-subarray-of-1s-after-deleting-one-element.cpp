class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int count=0,zeros=0;
        for(int j=0; j<nums.size(); j++) {
            if(nums[j]==0)
                zeros++;
            while(zeros>1){
                if(nums[i]==0)
                    zeros--;
                i++;
            }
            count=max(count,j-i);
        }
        return count;
    }
};