class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long ls=index;
        long long rs=n-1-index;
        long long l=1,r=maxSum;
        long long ans=0;
        while(l<=r) {
            long long sum=0;
            long long mid=(l+r)/2;
            sum+=mid;
            long long m=mid-1;
            if(m>=ls) {
                sum+=1ll*(m*(m+1)/2)-((m-ls)*(m-ls+1)/2);
            }
            else {
                sum+=m*(m+1)/2+(ls-m);
            }
            if(m>=rs) {
                sum+=(m*(m+1)/2)-((m-rs)*(m-rs+1)/2);
            }
            else {
                sum+=m*(m+1)/2+(rs-m);
            }
            if(sum<=maxSum){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};