class Solution {
public:
    int reverse(int x) {
        long long y=0,temp=x;
        int sign=1;
        if(x<0) {
            sign=-1;
            temp=-1*temp;
        }
        while(temp>0) {
            y=y*10+temp%10;
            temp/=10;
        }
        y=sign*y;
        if(y>INT_MAX || y<INT_MIN)
            return 0;
        return (int)y;
    }
};