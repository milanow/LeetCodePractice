/* 416. Partition Equal Subset Sum
 * Having a dp array to iterating and updating all possible numbers, who are
 * smaller than target, that can be sumed up by numbers in nums
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), tar = sum >> 1;
        if(sum & 1) return false;
        
        vector<bool> dp(tar+1, false);
        dp[0] = true;
        for(int n: nums){
            for(int i = tar; i >= n; i--){
                dp[i] = dp[i] || dp[i-n];
            }
        }
        return dp[tar];

    }
};