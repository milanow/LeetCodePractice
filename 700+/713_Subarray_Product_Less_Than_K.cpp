/* 713. Subarray Product Less Than K
 * The key is to maintain a 'window' where the the products of numbers inside the window 
 * is smaller than k
 * The strategy to maintain the window is:
 * 1. multiply the current nums[i]
 * 2. checking if the window is larger than k
 * 3. dividing window's left number until the window is smaller than k
 * 4. add the number (i-l+1) representing those subarrays where start at 'l'
 */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1) return 0;
        
        int prod = 1, l = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            prod *= nums[i];
            while(prod >= k) prod /= nums[l++];
            cnt += i - l + 1;
        }
        return cnt;
    }
};