class Solution {
private:
    void combinations(vector<int> &candidates,vector<int> temp,vector<vector<int>> &ans,int target,int ind,int n) {
        if(target==0) {
            ans.push_back(temp);
            return ;
        }
        else if(ind>=n || target<0)
            return ;
        for(int i=ind; i<n; i++) {
            if(i>ind && candidates[i]==candidates[i-1])
                continue;
            temp.push_back(candidates[i]);
            combinations(candidates,temp,ans,target-candidates[i],i+1,n);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        combinations(candidates,temp,ans,target,0,candidates.size());
        return ans;
    }
};