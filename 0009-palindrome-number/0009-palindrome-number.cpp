class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long int y=0;
        int n=x;
        while(n>0) {
            y=y*10+n%10;
            n/=10;
        } 
        if(x==y)
            return true;
        return false;
    }
};