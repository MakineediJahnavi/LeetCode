class comp {
    public:
    bool operator()(string &s,string &t) {
        return s.length()<t.length();
    }
};
class Solution {
public:
    bool isChain(string &s,string &t) {
        if(s.length()!=t.length()-1)
            return false;
        int i=0,j=0;
        while(j<t.length()) {
            if(i<s.length()&&s[i]==t[j]){
                i++;
                j++;
            }
            else
                j++;
        }
        if(i==s.length()&&j==t.length())
            return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp());
        int maxlen=1;
        vector<int> dp(n,1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(isChain(words[j],words[i]) && 1+dp[j]>dp[i])
                    dp[i]=1+dp[j];
            }
            maxlen=max(maxlen,dp[i]);
        }
        return maxlen;
    }
};