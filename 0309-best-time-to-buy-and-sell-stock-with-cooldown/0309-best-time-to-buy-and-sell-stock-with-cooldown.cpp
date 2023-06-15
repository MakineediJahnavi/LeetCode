class Solution {
private:
    int maxp(int i,int buy,vector<int> &prices,vector<vector<int>> &dp) {
        if(i>=prices.size())
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(!buy) {
            dp[i][buy]=max(-prices[i]+maxp(i+1,1,prices,dp),maxp(i+1,0,prices,dp));
        }
        else {
            dp[i][buy]=max(prices[i]+maxp(i+2,0,prices,dp),maxp(i+1,1,prices,dp));
        }
        return dp[i][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        maxp(0,0,prices,dp);
        return dp[0][0];
    }
};