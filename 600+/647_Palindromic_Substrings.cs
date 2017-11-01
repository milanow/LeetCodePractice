/* 647. Palindromic Substrings
 * Dp solution, dp[i,j] represents if a substring starts from j with length of i is palindrome
 * we can get a status transition equation by  
 * dp[i, j] = dp[i-2, j+1] ('mid' of current substring is a palindrome) && 
 *          s[j] == s[j+i-1](left letter = right letter);
 * Then use a counter to count how many palindromes in total
 */

public class Solution {
    public int CountSubstrings(string s) {
        int len = s.Length;
        if(len == 0) return 0;
        
        // first dim represents length, second dim represents start pos;
        bool[,] dp = new bool[len+1, len+1];
        for(int i = 0; i <= 1; ++i){
            for(int j = 0; j <= len - i; ++j){
                dp[i,j] = true;
            }
        }
        
        // we have at least number of 'len' palindrome
        int cnt = len;
        for(int i = 2; i <= len; ++i){
            for(int j = 0; j <= len - i; ++j){
                dp[i, j] = dp[i-2, j+1] && s[j] == s[j+i-1];
                if(dp[i, j]) ++cnt;
            }
        }
        return cnt;
    }
}