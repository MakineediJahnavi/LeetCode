class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,r=1e7;
        int ans=-1;
        while(l<=r) {
            int mid=(l+r)/2;
            double time=0.0;
            for(int i=0; i<dist.size(); i++) {
                double t=(double)dist[i]/(double)mid;
                if(i==dist.size()-1)
                    time+=t;
                else
                    time+=ceil(t);
            }
            if(time<=hour) {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};