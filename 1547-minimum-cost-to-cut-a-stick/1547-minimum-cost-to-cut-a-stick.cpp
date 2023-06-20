class Solution {
private:
    int fun(int i,int j,vector<int> &cuts,vector<vector<int>> &dp) {
        if(i>j)
            return dp[i][j]=0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=1e9;
        for(int k=i; k<=j; k++) {
            int c=cuts[j+1]-cuts[i-1]+fun(i,k-1,cuts,dp)+fun(k+1,j,cuts,dp);
            ans=min(ans,c);
        }
        return dp[i][j]=ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int s=cuts.size();
        vector<vector<int>> dp(s,vector<int>(s,-1));
        fun(1,s-2,cuts,dp);
        return dp[1][s-2];
    }
};