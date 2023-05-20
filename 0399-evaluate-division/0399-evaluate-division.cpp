class Solution {
private:
    void dfs(string node,string &dest,unordered_set<string> &vis,unordered_map<string,unordered_map<string,double>> &m,double &ans,double temp) {
        if(vis.find(node)!=vis.end())
            return;
        vis.insert(node);
        if(node==dest) {
            ans=temp;
            return;
        }
        for(auto it:m[node]){
            dfs(it.first,dest,vis,m,ans,temp*it.second);
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> m;
        vector<double> ans;
        for(int i=0; i<equations.size(); i++) {
            m[equations[i][0]][equations[i][1]] = values[i];
            m[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        for (auto it: queries) {
            string dividend = it[0];
            string divisor = it[1];
            if(m.find(dividend)==m.end() || m.find(divisor)==m.end())
                ans.push_back(-1.0);
            else {
                unordered_set<string> vis;
                double temp=1.0, val=-1;
                dfs(dividend,divisor,vis,m,val,temp);
                ans.push_back(val);
            }
        }
        return ans;
    }
};