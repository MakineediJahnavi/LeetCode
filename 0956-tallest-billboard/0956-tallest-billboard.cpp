class Solution {
    int offset=5000;
private:
    int fun(int i,int d,vector<int> &rods,vector<vector<int>> &dp) {
        if(i==rods.size()) {
            if(d==0)
                return 0;
            return INT_MIN;
        }
        if(dp[i][d+offset]!=-1)
            return dp[i][d+offset];
        int notake=fun(i+1,d,rods,dp);
        int take1=rods[i]+fun(i+1,d+rods[i],rods,dp);
        int take2=fun(i+1,d-rods[i],rods,dp);
        return dp[i][d+offset]=max({take1,take2,notake});
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        vector<vector<int>> dp(21,vector<int>(2*offset+1,-1));
        int ans = fun(0,0,rods,dp);
        if(ans<0)
            return 0;
        return ans;
    }
};