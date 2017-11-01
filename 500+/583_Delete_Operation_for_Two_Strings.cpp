/* 583. Delete Operation for Two Strings
 * A dp solution, dp[i][j] represents minDist of word1.substr(0,i) and 
 * word2.substr(0,j)
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        for(int i = 0; i <= len1; ++i){
            dp[i][0] = i;
        }
        
        for(int j = 0; j <= len2; ++j){
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                dp[i][j] = word1[i-1] == word2[j-1]? dp[i-1][j-1]:
                    min(dp[i-1][j] + 1, dp[i][j-1] + 1);
            }
        }
        
        return dp[len1][len2];
    }
};