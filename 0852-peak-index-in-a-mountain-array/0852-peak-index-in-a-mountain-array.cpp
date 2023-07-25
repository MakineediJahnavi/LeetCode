class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        int ans=r;
        while(l<=r) {
            int mid=(l+r)/2;
            if(arr[mid+1]>arr[mid])
                l=mid+1;
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};