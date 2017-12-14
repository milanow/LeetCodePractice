/* 474. Ones and Zeroes
 * A dp solution, dp[m][n] indicates max form of m 0 and n 1
 * The code is intuitive...counting numZero and numOne and checking 
 * previous dp array to seek a better/max result
 */

public class Solution {
    public int FindMaxForm(string[] strs, int m, int n) {
        int[,] dp = new int[m+1,n+1];
        
        for(int i = 0; i < strs.Length; i++){
            int numOne = 0, numZero = 0;
            
            foreach(var c in strs[i]){
                if(c == '0') numZero++;
                else numOne++;
            }
            
            for(int j = m; j >= numZero; j--){
                for(int k = n; k >= numOne; k--){
                    dp[j,k] = Math.Max(dp[j,k], dp[j-numZero,k-numOne] + 1);
                }
            }
        }
        return dp[m,n];
    }
}