/* 581. Shortest Unsorted Continuous Subarray
 * The final array should be sorted in ascending order. Thus we first check left and right
 * to find out the first element obeying ascending order
 * Then in the middle subarray, we find out the min and max in the array.
 * However, the min of mid subarray may smaller than elements in pre-mid subarray
 * that's why we need to move left pointer to left to see which position doesn't obey
 * ascending order.
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        
        int left = 0, right = n-1;
        while(left < n-1 && nums[left] <= nums[left+1]) left++;
        while(right > 0 && nums[right] >= nums[right-1]) right--;
        
        int shortest = 0;
        if(left < right){
            int mn = INT_MAX, mx = INT_MIN;
            for(int i = left; i <= right; ++i){
                mn = min(nums[i], mn);
                mx = max(nums[i], mx);
            }
            
            while(left >= 0 && nums[left] > mn) left--;
            while(right <= n-1 && nums[right] < mx) right++;
            
            shortest = right - left - 1;
        }
        return shortest;
    }
};