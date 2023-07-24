class Solution {
private: 
    double power(double x,long long n) {
        if(n==0)
            return 1;
        if(n<0)
            return 1/power(x,-1*n);
        if(n%2==0)
            return power(x*x,n/2);
        return x*power(x*x,(n-1)/2);
}
public:
    double myPow(double x, int n) {
        return power(x,(long long)n);
    }
};