/* 724. Find Pivot Index
 * Checking left side sum & right side sum to find the pivot point.
 * Sum[] is quite useful for recording left side sum, right side sum can be 
 * calculated by sum - sum[i-1] - nums[i]
 */

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) return nums[0];
        
        vector<int> sums(n, 0);
        int sum = nums[0];
        sums[0] = nums[0];
        for(int i = 1; i < n; i++){
            sums[i] = sums[i-1] + nums[i];
            sum += nums[i];
        }
        
        for(int i = 0; i < n; i++){
            int left = i > 0? sums[i-1]: 0;
            int right = sum - left - nums[i];
            if(left == right) return i;
        }
        return -1;
    }
};