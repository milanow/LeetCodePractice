/* 664. Strange Printer
 * this is a dp solution, when encountered stinrg like '**a***a', we don't know which is fast, '**aaaaa' + '***'
 * or **a + ***a
 */ 

public class Solution {
    public int StrangePrinter(string s) {
        int[,] dp = new int[100, 100];
        return helper(dp, s, 0, s.Length - 1);
    }
    
    private int helper(int[,] dp, string s, int l, int r){
        if(l > r) return 0;
        if(dp[l, r] != 0) return dp[l, r];
        while(l < r && s[r] == s[r-1]) --r;
        dp[l, r] = helper(dp, s, l, r-1) + 1;
        for(int i = l; i < r; ++i){
            if(s[i] == s[r]){
                dp[l, r] = Math.Min(dp[l, r], helper(dp, s, l, i) + helper(dp, s, i+1, r-1));
            }
        }
        return dp[l, r];
    }
}