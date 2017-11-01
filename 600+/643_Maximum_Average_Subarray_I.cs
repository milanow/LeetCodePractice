/* 643. Maximum Average Subarray I
 * dynamically update the max sum of k's continuous number
 * return maxSum / k as average
 */

public class Solution {
    public double FindMaxAverage(int[] nums, int k) {
        int n = nums.Length;
        int sum = 0;
        for(int i = 0; i < k; ++i){
            sum += nums[i];
        }
        int maxSum = sum;
        
        for(int i = k; i < n; ++i){
            sum -= nums[i-k];
            sum += nums[i];
            maxSum = Math.Max(sum, maxSum);
        }
        
        return (double)maxSum / (double)k;
    }
}