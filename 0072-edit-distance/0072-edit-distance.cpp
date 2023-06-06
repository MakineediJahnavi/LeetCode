class Solution {
private:
    int opers(int i,int j,string word1,string word2,vector<vector<int>> &dp){
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i]==word2[j]) {
            return dp[i][j]=opers(i-1,j-1,word1,word2,dp);
        }
        int ins=1+opers(i,j-1,word1,word2,dp);
        int del=1+opers(i-1,j,word1,word2,dp);
        int rep=1+opers(i-1,j-1,word1,word2,dp);
        int mini=min(ins,del);
        return dp[i][j]=min(mini,rep);
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return opers(n-1,m-1,word1,word2,dp);
    }
};