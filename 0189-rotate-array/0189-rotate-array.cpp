class Solution {
private:
    void reverse(int i,int j,vector<int> &nums) {
        while(i<=j) {
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++; j--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverse(0,n-1-k,nums);
        reverse(n-k,n-1,nums);
        reverse(0,n-1,nums);
    }
};