class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int s=cuts.size();
        vector<vector<int>> dp(s,vector<int>(s,0));
        for(int i=s-2; i>=1; i--) {
            for(int j=1; j<=s-2; j++) {
                if(i>j) continue;
                int ans=1e9;
                for(int k=i; k<=j; k++) {
                int c=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                ans=min(ans,c);
            }
            dp[i][j]=ans;
            }
        }
        return dp[1][s-2];
    }
};