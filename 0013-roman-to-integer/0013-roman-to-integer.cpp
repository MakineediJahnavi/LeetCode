class Solution {
    unordered_map<char,int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
public:
    int romanToInt(string s) {
        int intgr=0;
        int n=s.length();
        for(int i=0; i<s.length()-1; i++) {
            if(m[s[i]]<m[s[i+1]])
                intgr-=m[s[i]];
            else
                intgr+=m[s[i]];
        }
        intgr+=m[s[n-1]];
        return intgr;
    }
};