class Solution {
private:
    void combinations(int i,string &digits,vector<string> &m,vector<string> &ans,string &temp) {
        if(i==digits.size()) {
            ans.push_back(temp);
            return ;
        }
        int n=digits[i]-'0';
        for(int j=0; j<m[n-2].length(); j++) {
            temp+=m[n-2][j];
            cout<<m[n-2][j]<<endl;
            combinations(i+1,digits,m,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        vector<string> ans;
        string temp;
        vector<string> m={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        combinations(0,digits,m,ans,temp);
        return ans;
    }
};