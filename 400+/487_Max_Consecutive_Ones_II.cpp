/* 487. Max Consecutive Ones II
 * keep track of most recent 2 zeros' positions
 * When encountering a new 'zero' we check how long it can form
 * a consecutive one array (with one zero), also updating
 * prezero and curzero.
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int prezero = -1, curzero = -1, mxlen = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                mxlen = max(mxlen, i - prezero - 1);
                prezero = curzero;
                curzero = i;
            }
        }
        mxlen = max(mxlen, static_cast<int>(nums.size()) - prezero - 1);
        return mxlen;
    }
};