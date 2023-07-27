class Solution {
private:
    int alice(int i,int m,int flag,vector<int> &piles,vector<vector<vector<int>>> &dp) {
        if(i==piles.size())
            return 0;
        if(dp[i][m-1][flag]!=-1)
            return dp[i][m-1][flag];
        int ans;
        if(flag) {
            int sum=0;
            ans=INT_MIN;
            for(int j=i; j<i+2*m; j++) {
                if(j==piles.size())
                    break;
                sum+=piles[j];
                ans=max(ans,sum+alice(j+1,max(j-i+1,m),0,piles,dp));
            }
        }
        else{
            ans=INT_MAX;
            for(int j=i; j<i+2*m; j++){
                if(j==piles.size())
                    break;
                ans=min(ans,alice(j+1,max(j-i+1,m),1,piles,dp));
            }
        }
        return dp[i][m-1][flag]=ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n,vector<int>(2,-1)));
        return alice(0,1,1,piles,dp);
    }
};