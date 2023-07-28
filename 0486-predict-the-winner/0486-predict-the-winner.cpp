class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        int sum=0;
        for(auto n: nums) {
            sum+=n;
        }
        for(int i=n-1; i>=0; i--) {
            for(int j=1; j<=n; j++) {
                for(int flag=0; flag<=1; flag++) {
                    if(i>j)
                        continue;
                    int score1=INT_MIN;
                    if(flag)
                        score1=max(nums[i]+dp[i+1][j][0],nums[j-1]+dp[i][j-1][0]);
                    else
                        score1=min(dp[i+1][j][1],dp[i][j-1][1]);
                    dp[i][j][flag]=score1;
                }
            }
        }
        int score1=dp[0][n][1];
        int score2=sum-score1;
        return (score1>=score2);
    }
};