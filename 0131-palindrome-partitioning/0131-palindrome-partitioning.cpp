class Solution {
public:
    bool isPalindrome(int l,int r,string s) {
        while(l<r) {
            if(s[l]!=s[r])
                return false;
            l++; r--;
        }
        return true;
    }
    void palindromes(vector<vector<string>> &ans,vector<string> &ds,string s,int ind,int n) {
        if(ind==n) {
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<n; i++) {
            if(isPalindrome(ind,i,s)) {
                ds.push_back(s.substr(ind,i-ind+1));
                palindromes(ans,ds,s,i+1,n);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        palindromes(ans,ds,s,0,s.length());
        return ans;
    }
};