class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size()-1;
        string ans="";
        for(int i=0; i<min(strs[0].length(),strs[n].length()); i++) {
            if(strs[0][i]!=strs[n][i])
                return ans;
            ans+=strs[0][i];
        }
        return ans;
    }
};