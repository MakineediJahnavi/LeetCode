class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<long long> temp;
        for(int i=0; i<n-1; i++) {
            temp.push_back(weights[i]+weights[i+1]);
        }
        sort(temp.begin(),temp.end());
        long long edges=weights[0]+weights[n-1];
        long long min_cost=edges,max_cost=edges;
        for(int i=0; i<k-1; i++){
            min_cost+=temp[i];
            max_cost+=temp[n-2-i];
        }
        return max_cost-min_cost;
    }
};