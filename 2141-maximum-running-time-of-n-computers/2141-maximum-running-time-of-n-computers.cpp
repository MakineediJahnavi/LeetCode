class Solution {
private:
    bool isPossible(int n,vector<int> &batteries,int time) {
        long long sum=0;
        for(auto it: batteries) {
            sum+=it;
            if(sum>=time) {
                sum-=time;
                n--;
            }
        }
        return n<=0;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0;
        for(auto it: batteries) {
            sum+=it;
        }
        sort(batteries.begin(),batteries.end());
        long long l=0,r=sum/n;
        long long ans=0;
        while(l<=r) {
            long long mid=(l+r)/2;
            if(isPossible(n,batteries,mid)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};