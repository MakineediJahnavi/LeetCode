class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.length()-1;
        while(l<r) {
            while(l<s.length() && !isalnum(s[l])){
                l++;}
            while(r>=0 && !isalnum(s[r]))
                r--;
            if(l>=r)
                continue;
            if(tolower(s[l])!=tolower(s[r]))
                return false;
            else {
                l++; r--;
            }
        }
        return true;
    }
};