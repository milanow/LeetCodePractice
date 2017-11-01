/* 644. Maximum Average Subarray II
 * A binary search solution, evaluate an average value (mid) every time to seek a result
 * for each mids, calculate subarray's sum, and its avarage, if there is a subarray's average
 * is larger than mid, then assign mid's value to left, otherwise right = mid.
 * return left as result.
 */


public class Solution {
    public double FindMaxAverage(int[] nums, int k) {
        double left = Int32.MaxValue, right = Int32.MinValue;
        foreach(int num in nums){
            left = Math.Min(left, num);
            right = Math.Max(right, num);
        }
        while(left + 0.00001 < right){
            double mid = (left + right) / 2;
            if(MidIsLarger(nums, mid, k)) right = mid;
            else left = mid;
        }
        return left;
    }
    
    private bool MidIsLarger(int[] nums, double mid, int k){
        double sum = 0, preSum = 0, minSum = 0;
        for(int i = 0; i < nums.Length; ++i){
            sum += nums[i] - mid;
            if(i >= k){
                preSum += nums[i-k] - mid;
                minSum = Math.Min(minSum, preSum);
            }
            if(i >= k-1 && sum - minSum > 0) return false;
        }
        return true;
    }
}