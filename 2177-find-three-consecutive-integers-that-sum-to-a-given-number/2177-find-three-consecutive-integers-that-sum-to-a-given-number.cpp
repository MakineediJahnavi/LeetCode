class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long temp=num-3;
        if(temp%3!=0)
            return {};
        temp/=3;
        return {temp,temp+1,temp+2};
    }
};