class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int ans=0,sign=1;
        int i=0;
        while(s[i]==' ')
            i++;
        if(i<n && (s[i]=='+' || s[i]=='-')) {
            sign = s[i]=='+'? 1 :-1;
            ++i;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && s[i]>'7')) {
                return sign==1? INT_MAX :INT_MIN;
            }
            ans=ans*10+(s[i]-'0');
            ++i;
        }
        return ans*sign;
    }
};