class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0,j=0;
        int t=0,f=0;
        int maxlen=INT_MIN;
        for(int i=0; i<answerKey.length(); i++) {
            if(answerKey[i]=='T')
                t++;
            else
                f++;
            while(t>k && f>k && j<=i) {
                if(answerKey[j]=='T')
                    t--;
                else
                    f--;
                j++;
            }
            maxlen=max(maxlen,i-j+1);
        }
        return maxlen;
    }
};