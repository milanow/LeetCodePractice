/* 486. Predict the Winner
 * a dp solution
 * sum[i][j] represents the sum of numbers from index i with length j
 * dp[i][j] represent the max value a player can get from index i with length j
 * each iteration, player takes turns to pick, such that 
 * dp[i][j] = sum[i][j] - min(dp[i][j-1], dp[i+1][j-1])
 * becasue current player has to pick from i to j-1 ot i+1 to j-1
 * note: j represent length of the array
 */
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();        
        vector<vector<int>> dp(len, vector<int>(len+1, 0));
        vector<vector<int>> sum(len, vector<int>(len+1, 0));
        for(int i = 0; i < len; i++){
            dp[i][1] = sum[i][1] = nums[i];
        }
        
        for(int j = 2; j <= len; j++){
            for(int i = 0; i + j - 1 < len; i++){
                sum[i][j] = sum[i][j-1] + nums[i+j-1];
                dp[i][j] = sum[i][j] - min(dp[i][j-1], dp[i+1][j-1]);
            }
        }
        
        return sum[0][len] - dp[0][len] <= dp[0][len];
    }
};