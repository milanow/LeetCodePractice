/* 594. Longest Harmonious Subsequence
 * typical sliding window problem, sorting the array first, checking each subarray
 * whose diff of largest number & smallest number is 1. "start" represents the start pos
 * of such array. "laststart" represents the possible position of next start
 */

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        
        int start = 0, laststart = 0, mxlen = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] - nums[start] > 1){
                start = laststart;
            }
            if(nums[i] != nums[i-1]){
                laststart = i;
            }
            if(nums[i] - nums[start] == 1){
                mxlen = max(mxlen, i-start+1);
            }
        }
        return mxlen;
    }
};