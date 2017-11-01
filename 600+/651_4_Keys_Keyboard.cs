/* 651. 4 Keys Keyboard
 * similar with 2 keys keyboard (leetcode 650), since we gain benefit from Ctrl-V needs 3 steps
 * Thus we can check from dp[i-3] to see where we can benefit most from 'Ctrl-V'
 */

public class Solution {
    public int MaxA(int N) {
        int[] dp = new int[N+1];
        if(N <= 6) return N;
        
        for(int i = 0; i <= 6; ++i){
            dp[i] = i;
        }
        
        for(int i = 7; i <= N; ++i){
            dp[i] = i;
            for(int j = i-3; j >= 3; --j){
                dp[i] = Math.Max(dp[i], dp[j]*(i-j-1));
            }
        }
        return dp[N];
    }
}