/* 414. Third Maximum Number
 * Use set to maintain a length of 3 array and keep updating the set
 */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for(int n: nums){
            st.insert(n);
            if(st.size() > 3){
                st.erase(st.begin());
            }
        }
        return st.size() >= 3? *st.begin(): *st.rbegin();
    }
};