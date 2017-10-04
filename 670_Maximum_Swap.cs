/* 670. Maximum Swap
 * use an array to store the index of largest number on the right
 */

public class Solution {
    public int MaximumSwap(int num) {
        StringBuilder numStr = new StringBuilder(num.ToString());
        int n = numStr.Length;
        int curMaxPos = n-1;
        int[] dp = new int[n];
        for(int i = n-1; i >= 0; --i){
            if(numStr[i] > numStr[curMaxPos]){
                curMaxPos = i;
            }
            dp[i] = curMaxPos;
        }
        
        for(int i = 0; i < n; ++i){
            if(numStr[dp[i]] != numStr[i]){
                char tmp = numStr[dp[i]];
                numStr[dp[i]] = numStr[i];
                numStr[i] = tmp;
                break;
            }
        }
        
        return Int32.Parse(numStr.ToString());
    }
}