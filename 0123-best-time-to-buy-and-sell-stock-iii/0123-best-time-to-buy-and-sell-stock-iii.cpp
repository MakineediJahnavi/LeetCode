class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++){
                for(int t=1; t<=2; t++){
                    if(!buy) {
                        dp[i][buy][t]=max(-prices[i]+dp[i+1][1][t],dp[i+1][0][t]);
                    }
                    else {
                        dp[i][buy][t]=max(prices[i]+dp[i+1][0][t-1],dp[i+1][1][t]);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};