/* 656. Coin Path
 * A classic dp question, dp[k] represents the min coins need to be cost jump from k+1 to k+B,
 * pos[k] represents the next postion need to jump
 * compute from the back side to see how to reach beginning from end
 */

public class Solution {
    public IList<int> CheapestJump(int[] A, int B) {
        var ans = new List<int>();
        int len = A.Length;
        if(len == 0 || A[len-1] == -1) return ans;
        
        int[] dp = new int[len], pos = new int[len];
        for(int i = 0; i < len; ++i){
            dp[i] = Int32.MaxValue;
            pos[i] = -1;
        }
        dp[len-1] = A[len-1];
        for(int i = len - 2; i >= 0; --i){
            if(A[i] == -1) continue;
            for(int j = i+1; j <= Math.Min(B+i, len-1); ++j){
                if(dp[j] == Int32.MaxValue) continue;
                if(A[i] + dp[j] < dp[i]){
                    dp[i] = A[i] + dp[j];
                    pos[i] = j;
                }
            }
        }
        
        if(dp[0] == Int32.MaxValue) return ans;
        int k = 0;
        while(k != -1){
            ans.Add(k+1);
            k = pos[k];
        }
        return ans;
    }
}