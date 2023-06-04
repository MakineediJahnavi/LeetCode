class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> dp(amount+1,0);
        for(int i=0; i<=amount; i++){
            if(i%coins[0]==0)
                dp[i]=1;
        }
        for(int i=1; i<n; i++) {
            vector<int> cur(amount+1,0);
            for(int j=0; j<amount+1; j++) {
                int notake=dp[j];
                int take=0;
                if(j>=coins[i])
                    take=cur[j-coins[i]];
                cur[j]=notake+take;
            }
            dp=cur;
        }
        return dp[amount];
    }
};