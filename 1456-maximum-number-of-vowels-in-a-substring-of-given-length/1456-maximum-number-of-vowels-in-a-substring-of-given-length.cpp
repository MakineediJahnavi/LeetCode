class Solution {
public:
    int  isVowel(char x) {
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
            return 1;
        return 0;
    }
    int maxVowels(string s, int k) {
        int maxV=0;
        for(int i=0; i<k; i++) {
            maxV+=isVowel(s[i]);
        }
        int temp=maxV;
        cout<<maxV<<endl;
        for(int i=1; i<s.length()-k+1; i++) {
            temp = temp-isVowel(s[i-1])+isVowel(s[i+k-1]);
            maxV=max(temp,maxV);
        }
        return maxV;
    }
};