class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int first;
        int prev=nums[0];
        int prev1=-1;
        for(int i=1; i<n-1; i++) {
            int take;
            if(i>=2)
                take=nums[i]+prev1;
            else
                take=nums[i];
            int noTake=prev;
            int cur=max(take,noTake);
            prev1=prev;
            prev=cur;
        }
        first=prev;
        int last;
        prev=nums[1];
        prev1=-1;
        for(int i=2; i<n; i++) {
            int take;
            if(i>=3)
                take=nums[i]+prev1;
            else
                take=nums[i];
            int noTake=prev;
            int cur=max(take,noTake);
            prev1=prev;
            prev=cur;
        }
        last=prev;
        return max(first,last);
    }
};