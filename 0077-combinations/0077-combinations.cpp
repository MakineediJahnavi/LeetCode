class Solution {
private:
    void subsequences(int i,int n,int k,vector<int> &temp,vector<vector<int>> &ans) {
        if(k==0){
            ans.push_back(temp);
            return ;
        }
        if(i==n+1)
            return ;
        temp.push_back(i);
        subsequences(i+1,n,k-1,temp,ans);
        temp.pop_back();
        subsequences(i+1,n,k,temp,ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        subsequences(1,n,k,temp,ans);
        return ans;
    }
};