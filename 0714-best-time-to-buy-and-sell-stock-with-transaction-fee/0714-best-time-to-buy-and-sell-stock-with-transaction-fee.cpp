class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(!buy) {
                    dp[i][buy]=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                else {
                    dp[i][buy]=max(prices[i]-fee+dp[i+1][0],dp[i+1][1]);
                }
            }
        }
        return dp[0][0];
    }
};