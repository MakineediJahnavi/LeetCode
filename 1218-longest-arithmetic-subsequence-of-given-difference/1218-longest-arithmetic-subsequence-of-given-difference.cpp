class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        unordered_map<int,int> dp;
        int ans=1;
        for(auto it: arr) {
            if(dp.count(it-difference)){
                dp[it]=1+dp[it-difference];
                ans=max(ans,dp[it]);
            }
            else
                dp[it]=1;
        }
        return ans;
    }
};