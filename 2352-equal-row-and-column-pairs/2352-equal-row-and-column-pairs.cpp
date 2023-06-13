class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        map<vector<int>,int> p;
        for(auto it:grid)
            p[it]++;
        int ans=0;
        for(int col=0; col<m; col++) {
            vector<int> temp;
            for(int row=0; row<n; row++)
                temp.push_back(grid[row][col]);
            ans+=p[temp];
        }
        return ans;
    }
};