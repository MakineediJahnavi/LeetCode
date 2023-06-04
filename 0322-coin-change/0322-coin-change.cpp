class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,0);
        for(int target=0; target<=amount; target++){
            if(target%coins[0]==0)
                dp[target]=target/coins[0];
            else
               dp[target]=1e9; 
        }
        for(int i=1; i<n; i++) {
            vector<int> cur(amount+1,0);
            for(int j=0; j<=amount; j++) {
                int notake=dp[j];
                int take=INT_MAX;
                if(coins[i]<=j)
                    take=1+cur[j-coins[i]];
                cur[j]=min(take,notake);
            }
            dp=cur;
        }
        if(dp[amount]>=1e9)
            return -1;
        return dp[amount];
    }
};