/* 712. Minimum ASCII Delete Sum for Two Strings
 * This is a typical DP problem, dp[i][j] represents minimum ASCII delete sum starting
 * at i, j. i and j representing index of s1 & index of s2.
 */

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = m; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                if(i < m || j < n){
                    dp[i][j] = i < m && j < n && s1[i] == s2[j]?
                        dp[i+1][j+1]: min(i < m? s1[i] + dp[i+1][j]: INT_MAX, j < n? s2[j] + dp[i][j+1]: INT_MAX);
                }
            }
        }
        return dp[0][0];
    }
};