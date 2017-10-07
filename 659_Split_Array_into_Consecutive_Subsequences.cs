/* 659. Split Array into Consecutive Subsequences
 * First, split the array to several continuous block, where every pair of adjacent element's difference
 * is less than 1. 
 * Secondly, in every block, keep recording the count of current 'ones' array and 'twos' arrays,
 * which means the arrays that have 1 or 2 elements (cannot be individual array because length less than 3)
 * In each steps, check if incoming number is enough to append 'ones' and 'twos', eg, [1] & [1,2] needs at least
 * 2 '3's to be valid. If not enough num, return false. After checking one block, check if 'ones' & 'twos' are zero
 * length
 */

public class Solution {
    public bool IsPossible(int[] nums) {
        int len = nums.Length, k = 0;
        if(len < 3) return false;
        for(int i = 1; i < len; ++i){
            if(nums[i] - nums[i-1] > 1){
                if(!checkSubArr(nums, k, i-1)) return false;
                k = i;
            }
        }
        return checkSubArr(nums, k, len-1);
    }
    
    private bool checkSubArr(int[] nums, int start, int end){
        int n = end - start + 1;
        int[] ones = new int[n+1], twos = new int[n+1], mp = new int[n];
        for(int i = start, diff = nums[start]; i <= end; ++i){
            mp[nums[i] - diff]++;
        }
        
        for(int i = 0; i < n; ++i){
            if(mp[i] < ones[i] + twos[i]) return false;
            twos[i+1] = ones[i];
            ones[i+1] = Math.Max(0, mp[i] - ((i > 0)? mp[i-1]: 0));
        }
        
        return ones[n] == 0 && twos[n] == 0;
    }
}