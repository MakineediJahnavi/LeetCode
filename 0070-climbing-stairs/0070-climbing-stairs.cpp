class Solution {
public:
    int climbStairs(int n) {
        int prev1=1, prev=1;
        for(int i=2; i<=n; i++) {
            int cur = prev+prev1;
            prev1 = prev;
            prev = cur;
        }
        return prev;
    }
};