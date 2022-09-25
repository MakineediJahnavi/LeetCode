class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> a;
        int n=heights.size();
        for(int i=0; i<n; i++) {
            a.push_back({heights[i],names[i]});
        }
        sort(a.rbegin(),a.rend());
        vector<string> ans;
        for(int i=0; i<n; i++) {
            ans.push_back(a[i].second);
        }
        return ans;
    }
};