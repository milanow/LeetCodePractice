/* 553. Optimal Division
 * The answer is quite simple, the biggest result is first number as dividend and other
 * numbers to form a smallest divisor.
 */

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int sz = nums.size();
        string res{to_string(nums[0])};
        for(int i = 1; i < sz; ++i){
            res += '/';
            if(i == 1 && sz > 2) res += '(';
            res += to_string(nums[i]);
        }
        if(sz > 2) res += ')';
        return res;
    }
};