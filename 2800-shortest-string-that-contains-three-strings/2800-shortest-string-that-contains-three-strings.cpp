class Solution {
private:
    string merge(string s1,string s2) {
        if(s1.find(s2)!=string::npos)
            return s1;
        for(int i=min(s1.length(),s2.length()); i>=0; i--) {
            if(s1.substr(s1.length()-i)==s2.substr(0,i))
                return s1+s2.substr(i);
        }
        return s1+s2;
    }
    void minimum(string s1,string &s2) {
        if(s2.empty() || s1.length()<s2.length() || (s1.length()==s2.length() && s1<s2))
            s2=s1;
    }
public:
    string minimumString(string a, string b, string c) {
        string ans="";
        vector<string> s={a,b,c};
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    if(i!=j && j!=k && k!=i) {
                        string temp=merge(s[i],s[j]);
                        temp=merge(temp,s[k]);
                        minimum(temp,ans);
                    }
                }
            }
        }
        return ans;
    }
};