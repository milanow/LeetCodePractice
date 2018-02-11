/* 746. Min Cost Climbing Stairs
 * a typical dp problem
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        vector<int> dp(n, INT_MAX);
        if(!n) return 0;
        if(n == 1) return cost[0];
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return dp[n-1];
        
    }
};