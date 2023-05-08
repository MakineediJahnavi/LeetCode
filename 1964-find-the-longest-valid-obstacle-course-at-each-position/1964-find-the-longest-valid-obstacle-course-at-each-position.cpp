class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> course;
        vector<int> courseLen(obstacles.size());
        for(int i=0; i<obstacles.size(); i++) {
            if(course.size()==0 || course.back()<=obstacles[i]) {
                course.push_back(obstacles[i]);
                courseLen[i] = course.size();
            }
            else {
                int ind = upper_bound(course.begin(), course.end(),obstacles[i])-course.begin();
                course[ind] = obstacles[i];
                courseLen[i] = ind+1;
            }
        }
        return courseLen;
    }
};