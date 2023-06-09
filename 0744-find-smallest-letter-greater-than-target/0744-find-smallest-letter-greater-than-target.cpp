class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0,r=letters.size()-1;
        if(letters[r]<=target||letters[0]>target)
            return letters[0];
        char ans;
        while(l<=r) {
            int mid=(l+r)/2;
            if(target<letters[mid]) {
                ans=letters[mid];
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};