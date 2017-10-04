/* 665. Non-decreasing Array
 * keep recording previous larger value to avoid mis calculate condition: 5 6 2 3, where
 * we have to compare 6 with 3 not 2
 */

public class Solution {
    public bool CheckPossibility(int[] nums) {
        int n = nums.Length, last = nums[0];
        bool switched = false;
        for(int i = 1; i < n; ++i){
            if(nums[i] < last){
                if(switched) return false;
                switched = true;
                
                if(i >= 2 && nums[i-2] > nums[i]) continue;
            }
            last = nums[i];
        }
        return true;
    }
}