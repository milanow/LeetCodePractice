/* 633. Sum of Square Numbers
 * a hashset to record calculated difference of target and squared number
 * if a new squared number is found in the set, then the target can be added by two squared nunmber
 */


class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> st;
        for(int i = 0; i <= sqrt(c); ++i){
            st.insert(c - i*i);
            if(st.find(i*i) != st.end()) return true;
        }
        return false;
    }
};