class Solution {
private:
    int who_wins(int i,int j,int flag,vector<int> &piles,vector<vector<int>> &dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(flag==1)
            dp[i][j] = max(piles[i]+who_wins(i+1,j,0,piles,dp),piles[j]+who_wins(i,j-1,0,piles,dp));
        else
            dp[i][j] = max(-piles[i]+who_wins(i+1,j,1,piles,dp),-piles[j]+who_wins(i,j-1,1,piles,dp));
            return dp[i][j];
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        who_wins(0,piles.size()-1,1,piles,dp);
        return (dp[0][n-1]>0);
    }
};
