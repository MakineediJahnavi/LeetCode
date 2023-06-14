class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(2,vector<int>(3,0));
        for(int i=n-1; i>=0; i--) {
            vector<vector<int>> cur(2,vector<int>(3,0));
            for(int buy=0; buy<=1; buy++){
                for(int t=1; t<=2; t++){
                    if(!buy) {
                        cur[buy][t]=max(-prices[i]+dp[1][t],dp[0][t]);
                    }
                    else {
                        cur[buy][t]=max(prices[i]+dp[0][t-1],dp[1][t]);
                    }
                }
            }
            dp=cur;
        }
        return dp[0][2];
    }
};