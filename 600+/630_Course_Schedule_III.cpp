/* 630. Course Schedule III
 * Sort the input courses by comparing the deadline, the earlier deadline dates are placed at front
 * Because we want to greedily take as many courses as possible.
 * Then we examine from the first course, the strategy is "keep current day as earlier as possible",
 * because in this way we can save time to take courses. When encountered a new course whose time cost is
 * less than prior course, we 'switch course' because obviously, a short course can save our time and 
 * our goal is to take as MANY as courses possible.
 */

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto comp = [](const vector<int>& c1, const vector<int>& c2){
            return c1[1] < c2[1] || c1[1] == c2[1] && c1[0] < c2[0];
        };
        sort(courses.begin(), courses.end(), comp);
        multiset<int> st;
        
        int day = 0;
        for(int i = 0; i < courses.size(); ++i){
            if(day + courses[i][0] <= courses[i][1]){
                day += courses[i][0];
                st.insert(courses[i][0]);
            }else if(!st.empty() && *--st.end() > courses[i][0]){
                day -= *st.rbegin() - courses[i][0];
                st.erase(--st.end());
                st.insert(courses[i][0]);
            }
        }
        return st.size();
    }
};