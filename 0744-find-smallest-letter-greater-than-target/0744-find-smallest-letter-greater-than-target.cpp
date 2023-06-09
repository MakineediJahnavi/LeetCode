class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto it:letters) {
            if(target-41<it-41) {
                return it;
            }
        }
        return letters[0];
    }
};