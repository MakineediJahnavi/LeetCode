class Solution {
public:
    int minFlips(int a, int b, int c) {
        int steps=0;
        while(a>0 || b>0 || c>0) {
            int x=a&1;
            int y=b&1;
            int z=c&1;
            if(z==0){
                steps+=(x+y);
            }
            else if(x==0 && y==0){
                steps+=1;
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return steps;
    }
};