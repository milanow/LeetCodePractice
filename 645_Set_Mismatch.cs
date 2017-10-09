/* 645. Set Mismatch
 * rearrange the array to {1,2,3,4,...,n} by swaping nums[i] with nums[nums[i]-1]
 */


public class Solution {
    public int[] FindErrorNums(int[] nums) {
        for(int i = 0; i < nums.Length; ++i){
            while(nums[i] != nums[nums[i] - 1]){
                SwapNums(nums, i, nums[i] - 1);
            }
        }
        
        for(int i = 0; i < nums.Length; ++i){
            if(nums[i] != i+1) return new int[]{nums[i], i+1};
        }
        return new int[0];
    }
    
    public void SwapNums(int[] nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
}