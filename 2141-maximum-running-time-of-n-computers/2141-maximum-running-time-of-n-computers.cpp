class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0;
        for(auto it: batteries) {
            sum+=it;
        }
        sort(batteries.begin(),batteries.end());
        for(int i=batteries.size()-1; i>=0; i--) {
            if(batteries[i]>sum/n) {
                sum-=batteries[i];
                n--;
            }
            else
                break;
        }
        return sum/n;
    }
};