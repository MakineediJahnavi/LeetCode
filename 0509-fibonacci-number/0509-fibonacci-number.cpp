class Solution {
public:
    int fib(int n) {
        int prev1=0, prev=1;
        if(n==0)
            return 0;
        for(int i=2; i<=n; i++) {
            int cur = prev + prev1;
            prev1 = prev;
            prev = cur;
        }
        return prev;
    }
};