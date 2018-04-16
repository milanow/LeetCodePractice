/* 818. Race Car
 * if n is the min step (saying n's 'A') that pass the target
 * then we have 2^(n-1) <= target < 2^n
 * we have two strategies:
 * 1. go passing the target with n's 'A' and turn back, which means we take n's 'A' + 1's 'R' = n+1 steps
 *    then we get to next recursion by passing 2^n-1 - target, because n-steps move 2^n-1
 * 2. taking n-1 steps and stop to go back a few step (not passing the target), then turn back
 * a dp could memory the results to avoid repeat calculation
 */
class Solution {
    int dp[10001];
public:
    int racecar(int target) {
        if (dp[target] > 0) return dp[target];
        int n = floor(log2(target)) + 1;
        if((1 << n) == target + 1) return dp[target] = n;
        else{
            // go pass the target then turn back
            // take n step = (1 << n) - 1, we have n's 'A' and 1's 'R';
            dp[target] = racecar((1 << n) - 1 - target) + n + 1;
            // stop if next 'A' would pass target (turn back twice)
            for(int m = 0; m < n-1; m++){
                // original code for better understanding:
                // dp[target] = min(dp[target], racecar(target - ((1 << (n-1)) - 1) + ((1 << m) - 1)) + ((n - 1) + 1) + m + 1);
                // can be optimized as:
                dp[target] = min(dp[target], racecar(target - (1 << (n-1)) + (1 << m)) + m + n + 1);
            }
        }
        return dp[target];
    }
};