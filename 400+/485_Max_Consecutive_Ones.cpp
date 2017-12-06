/* 485. Max Consecutive Ones
 * Keep track of previous zero position and find all possible consecutive 
 * One's array. Return the maximum length of consecutive one array
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int prezero = -1, mxlen = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                mxlen = max(mxlen, i - prezero - 1);
                prezero = i;
            }
        }
        return max(mxlen, static_cast<int>(nums.size()) - prezero - 1);
    }
};