class Solution {
private: 
    int  maxp(int i,int buy,int t,vector<int> &prices,vector<vector<vector<int>>> &dp) {
        if(t==0)
            return 0;
        if(i==prices.size())
            return 0;
        if(dp[i][buy][t]!=-1)
            return dp[i][buy][t];
        if(!buy) {
            dp[i][buy][t]=max(-prices[i]+maxp(i+1,1,t,prices,dp),maxp(i+1,0,t,prices,dp));
        }
        else {
            dp[i][buy][t]=max(prices[i]+maxp(i+1,0,t-1,prices,dp),maxp(i+1,1,t,prices,dp));
        }
        return dp[i][buy][t];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        maxp(0,0,2,prices,dp);
        return dp[0][0][2];
    }
};