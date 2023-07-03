class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n1=s.length();
        int n2=goal.length();
        if(n1!=n2)
            return false;
        if(s==goal){
            set<char> temp(s.begin(),s.end());
            return temp.size()<goal.size();
        }
        int i=0,j=n1-1;
        while(i<j && s[i]==goal[i]) {
            i++;
        }
        while(j>=0 && s[j]==goal[j]) {
            j--;
        }
        if(i<j)
            swap(s[i],s[j]);
        return s==goal;
    }
};