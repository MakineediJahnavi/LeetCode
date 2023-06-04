class Solution {
private:
    int count(int i,int target,vector<int> &coins,vector<vector<int>> &dp) {
        if(i==0) {
            if(target%coins[0]==0)
                return target/coins[0];
            return 1e9;
        }
        if(dp[i][target]!=-1)
            return dp[i][target];
        int notake=count(i-1,target,coins,dp);
        int take=INT_MAX;
        if(coins[i]<=target)
            take=1+count(i,target-coins[i],coins,dp);
        return dp[i][target]=min(take,notake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int target=0; target<=amount; target++){
            if(target%coins[0]==0)
                dp[0][target]=target/coins[0];
            else
               dp[0][target]=1e9; 
        }
        for(int i=1; i<n; i++) {
            for(int j=0; j<=amount; j++) {
                int notake=dp[i-1][j];
                int take=INT_MAX;
                if(coins[i]<=j)
                    take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take,notake);
            }
        }
        if(dp[n-1][amount]>=1e9)
            return -1;
        return dp[n-1][amount];
    }
};