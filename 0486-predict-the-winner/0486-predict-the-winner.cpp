class Solution {
private:
    int prediction(int i,int j,int flag,vector<int> &nums,vector<vector<vector<int>>> &dp) {
        if(i>j)
            return 0;
        if(dp[i][j][flag]!=-1)
            return dp[i][j][flag];
        int score1=INT_MIN;
        if(flag)
            score1=max(nums[i]+prediction(i+1,j,0,nums,dp),nums[j]+prediction(i,j-1,0,nums,dp));
        else
            score1=min(prediction(i+1,j,1,nums,dp),prediction(i,j-1,1,nums,dp));
        return dp[i][j][flag]=score1;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int sum=0;
        for(auto n: nums) {
            sum+=n;
        }
        int score1=prediction(0,nums.size()-1,1,nums,dp);
        int score2=sum-score1;
        return (score1>=score2);
    }
};