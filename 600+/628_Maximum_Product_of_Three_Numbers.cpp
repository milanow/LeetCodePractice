/* 628. Maximum Product of Three Numbers
 * the possible max product can be two candidates:
 * 1. 3 max positive numbers
 * 2. 2 min negative numbers times 1 max positive number
 */

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int tmp1 = nums[n-1]*nums[n-2]*nums[n-3];
        int tmp2 = nums[0]*nums[1]*nums[n-1];
        return tmp2>tmp1?tmp2:tmp1;
    }
};