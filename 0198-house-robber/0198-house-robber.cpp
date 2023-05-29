class Solution {
private:
public:
    int rob(vector<int>& nums) {
        int prev=nums[0];
        int prev1 = -1;
        for(int i=1; i<nums.size(); i++) {
            int take;
            if(i>=2)
                take = nums[i]+prev1;
            else
                take=nums[i];
            int noTake=prev;
            int cur=max(take,noTake);
            prev1=prev;
            prev=cur;
        }
        return prev;
    }
};