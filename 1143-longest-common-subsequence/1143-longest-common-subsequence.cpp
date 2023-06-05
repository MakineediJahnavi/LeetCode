class Solution {
private:
    int dp(int ind1,int ind2,string &text1,string &text2,vector<vector<int>> &temp){
        if(ind1<0 || ind2<0)
            return 0;
        if(temp[ind1][ind2]!=-1)
            return temp[ind1][ind2];
        if(text1[ind1]==text2[ind2])
            return 1+dp(ind1-1,ind2-1,text1,text2,temp);
        return temp[ind1][ind2]=max(dp(ind1-1,ind2,text1,text2,temp),dp(ind1,ind2-1,text1,text2,temp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>> temp(n1,vector<int>(n2,-1));
        return dp(n1-1,n2-1,text1,text2,temp);
    }
};