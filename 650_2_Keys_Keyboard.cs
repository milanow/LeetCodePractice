/* 650. 2 Keys Keyboard
 * A typical dp problem, continuely updating maxed 'A' iterating from 1 to i/2.
 * We can perform Ctrl+V multiple times where we don't need to perform Ctrl+C (bag English explanation:) )
 * eg. dp[8] can be get from dp[2] + 4 * 'Ctrl+V'
 */

public class Solution {
    public int MinSteps(int n) {
        int[] dp = new int[n+1];
        for(int i = 0; i <= 1; ++i) dp[i] = 0;
        
        for(int i = 2; i <= n; ++i){
            int limit = i / 2;
            dp[i] = i;
            for(int j = 1; j <= limit; ++j){
                if(i % j == 0){
                    dp[i] = Math.Min(dp[i], dp[j] + i / j);
                }
            }
        }
        return dp[n];
    }
}