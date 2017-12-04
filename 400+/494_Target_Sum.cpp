/* 494. Target Sum
 * A dp solution, final result is dp[S+sum] rather than dp[S] because
 * dp is actually representing range from -sum to sum
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto& i: nums) sum += i;
        if(S > sum || S <-sum) return 0;
        vector<int> dp(2*sum+1);
        dp[sum] = 1;
        for(int i = 0; i < nums.size(); i++){
            vector<int> newdp(2*sum+1);
            for(int j = 0; j < 2*sum+1; j++){
                if(dp[j] != 0){
                    newdp[j - nums[i]] += dp[j];
                    newdp[j + nums[i]] += dp[j];
                }
            }
            dp = newdp;
        }
        return dp[S+sum];
    }
};