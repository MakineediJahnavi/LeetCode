class Solution {
private:
    void combinations(vector<int> &candidates,int target,vector<int> temp,vector<vector<int>> &ans,int i,int n) {
        if(target==0){
            ans.push_back(temp);
            return;
        }
        else if(target<0 || i>=n)
            return;
        temp.push_back(candidates[i]);
        combinations(candidates,target-candidates[i],temp,ans,i,n);
        temp.pop_back();
        combinations(candidates,target,temp,ans,i+1,n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinations(candidates,target,temp,ans,0,candidates.size());
        return ans;
    }
};