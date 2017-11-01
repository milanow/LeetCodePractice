/* 674. Longest Continuous Increasing Subsequence
 * using an int to record current start pos of substring. If a new start pos reached, calculate the
 * length and record the max length of all increasing subsequence
 */


public class Solution {
    public int FindLengthOfLCIS(int[] nums) {
        if(nums.Length == 0) return 0;
        
        int mxlen = 1, start = 0;
        for(int i = 1; i < nums.Length; ++i){
            if(nums[i] <= nums[i-1]){
                mxlen = Math.Max(mxlen, i - start);
                start = i;
            }    
        }
        return Math.Max(mxlen, nums.Length - start);
    }
}